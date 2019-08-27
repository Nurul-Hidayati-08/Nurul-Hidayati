#define LIGHT A3
#define LED A5
 
int BUZZER = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LIGHT, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(LIGHT);
  int data = map(value, 0, 1023, 0, 255);

  if(data > 100){
    tone(BUZZER, 200);
    delay(100);
    Serial.print("BEEP SOUND \n");
    }
  else {
    noTone(BUZZER);
    delay(100); 
    Serial.print("NO SOUND \n"); 
    }
    
  Serial.print("LIGHT: ");
  Serial.println(data);

  analogWrite(LED, data);

  delay(100);
}
