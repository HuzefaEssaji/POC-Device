#include "esp_camera.h"
#include "ESP32_OV5640_AF.h"
#include <WiFi.h>
#include <WebServer.h>
#include <WiFiClient.h>
//#include "sendImage.h"
#define CAMERA_MODEL_AI_THINKER

#include "camera_pins.h"

#include <Arduino.h>
#include <Arduino_JSON.h>
// #include <WiFi.h>
#include <HTTPClient.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
// #include "esp_camera.h"
// #include "ESP32_OV5640_AF.h"
#include "esp_sleep.h"


int id = 0;



RTC_DATA_ATTR boolean startFlag = false;

String serverName = "sensorlifeline.com";
String serverPath = "/uploads.php";
const char* getServerName = "http://sensorlifeline.com/get-esp.php";
String getPatientDetails = "";

const int serverPort = 80;

const int flash = 1;
const int flashInt = 6; // 0 - 2 ^ fleshRes;
const int flashRes = 8;
const int flashFreq = 500;

long tim = 0;



///////////////////////////////////////////

String sendPhoto(camera_fb_t * fb) {

  WiFiClient client;

  String getAll;
  String getBody;

  Serial.println("Connecting to server: " + serverName);

  digitalWrite(12, HIGH);
  if (client.connect(serverName.c_str(), serverPort)) {
    Serial.println("Connection successful!");
    //    String head = "--RandomNerdTutorials\r\nContent-Disposition: form-data; name=\"imageFile\"; filename=\"" + String(id) + "_" + String(count[id]) + ".jpg\"\r\nContent-Type: image/jpeg\r\n\r\n";
    String head = "--RandomNerdTutorials\r\nContent-Disposition: form-data; name=\"imageFile\"; filename=\"" + String(id) + ".jpg\"\r\nContent-Type: image/jpeg\r\n\r\n";
    //Serial.println(head);
    String tail = "\r\n--RandomNerdTutorials--\r\n";

    uint32_t imageLen = fb->len;
    uint32_t extraLen = head.length() + tail.length();
    uint32_t totalLen = imageLen + extraLen;

    client.println("POST " + serverPath + " HTTP/1.1");
    client.println("Host: " + serverName);
    client.println("Content-Length: " + String(totalLen));
    client.println("Content-Type: multipart/form-data; boundary=RandomNerdTutorials");
    client.println();
    client.print(head);

    uint8_t *fbBuf = fb->buf;
    size_t fbLen = fb->len;
    for (size_t n = 0; n < fbLen; n = n + 1024) {
      if (n + 1024 < fbLen) {
        client.write(fbBuf, 1024);
        fbBuf += 1024;
      }
      else if (fbLen % 1024 > 0) {
        size_t remainder = fbLen % 1024;
        client.write(fbBuf, remainder);
      }
    }
    client.print(tail);

    //count[id]++;

    int timoutTimer = 10000;
    long startTimer = millis();
    boolean state = false;

    while ((startTimer + timoutTimer) > millis()) {
      Serial.print(".");
      delay(100);
      while (client.available()) {
        char c = client.read();
        if (c == '\n') {
          if (getAll.length() == 0) {
            state = true;
          }
          getAll = "";
        }
        else if (c != '\r') {
          getAll += String(c);
        }
        if (state == true) {
          getBody += String(c);
        }
        startTimer = millis();
      }
      if (getBody.length() > 0) {
        break;
      }
    }
    Serial.println();
    client.stop();
    Serial.println(getBody);
  }
  else {
    getBody = "Connection to " + serverName +  " failed.";
    Serial.println(getBody);
  }
  return getBody;

}

String httpGETRequest(const char* serverName) {
  WiFiClient client1;
  HTTPClient http;

  // Your IP address with path or Domain name with URL path
  http.begin(client1, serverName);

  // Send HTTP POST request
  int httpResponseCode = http.GET();

  String payload = "{}";

  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}

void getPatientDetail()
{
  if (WiFi.status() == WL_CONNECTED) {

    getPatientDetails = httpGETRequest(getServerName);
    while (getPatientDetails.indexOf("login and try again")) {
      getPatientDetails = httpGETRequest(getServerName);

      if (getPatientDetails)
      {
        //Serial.println(getPatientDetails);
        break;
      }
      delay(200);
    }

    // Serial.println(getPatientDetails);

    JSONVar myObject = JSON.parse(getPatientDetails);

    if (JSON.typeof(myObject) == "undefined") {
      //Serial.println("Parsing input failed!");
      return;
    }

    // Serial.print("JSON object = ");
    //Serial.println(myObject);

    // myObject.keys() can be used to get an array of all the keys in the object
    JSONVar keys = myObject.keys();

    for (int i = 0; i < keys.length(); i++)
    {
      JSONVar value = myObject[keys[i]];

      if (i == 0)
      {
        String idStr = JSON.stringify(value);
        //Serial.println("length: " +String(idStr.length()));
        idStr = idStr.substring(1, idStr.length() - 1);
        id = idStr.toInt();
        //Serial.println(idStr);

      }
    }

    Serial.println("id: " + String(id));
  }
  else {
    Serial.println("WiFi Disconnected");
  }
}


///////////////////////////////////////////
// OV5640 ov5640 = OV5640();



OV5640 ov5640 = OV5640();

WebServer server(80);

const char *ssid = "realme 3 Pro";
const char *pass = "1234567890";

//const char *ssid = "Cam";
//const char *pass = "1243567890";

const char HEADER[] = "HTTP/1.1 200 OK\r\n"
                      "Access-Control-Allow-Origin: *\r\n"
                      "Content-Type: multipart/x-mixed-replace; boundary=1234567890\r\n";
const char BOUNDARY[] = "\r\n--1234567890\r\n";
const char CTNTTYPE[] = "Content-Type: image/jpeg\r\nContent-Length: ";
const int hdrLen = strlen(HEADER);
const int bdrLen = strlen(BOUNDARY);
const int cntLen = strlen(CTNTTYPE);



void handle_jpg_stream(void)
{
  char buf[32];
  int s;

  WiFiClient client = server.client();

  client.write(HEADER, hdrLen);
  client.write(BOUNDARY, bdrLen);

  long tim = millis();

  camera_fb_t * fb = NULL;

  while (true)
  {
    tim = millis();

    if (!client.connected())
      break;


    fb = esp_camera_fb_get();

    if (!digitalRead(13))
    {
      if (!digitalRead(13)) {
        getPatientDetail();
        sendPhoto(fb);

        ledcWrite(flash, 0);
        //  digitalWrite(4, LOW);
        digitalWrite(12, LOW);

        gpio_hold_en(GPIO_NUM_4);
        gpio_deep_sleep_hold_en();

        WiFi.disconnect();
        esp_deep_sleep_start();

        break;
      }
    }

    s = fb->len;
    client.write(CTNTTYPE, cntLen);
    sprintf(buf, "%d\r\n\r\n", s);
    client.write(buf, strlen(buf));
    client.write((char *)fb->buf, s);
    client.write(BOUNDARY, bdrLen);
    Serial.println(millis() - tim);
    esp_camera_fb_return(fb);

  }
}

// const char JHEADER[] = "HTTP/1.1 200 OK\r\n";
//                        "Content-disposition: inline; filename=capture.jpg\r\n";
//                        "Content-type: image/jpeg\r\n\r\n";
// const int jhdLen = strlen(JHEADER);
//
// void handle_jpg(void)
//{
//   WiFiClient client = server.client();
//
//   if (!client.connected()) return;
//   cam.run();
//   client.write(JHEADER, jhdLen);
//   client.write((char *)cam.getfb(), cam.getSize());
// }

void handleNotFound()
{
  String message = "Server is running!\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  server.send(200, "text / plain", message);
}

void configCam()
{
  Serial.println("configing cam");
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_VGA;
  config.jpeg_quality = 10;
  config.fb_count = 2;

  // init with high specs to pre-allocate larger buffers
  if (psramFound()) {
    config.frame_size = FRAMESIZE_SXGA;
    config.jpeg_quality = 4;  //0-63 lower number means higher quality
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_XGA;
    config.jpeg_quality = 4;  //0-63 lower number means higher quality
    config.fb_count = 2;
  }

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK)
  {
    Serial.printf("Camera init failed with error 0x%x", err);
    delay(100);
    ESP.restart();
  }

  sensor_t* sensor = esp_camera_sensor_get();
  ov5640.start(sensor);

  if (ov5640.focusInit() == 0) {
    Serial.println("OV5640_Focus_Init Successful!");
  }

  if (ov5640.autoFocusMode() == 0) {
    Serial.println("OV5640_Auto_Focus Successful!");
  }
  Serial.println("configed cam");
}

IPAddress ip;

void startAP()
{
  Serial.println("Starting AP/ WiFi");

  IPAddress ip;
  //  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  //Serial.println("Connecting");
  long tim ;
  tim = millis();
  while (WiFi.status() != WL_CONNECTED)
  {
    //    delay(50);
    //    digitalWrite(12, HIGH);
    //    delay(50);
    //    digitalWrite(12, LOW);
    Serial.print(".");
    if (millis() - tim > 6000)
      ESP.restart();
  }
  ip = WiFi.localIP();

  //  Serial.println(F("WiFi connected"));
  //  Serial.println("");
  //  Serial.println(ip);
  Serial.println();
  Serial.print("Stream Link: http://");
  Serial.print(ip);
  Serial.println("/mjpeg/1");
  server.on("/mjpeg/1", HTTP_GET, handle_jpg_stream);
  //  server.on("/jpg", HTTP_GET, handle_jpg);
  server.onNotFound(handleNotFound);
  server.begin();

  //  WiFi.softAP(ssid, pass);
  //  ip = WiFi.softAPIP();
  //
  //  //  Serial.println(F("WiFi connected"));
  //  //  Serial.println("");
  //  //  Serial.println(ip);
  //  Serial.print("Stream Link: http://");
  //  Serial.print(ip);
  //  Serial.println("/mjpeg/1");
  //  server.on("/mjpeg/1", HTTP_GET, handle_jpg_stream);
  //  //  server.on("/jpg", HTTP_GET, handle_jpg);
  //  server.onNotFound(handleNotFound);
  //  server.begin();
  //
}

//void startServer()
//{
//  /////////////////////////////////////////////////////////Server
//  server.on("/mjpeg/1", HTTP_GET, handle_jpg_stream);
//  //  server.on("/jpg", HTTP_GET, handle_jpg);
//  server.onNotFound(handleNotFound);
//  server.begin();
//  Serial.print("Stream Link: http://");
//  Serial.print(ip);
//  Serial.println("/mjpeg/1");
//}

void setup()
{

  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);


  Serial.begin(115200);

  pinMode(4, OUTPUT);

  ledcSetup(flash, flashFreq, flashRes);
  ledcAttachPin(4, flash);
  //  digitalWrite(4, LOW);

  gpio_hold_dis(GPIO_NUM_4);
  gpio_deep_sleep_hold_dis();

  pinMode(13, INPUT_PULLUP);
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_13, 0);


  if (startFlag == false)
  {
    //    digitalWrite(4, LOW);
    ledcWrite(flash, 0);
    digitalWrite(12, LOW);

    gpio_hold_en(GPIO_NUM_4);
    gpio_deep_sleep_hold_en();
    Serial.println("Press Button");
    while (!digitalRead(13));
    startFlag = true;
    esp_deep_sleep_start();
  }


  configCam();
  Serial.println("cam config time: " + String((long)(millis() - tim) / 1000));

  startAP();
  //  getPatientDetail();
  //  startServer();
}

void loop()
{
  server.handleClient();
}
