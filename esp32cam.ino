#include <Arduino.h>
#include <Arduino_JSON.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "esp_camera.h"
#include "esp_sleep.h"

const char* ssid = "realme 3 Pro";
const char* password = "1234567890";
int id = 0;
//RTC_DATA_ATTR boolean justStarted = true;
//RTC_DATA_ATTR unsigned int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
String serverName = "sensorlifeline.com";
String serverPath = "/uploads.php";
const char* getServerName = "http://sensorlifeline.com/get-esp.php";
String getPatientDetails = "";

const int serverPort = 80;

WiFiClient client;

// CAMERA_MODEL_AI_THINKER
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22
////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
void connectWiFi()
{
  WiFi.begin(ssid, password);
  //Serial.println("Connecting");
  long tim ;
  tim = millis();
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(50);
    digitalWrite(12, HIGH);
    delay(50);
    digitalWrite(12, LOW);
    Serial.print(".");
    if (millis() - tim > 3000)
      ESP.restart();
  }

  Serial.println("");
  Serial.print("Connected to WiFi network in " + String(((millis() - tim) / 1000.0)) + " seconds with IP Address: ");
  Serial.println(WiFi.localIP());

  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    http.begin(client, serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  }
  else {
    Serial.println("WiFi Disconnected");
  }
}

void configCam()
{
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

  // init with high specs to pre-allocate larger buffers
  if (psramFound()) {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 2;  //0-63 lower number means higher quality
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_CIF;
    config.jpeg_quality = 2;  //0-63 lower number means higher quality
    config.fb_count = 1;
  }

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    delay(1000);
    ESP.restart();
  }

}

String sendPhoto() {


  String getAll;
  String getBody;

  camera_fb_t * fb = NULL;
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(12, HIGH);
    delay(500);
    digitalWrite(12, LOW);
    delay(500);
  }

  digitalWrite(4, HIGH);
  //delay(250);
  fb = esp_camera_fb_get();
  digitalWrite(4, LOW);

  if (!fb) {
    Serial.println("Camera capture failed");
    delay(1000);
    ESP.restart();
  }

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

    esp_camera_fb_return(fb);
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
  WiFiClient client;
  HTTPClient http;

  // Your IP address with path or Domain name with URL path
  http.begin(client, serverName);

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
        idStr = idStr.substring(1,idStr.length()-1);
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

void setup() {
  
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);

  gpio_hold_dis(GPIO_NUM_4);
  gpio_deep_sleep_hold_dis();
  Serial.begin(115200);

  pinMode(4, OUTPUT);
  pinMode(13, INPUT_PULLUP);
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_13, 0);

    connectWiFi();
    configCam();
    getPatientDetail();
    sendPhoto();
}

void loop() {
  digitalWrite(4, LOW);
  digitalWrite(12, LOW);

  gpio_hold_en(GPIO_NUM_4);
  gpio_deep_sleep_hold_en();

  WiFi.disconnect();
  esp_deep_sleep_start();
}
