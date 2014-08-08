#include <Wire.h>

void setup()
{
  Wire.begin(0x90);                // join i2c bus with address #2
  Wire.onReceive(receiveEvent);
  Serial.begin(115200);
  while(!Serial);
  Serial.println("Yun up...");
}

void loop()
{
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while (Wire.available()) {
  int a = Wire.read(); // respond with message of 6 bytes
  Serial.println(a,HEX);                     // as expected by master
  }
}
