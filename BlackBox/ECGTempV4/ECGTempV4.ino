#include <Arduino_JSON.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>

//////////////////////////////////////////////////////////////////////////////////   TFT Display
#include <TFT_eSPI.h>
#include <SPI.h>

#define BLACK       0x0000      /*   0,   0,   0 */
#define NAVY        0x000F      /*   0,   0, 128 */
#define DARKGREEN   0x03E0      /*   0, 128,   0 */
#define DARKCYAN    0x03EF      /*   0, 128, 128 */
#define MAROON      0x7800      /* 128,   0,   0 */
#define PURPLE      0x780F      /* 128,   0, 128 */
#define OLIVE       0x7BE0      /* 128, 128,   0 */
#define LIGHTGREY   0xD69A      /* 211, 211, 211 */
#define DARKGREY    0x7BEF      /* 128, 128, 128 */
#define BLUE        0x001F      /*   0,   0, 255 */
#define GREEN       0x07E0      /*   0, 255,   0 */
#define CYAN        0x07FF      /*   0, 255, 255 */
#define RED         0xF800      /* 255,   0,   0 */
#define MAGENTA     0xF81F      /* 255,   0, 255 */
#define YELLOW      0xFFE0      /* 255, 255,   0 */
#define WHITE       0xFFFF      /* 255, 255, 255 */
#define ORANGE      0xFDA0      /* 255, 180,   0 */
#define GREENYELLOW 0xB7E0      /* 180, 255,   0 */
#define PINK        0xFE19      /* 255, 192, 203 */ //Lighter pink, was 0xFC9F      
#define BROWN       0x9A60      /* 150,  75,   0 */
#define GOLD        0xFEA0      /* 255, 215,   0 */
#define SILVER      0xC618      /* 192, 192, 192 */
#define SKYBLUE     0x867D      /* 135, 206, 235 */
#define VIOLET      0x915C      /* 180,  46, 226 */

TFT_eSPI tft = TFT_eSPI();  // Invoke library
///////////////////////////////////////////////////////////////////////////////////   Tempreature
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//////////////////////////////////////////////////////////////////////////////////    Buttons
#define ECGButton 25
#define TempButton 33
#define CamButton 32
#define Return 16
boolean ButtonFlag = false;
int ButtonSelected = 0;

#define ECGSensor 34 //Sensor Pin
//#define camPin
//#define camAck  1

//////////////////////////////////////////////////////////////////////////////////   wifi setup
const char* ssid     = "realme 3 Pro";
const char* password = "1234567890";
String apiKeyValue = "tPmAT5Ab3j7F9";
String id = "0";          // person id
const char* serverName = "http://remote-ecg.000webhostapp.com/post-esp.php";
const char* getServerName = "http://remote-ecg.000webhostapp.com/get-esp.php";
String getPatientDetails = "";

////////////////////////////////////////////////////////////////////////////////// for ECG
int sensorVal = 170;
int sensorValOld = 170;
int loopCounter = 0;
int CenterGraphColor = GREEN;
int GridColor = DARKGREY;

///////////////////////////////////////////////////////////////////////////////////
long tim;
String ECGString = "";
int temp;
String camera;

//////////////////////////////////////////////////////////////////////////////////

void IRAM_ATTR Idel()  // used for returning to home after Return button pressed
{
  ButtonSelected = 0;
  ButtonFlag = true;
}

void IRAM_ATTR ECGFlag()   // used for returning to ECG function after ECG button pressed
{
  ButtonSelected = 1;
  ButtonFlag = true;
}

void IRAM_ATTR TempFlag()  // used for returning to Temp function after Temp button pressed
{
  ButtonSelected = 2;
  ButtonFlag = true;
}

void IRAM_ATTR CamFlag()   // used for returning to Camera function after Camera button pressed
{
  ButtonSelected = 3;
  ButtonFlag = true;
}

void connectWiFi()
{
  WiFi.begin(ssid, password);
  //Serial.println("Connecting");
  tim = millis();
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(10);
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

void postData(int type,  String string)
{
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    http.begin(client, serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String httpRequestData = "api_key=" + apiKeyValue + "&id=" + id + "&type=" + type +  "&value1=" + string + "";
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);

    int httpResponseCode;
    httpResponseCode = http.POST(httpRequestData);

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      for (int i = 2; i > 0; i++)
      {
        httpResponseCode = http.POST(httpRequestData);
        if (httpResponseCode == 200)
          break;
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      Serial.println("error while uploading");
    }

    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
    connectWiFi();
  }
}

void appendData(String * string, int dta)
{
  *string += String(dta);
  *string += ",";
}

void getTemp()
{
  while (!ButtonFlag)
  {
    if (ButtonFlag == true)
      return;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    float temp = 0;
    float dataCounter = 0;
    while ( dataCounter <= 500)
    {
      dataCounter++;
      temp =  temp + mlx.readObjectTempF();
      Serial.println(mlx.readObjectTempF());
      delay(10);
    }
    temp = temp / dataCounter;

    Serial.println("Tempreature is: " + String(temp));
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    if (temp < 94)
    {
      tft.setTextColor(GREEN);
      tft.setCursor(95, 140);
      tft.println(temp);
      tft.setCursor(80, 160);
      tft.println("Standby");
      delay(1000);

    }
    else if (temp > 94 && temp < 100) {
      tft.setTextColor(YELLOW);
      tft.setCursor(95, 140);
      tft.println(temp);
      tft.setCursor(80, 160);
      tft.println("NORMAL");
      delay(250);

    }
    else if (temp > 100) {
      tft.setTextColor(BLUE);
      tft.setCursor(95, 140);
      tft.println(temp);
      tft.setCursor(80, 160);
      tft.println("FEVER !");
      delay(250);

    }

    //    tft.fillScreen(BLACK);
    //    tft.setTextColor(GREEN, BLACK); //font colour / bg colour
    //    tft.drawString("Disp Temp", 60, 160, 4);

    postData(1, String(temp));
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (ButtonSelected == 2)
      ButtonSelected = 0;
    break;
    delay(125);
  }
}

void getECG()
{
  //  tft.fillScreen(BLACK);
  //  tft.setRotation(3);
  //  tft.fillRect(0, 0, 10, 240, BLACK );
  //  long Time = 0;
  //  double gridTime = 10;
  //  boolean gridFlag = LOW;
  //  float dividend = 100;  // for grid
  //  int base = 210;
  //  int gridbase = base - 50;
  //  int gridheight = 220;
  //  float BPM = 0;
  //
  //  boolean periodFlag = LOW;
  //  long periodInTime = 0;
  //  long periodTime = 0;
  //  double periodCounter = 0;
  //  float period = 1;
  //  int val1 = 2400;
  //  int val2 = 2200;
  //  int inLoopCounter = 0;
  //  boolean onceFlag = LOW;
  //  long privWhile = 0;

  while (!ButtonFlag)
  {
    //long toteltimeforfunction = millis();

    if (ButtonFlag)
      break;

    //
    //    ///////////////////////////////////////////////////////////////////////////////////////////////Reading Values
    //    sensorValOld = sensorVal;
    //    sensorVal = analogRead(ECGSensor);
    //    Serial.println(sensorVal);
    //
    //    /////////////////////////////////////////////////////////////////////////////////////////////////Period calculations
    //    if ( sensorVal >= val1 && periodFlag == LOW)
    //    {
    //      periodFlag = HIGH;
    //      int tim = millis();
    //
    //      if (!periodInTime)
    //      {
    //        periodInTime = tim;
    //        periodTime = periodInTime;
    //      }
    //      else
    //      {
    //        periodTime = tim;
    //      }
    //    }
    //
    //    else if (sensorVal < val2 && periodFlag == HIGH)
    //    {
    //      periodFlag = LOW;
    //      periodCounter ++;
    //      period = (periodTime - periodInTime) / (1000 * periodCounter);
    //      //Serial.println("Period is: " + String(period));
    //    }
    //
    //    ///////////////////////////////////////////////////////////////////////////////////////////////GridCalculations  Needed to be done only once
    //
    //    if (gridFlag == LOW)
    //    {
    //      loopCounter = 0;
    //      inLoopCounter = loopCounter;
    //      Time = millis();
    //      gridFlag = HIGH;
    //    }
    //    else if (gridFlag == HIGH && inLoopCounter == loopCounter  )
    //    {
    //      gridTime = (millis() - Time) / dividend;
    //      //Serial.println("Gridtime: " + String(Time));
    //      Time = 0;
    //      gridFlag = LOW;
    //    }
    //    ///////////////////////////////////////////////////////////////////////////////////////////////Drawing Graph
    //
    //    sensorVal = map(sensorVal, 0, 4096, tft.height() - gridbase, gridheight); // mapping value
    //    //Serial.println(sensorVal);
    //
    //    tft.setRotation(7);
    //    if (loopCounter == tft.width()  )
    //    {
    //      tft.fillRect(0, 0, 2, gridbase, BLACK );
    //      loopCounter = 0;
    //    }
    //    else
    //    {
    //      loopCounter = loopCounter + 1;
    //    }
    //
    //    tft.fillRect(loopCounter + 2, 0, 2, gridbase, BLACK );
    //    tft.setRotation(3);
    //    tft.drawLine(loopCounter, sensorValOld, loopCounter + 1, sensorVal, CenterGraphColor);
    //
    //    ///////////////////////////////////////////////////////////////////////////////////////////////Drwing Grid
    //    tft.setRotation(7);
    //    for (float i = 0; i <= tft.width(); i = i + (float)(tft.width() / gridTime))
    //    {
    //      tft.drawFastVLine(i, 0, gridbase, GridColor);
    //    }
    //
    //    for (float i = 0; i <= gridbase; i = i + (float)(tft.width() / gridTime))
    //    {
    //      tft.drawFastHLine(0, i, tft.width(), GridColor);
    //    }
    //    /////////////////////////////////////////////////////////////////////////////////////////////writes graph properties  needed to be done only once
    //    if (onceFlag == LOW)
    //    {
    //      tft.drawFastHLine(0, gridbase, tft.width(), GridColor);
    //      tft.setTextColor(WHITE);
    //      tft.setRotation(7);
    //      tft.setTextSize(1);
    //      tft.setCursor(240, base - 30);
    //      tft.println(" " + String(((float)dividend) / 1000) + " Second");
    //      tft.setCursor(240, base - 20);
    //      tft.println("per division");
    //      tft.setCursor(40, base);
    //      tft.setTextSize(2);
    //      //tft.println("Period:     Seconds");
    //      tft.println("Heart Rate:        BPM");
    //      onceFlag = HIGH;
    //    }
    //
    //    /////////////////////////////////////////////////////////////////////////////////////////////writing BPS can be done once in the while
    //    if (millis() - privWhile >= 1000)
    //    {
    //      tft.setRotation(7);
    //      tft.fillRect(170, base - 10, 70, 30, BLACK);
    //      tft.setTextSize(2);
    //      tft.setCursor(180, base);
    //      BPM = 60 / period;
    //      tft.println(BPM);
    //      tft.setRotation(3);
    //      privWhile = millis();
    //    }
    //    //////////////////////////////////////////////////////////////////////////////////////////Delay : streaches graph. inversely proportional
    //    delayMicroseconds(6000);  // 7  Add Slider here
    //    //Serial.println(millis() - toteltimeforfunction);

    long oldReadingTime = millis();
    long delayTime = 10;

    int dataCounter = 0;
    while ( dataCounter <= 2000)
    {
      int ecgdata = analogRead(ECGSensor);
      appendData(&ECGString, ecgdata);
      dataCounter ++;
      Serial.println(dataCounter / 100.0);
      while (millis() - oldReadingTime <= delayTime);
      oldReadingTime = millis();
    }
    postData(0, ECGString);
    if (ButtonSelected == 1)
      ButtonSelected = 0;
    break;
  }

  tft.setRotation(6);
}

void getCam()
{
  while (!ButtonFlag)
  {
    if (ButtonFlag == true)
      return;
    //////////////////////////////////////////////////////////////////////////////////////////////
    Serial.println("in Camera");
    tft.fillScreen(BLACK);
    tft.setTextColor(GREEN, BLACK); //font colour / bg colour
    tft.drawString("Disp cam", 60, 160, 2);

    //digitalWrite(camPin, HIGH);
    //while(!digitalRead(camAck))
    // digitalWrite(camPin, LOW);

    //    Serial.write(id);
    //
    //    while (1)
    //    {
    //      String ack = "";
    //      while (Serial.available())
    //      {
    //        ack = Serial.read();
    //      }
    //      if (ack == "Done")
    //        break;
    //    }



    //////////////////////////////////////////////////////////////////////////////////////////////
    if (ButtonSelected == 3)
      ButtonSelected = 0;
    break;
    delay(500);
  }
}

void idel()
{
  while (!ButtonFlag)
  {
    if (ButtonFlag == true)
      return;
    Serial.println("Ready State");

    //esp_light_sleep_start();

    delay(500);
  }
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
        id = value;
        Serial.println(id);
      }
    }

    Serial.println("id: " + String(id));
  }
  else {
    Serial.println("WiFi Disconnected");
  }
}

void setup()
{
  pinMode(ECGButton, INPUT_PULLUP);
  pinMode(TempButton, INPUT_PULLUP);
  pinMode(CamButton, INPUT_PULLUP);
  pinMode(Return, INPUT_PULLUP);
  //  pinMode(camPin, OUTPUT);
  pinMode(ECGSensor, INPUT);

  attachInterrupt(ECGButton, ECGFlag, FALLING);
  attachInterrupt(TempButton, TempFlag, FALLING);
  attachInterrupt(CamButton, CamFlag, FALLING);
  attachInterrupt(Return, Idel, FALLING);

  //esp_sleep_enable_ext0_wakeup(GPIO_NUM_25, 0);
  //esp_sleep_enable_ext0_wakeup(GPIO_NUM_32, 0);
  //esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, 0);

  tft.init();
  tft.setRotation(6);
  tft.setTextSize(2);

  mlx.begin();

  Serial.begin(115200);
  ///////////////////////////////////////////////////////////////////////////
  connectWiFi();
  getPatientDetail();
  ////////////////////////////////////////////////////////////////////////////


}


void loop()
{
  if (ButtonFlag == true)
    ButtonFlag = false;


  switch (ButtonSelected)
  {
    case 0:
      idel();
      break;
    case 1:
      getECG();
      break;
    case 2:
      getTemp();
      break;
    case 3:
      getCam();
      break;
    default:
      break;
  }
}
