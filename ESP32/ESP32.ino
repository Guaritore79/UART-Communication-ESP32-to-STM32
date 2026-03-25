#include <PS4Controller.h>

char Trans [5] = "ABC";
unsigned long int prev_mil;
int8_t ry;


void setup() {
  Serial.begin(115200);
  // PS4.attach(notify);
  PS4.begin("44:af:28:07:5e:21");

}

void loop() {
  if (millis() - prev_mil >= 1){
    ry = PS4.RStickY();

    memcpy(Trans+3, &ry, 1);

    for (int i = 0; i < sizeof(Trans); i++){
      Serial.write(Trans[i]);
    }
    prev_mil += 1;
  }
   
}
