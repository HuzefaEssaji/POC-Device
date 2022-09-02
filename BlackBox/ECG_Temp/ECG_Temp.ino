///////////////////////////////////////////////////////////////////////////////////   TFT Display
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

//////////////////////////////////////////////////////////////////////////////////
#define ECGButton 25
#define TempButton 33
#define CamButton 32
#define Return 35

boolean Flag = false;


void setup() {
  pinMode(ECGButton, INPUT_PULLUP);
  pinMode(TempButton, INPUT_PULLUP);
  pinMode(CamButton, INPUT_PULLUP);
  pinMode(Return, INPUT_PULLUP);

  attachInterrupt(Return, upFlag, FALLING);

  tft.init();
  tft.setRotation(6);
}

void upFlag()  // used for returning to home after Return button pressed
{
  Flag = true;
}

int chkBtn()  // checks button to select mode { ECG, Tempreature, etc}
{
  if (!digitalRead(ECGButton))
    return 1;
  else if (!digitalRead(TempButton))
    return 2;
  else if (!digitalRead(CamButton))
    return 3;
  else
    return 0;
}

void getTemp()
{
  while (1)
  {
    double temp = mlx.readObjectTempF();
    if (temp < 94) 
    {
      tft.setTextColor(GREEN);
      tft.println(temp);
      tft.setCursor(80, 115);
      tft.println("Standby");
      delay(500);
    }
    else if (temp > 94 && temp < 100) 
    {
      tft.setTextColor(YELLOW);
      tft.println(temp);

      tft.setCursor(80, 115);
      tft.println("NORMAL");
      delay(500);
    }
    else if (temp > 100) 
    {
      tft.setTextColor(BLUE);
      tft.println(temp);
      tft.setCursor(80, 115);
      tft.println("FEVER !");
      delay(500);
    }

    //    tft.fillScreen(BLACK);
    //    tft.setTextColor(GREEN, BLACK); //font colour / bg colour
    //    tft.drawString("Disp Temp", 60, 160, 4);
    if (Flag == true)
      return;
  }
}

void getECG()
{
  while (1)
  {
    tft.fillScreen(BLACK);
    tft.setTextColor(GREEN, BLACK); //font colour / bg colour
    tft.drawString("Disp ECG", 60, 160, 4);
    if (Flag == true)
      return;
    delay(500);
  }
}

void getCam()
{
  while (1)
  {
    tft.fillScreen(BLACK);
    tft.setTextColor(GREEN, BLACK); //font colour / bg colour
    tft.drawString("Disp cam", 60, 160, 4);
    if (Flag == true)
      return;
    delay(500);
  }
}


void loop()
{
  if (Flag == true)
    Flag = false;

  tft.fillScreen(BLACK);
  tft.setTextColor(GREEN, BLACK); //font colour / bg colour
  tft.drawString("Home", 60, 160, 4);

  switch (chkBtn())
  {
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
