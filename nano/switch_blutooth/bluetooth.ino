
#include <SoftwareSerial.h>
#define button 5

SoftwareSerial app(10, 11); // RX, TX

void setup() {

  Serial.begin(9600);
  pinMode(button, INPUT);
  app.begin(9600);
  app.write(10000);
}
unsigned int buttonstate = LOW;
unsigned int count = 1000;
void loop() { 
  
  buttonstate = digitalRead(button);
  
  Serial.println(buttonstate);
  delay(500);
  if (buttonstate == HIGH)
  {
    Serial.println(count);
    app.println(count);
    count++;
  }
  
  if (Serial.available()) {
    app.write(Serial.read());
  }
  if (app.available()) {
    Serial.write(app.read());
  }
}
