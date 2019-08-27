#define BUZZER 6
#define SIGNAL_PIN A0

int distance = 0;
void setup(){
    Serial.begin(9600);

    pinMode(BUZZER, OUTPUT);
    pinMode(SIGNAL_PIN,INPUT);
  }

  void loop(){
    int volt = map(analogRead(SIGNAL_PIN),0,1023,0,5000);
    distance = (21.61/(volt-0.1696))*1000;

    if (distance <=30){

      tone(BUZZER,400);
      delay(500);
      noTone(BUZZER);
      delay(500);
      }
      else{
        delay (500);
      }

      Serial.print(distance);
      Serial.println("cm");
      delay(500);
      
  }
