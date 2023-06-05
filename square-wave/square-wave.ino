#include <button.h>

unsigned long last_t = 0;

int f = 10;

#define FREQ_OUT_PIN 13

button button1(2, HIGH);

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  pinMode(FREQ_OUT_PIN, OUTPUT);

  button1.init(); //Initialize button1
}

void loop() {

  if(button1.push()){
    f += 10;
    if(f > 60) f = 10;
  }

  if(millis() - last_t >= TperiodMilliSecond(f)/2.0){
    last_t = millis();
    digitalWrite(FREQ_OUT_PIN, !digitalRead(FREQ_OUT_PIN));
  }
}

int TperiodMilliSecond(int freq){
  return (1/(float)freq)*1000;
}
