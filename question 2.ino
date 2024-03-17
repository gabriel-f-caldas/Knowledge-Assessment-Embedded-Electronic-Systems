#define BUTTON_PIN 3
#define DELAY 10000 // ms
#define CLOCK 16000000 // Arduino UNO's clock in Hz

enum States {OFF, ON, PROTECTED};
States state = OFF; // initial state

int ti = 0; // initial millis() time
int tf; // final millis() time
int dt; // delta dt = tf - ti

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);

}

void loop() {
  
  int buttonState = digitalRead(BUTTON_PIN);
  switch(state){
    case OFF:
      if(buttonState == HIGH){
        ti = millis();
        state = ON;
      }
      break;
    case ON:
      if(buttonState == LOW){
        tf = millis();
        dt = tf - ti;
        Serial.print("Pressed time (ms): "); Serial.println(dt);
        state = PROTECTED;
      }
      break;
    case PROTECTED:
      if(buttonState == LOW){
        delay(DELAY);
        state = LOW;
      }else{
        state = ON;
      }
  }
  

}
