#include <HardwareSerial.h>
#include "BluetoothSerial.h"

HardwareSerial SerialPort (2); // use UART2

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(9600);
  SerialBT.begin("ESP32test"); //Bluetooth device name 
  Serial.println("The device started, now you can pair it");
  SerialPort.begin(9600, SERIAL_8N1, 16, 17);
}
void loop()
{
  if (SerialPort.available())
  {
    uint32_t number = SerialPort.read();
    SerialBT.write (number);
    Serial.println(number);
  }
}
