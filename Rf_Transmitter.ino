//Prateek
//www.prateeks.in

#include <VirtualWire.h>

char *data;
int SensorPin = 4;

void setup()
{
  vw_set_tx_pin(12);
  vw_setup(2000);
  Serial.begin(9600);

  pinMode(SensorPin, INPUT);

}

void loop()
{

  int SensorValue = digitalRead(SensorPin);
  Serial.print("SensorPin Value: ");
  Serial.println(SensorValue);



  if (SensorValue == LOW) {
    data = "f";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(500);
    Serial.println("Where Hemalat");
    //https://www.youtube.com/c/JustDoElectronics/videos

  }
  else
  {
    data = "b";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(500);
    Serial.println("you not where hemalat");
  }


}
