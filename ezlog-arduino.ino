#include <SoftwareSerial.h>
SoftwareSerial RFID(2, 3); // RX and TX
SoftwareSerial BT(10, 11); // RX and TX

int i;
String tag = "";

void setup()
{
  Serial.begin(9600);  // start serial to PC
  
  RFID.begin(9600);    // start serial to RFID reader
  BT.begin(9600);

  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);

  RFID.listen();

}

void loop()
{
  if (RFID.available() > 0)
  {
    i = RFID.read();
    Serial.print(i, DEC);
    Serial.print(" ");
    tag += i;
//    tag += " ";
    if (i == 3) {
      Serial.println();
      Serial.println(tag);

      BT.listen();
      BT.println(tag);
      
      tag = "";

      RFID.listen();
    }
  }
}
