#include <SoftwareSerial.h>

SoftwareSerial reciever(5, 4); //rx,tx  

void  shifter(uint8_t msb_sample,uint8_t mid_sample,uint8_t lsb_sample);

int i = 0;

uint8_t val[18];
void setup()

{
  Serial.begin(9600);
  reciever.begin(9600);

}
void loop()
{

  if (reciever.available())
  {
    val[i] = reciever.read();
    i++;
  }

  if (i >= 18)
  {
    i = 0;
    for (int j = 0; j < 18; j =j+1)
    {
//      Serial.println(val[j],HEX);
        shifter(~val[j],~val[j+1],~val[j+2]);
    }

//    Serial.println("");


  }


}

void shifter(uint8_t msb_sample,uint8_t mid_sample,uint8_t lsb_sample)
{

  uint32_t temp = 0;
  msb_sample =  0x0000000F & (uint32_t)msb_sample ;
  msb_sample = msb_sample << 16;
  temp = temp | msb_sample;
  mid_sample = (uint32_t)mid_sample<< 8;
  temp = temp | mid_sample;
  temp = temp | (uint32_t)lsb_sample;

  Serial.println(temp+1,HEX) ;
}
