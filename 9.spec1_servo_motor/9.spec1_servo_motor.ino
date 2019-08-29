#include <Servo.h>
Servo myServo;
int angle = 0;

void setup() {
  Serial.begin(9600);
  myServo.attach(3);
}

void loop() {
  // move from 0 to 180 degrees
  static unsigned long tick = millis ();
  static unsigned long waktu=millis ();
  double x;
  

  //Serial.println(tick);
  for(int i = 0; i < 10; i++) {
    for(angle = 0; angle < 180; angle++){
    
      myServo.write(angle);
      delay(20);
   }
    
    //move in reverse direction, from 180 to 0 degrees
    for(angle = 180; angle > 0; angle--)
    {
      myServo.write(angle);
      delay(20);
    }
    waktu = millis() - tick;
    }
    Serial.print("waktu");
    Serial.println(waktu);

    //measurement 
    x = ((600)/(double)waktu)*10000;
    Serial.println("Rotation in each 60 sec ");
    Serial.println(x);
}
