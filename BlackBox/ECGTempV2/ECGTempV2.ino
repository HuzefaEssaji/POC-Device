//////////////////////////////////////////////////////////////////////////////////   TFT Display
#include <TFT_eSPI.h>
#include <SPI.h>

#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
TFT_eSPI tft = TFT_eSPI();  // Invoke library
///////////////////////////////////////////////////////////////////////////////////   Tempreature
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//////////////////////////////////////////////////////////////////////////////////    Buttons
#define ECGButton 25
#define TempButton 32
#define CamButton 33
#define Return 16
boolean ButtonFlag = false;
int ButtonSelected = 0;

////////////////////////////////////////////////////////////////////////////////// for ECG
int sensor2Val = 0;
int sensor2ValOld = 0;
const int BASEVAL = 1800;
int TopDirection = 1;  // 0=right, 1=left
int CenterDirection = 0;
int BottomDirection = 0;
int loopCounter = 0;
int TopGraphColor = RED;
int CenterGraphColor = GREEN;
int BottomGraphColor = YELLOW;
#define ECGSensor 35

///////////////////////////////////////////////////////////////////////////////////
long tim;

//////////////////////////////////////////////////////////////////////////////////

void IRAM_ATTR HomeFlag()  // used for returning to home after Return button pressed
{
  ButtonSelected = 0;
  ButtonFlag = true;
}

void IRAM_ATTR TempFlag()  // used for returning to home after Return button pressed
{
  ButtonSelected = 2;
  ButtonFlag = true;
}

void IRAM_ATTR CamFlag()  // used for returning to home after Return button pressed
{
  ButtonSelected = 3;
  ButtonFlag = true;
}

void IRAM_ATTR ECGFlag()  // used for returning to home after Return button pressed
{
  ButtonSelected = 1;
  ButtonFlag = true;
}

void setup()
{
  pinMode(ECGButton, INPUT_PULLUP);
  pinMode(TempButton, INPUT_PULLUP);
  pinMode(CamButton, INPUT_PULLUP);
  pinMode(Return, INPUT_PULLUP);

  attachInterrupt(ECGButton, ECGFlag, FALLING);
  attachInterrupt(TempButton, TempFlag, FALLING);
  attachInterrupt(CamButton, CamFlag, FALLING);
  attachInterrupt(Return, HomeFlag, FALLING);

  tft.init();
  tft.setRotation(6);
  tft.setTextSize(2);

  mlx.begin();

  Serial.begin(115200);
}

void getTemp()
{
  while (!ButtonFlag)
  {
    double temp = mlx.readObjectTempF();
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
      delay(250);

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
    if (ButtonFlag == true)
      return;
    delay(125);
  }
}

void getECG()
{
  tft.fillScreen(BLACK);
  tft.setRotation(3);
  int minVal = 1000;
  
  tim = millis();

  while (millis() - tim <= 2000)
  {
    tft.setRotation(7);
    tft.drawString("Analyzing", 60, 160, 2);
    if (analogRead(ECGSensor) < minVal)
      minVal = analogRead(ECGSensor);
     Serial.println(analogRead(ECGSensor));

  }

  
  tft.fillScreen(BLACK);
  minVal += 5;

  while (!ButtonFlag)
  {
    Serial.println(analogRead(ECGSensor));
    if (ButtonFlag)
      break;
    sensor2Val = analogRead(ECGSensor); // read sensor data

    //Serial.println(sensor2Val);

    int audioVal = sensor2Val; // raw

    if (audioVal > BASEVAL)
      audioVal = 2 * BASEVAL - audioVal;

    int sensor2Transposed = (sensor2Val - tft.height()) / 18 ;

    //draw center graph
    if (CenterDirection == 0)
      tft.drawLine(loopCounter, sensor2ValOld, loopCounter + 1, sensor2Transposed, CenterGraphColor);
    else
      tft.drawLine(tft.width() - loopCounter + 1, sensor2ValOld, tft.width() - loopCounter, sensor2Transposed, CenterGraphColor);



    sensor2ValOld = sensor2Transposed;

    if (loopCounter == tft.width()  )
    {
      loopCounter = 0;
      tft.fillScreen(BLACK);
    }
    else
    {
      loopCounter = loopCounter + 1;
    }
    delay(7);  // 7
  }
}

void getCam()
{
  while (!ButtonFlag)
  {
    tft.fillScreen(BLACK);
    tft.setTextColor(GREEN, BLACK); //font colour / bg colour
    tft.drawString("Disp cam", 60, 160, 2);
    if (ButtonFlag == true)
      return;
    delay(500);
  }
}

void gotoHome()
{
  while (!ButtonFlag)
  {
    tft.fillScreen(BLACK);
    tft.setTextColor(GREEN, BLACK); //font colour / bg colour
    tft.drawString("Home", 60, 160, 2);
    if (ButtonFlag == true)
      return;
    delay(500);
  }
}

void loop()
{
  if (ButtonFlag == true)
    ButtonFlag = false;


  switch (ButtonSelected)
  {
    case 0:
      gotoHome();
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
