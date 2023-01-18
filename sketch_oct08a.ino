#define RXD2 16
#define TXD2 17
void  shifter(uint8_t msb_sample,uint8_t mid_sample,uint8_t lsb_sample);

int i = 0;

uint8_t val[18];
void setup()

{
  Serial.begin(9600);
  Serial2.begin(9600,SERIAL_8N1,RXD2,TXD2);

}
void loop()
{

  if (Serial2.available())
  {
    val[i] = Serial2.read();
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
  uint8_t X = msb_sample>>7;
  if(X==1)
  {
     msb_sample =  0xFFFF & (uint32_t)msb_sample ;
  }
  else
  {
      msb_sample =  0x0000000F & (uint32_t)msb_sample ;
  }
  
  msb_sample = msb_sample << 16;
  temp = temp | msb_sample;
  mid_sample = (uint32_t)mid_sample;
  mid_sample = mid_sample<< 8;
  temp = temp | mid_sample;
  temp = temp | (uint32_t)lsb_sample;

  Serial.println(temp+1,HEX) ;
}
