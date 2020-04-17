#include <M65857FP.h>

  byte del_time[4][2] = {{0,0},{1,0},{0,1},{1,1}}; // 0...3 | 20 30 40 50 ms
  byte del_gain[4][2] = {{0,0},{1,0},{0,1},{1,1}}; // 0...3 | 1 2 3 4 
  byte del_feed_gain[5][3] = {{0,0,0},{1,0,0},{0,1,0},{1,1,0},{1,1,1}}; // 0...4 | -3 -6 -9 -12 && dB

M65857FP::M65857FP(uint8_t data, uint8_t clock, uint8_t latch){
          DATA = data;
          CLOCK = clock;
          LATCH = latch;
      pinMode(DATA,OUTPUT);
      pinMode(CLOCK,OUTPUT);
      pinMode(LATCH,OUTPUT);
}

void M65857FP::setReg(bool mode_b, bool in_b, bool center_b, bool sur_out_b, bool surr_ef_b, byte del_time_b, bool del_lpf_b, bool del_ef_b, bool del_gain_b, byte del_feed_gain_b){
     // CLOCK
     digitalWrite(LATCH,HIGH);
     delay(2);
     digitalWrite(LATCH,LOW);
     
     // 1 - MODE
     digitalWrite(DATA, mode_b);delay(1);
     digitalWrite(CLOCK, HIGH);delay(2);
     digitalWrite(CLOCK, LOW);delay(1);

     // 2- INPUT
     digitalWrite(DATA, in_b);delay(1);
     digitalWrite(CLOCK, HIGH);delay(2);
     digitalWrite(CLOCK, LOW);delay(1);

     // 3 - CENTER
     digitalWrite(DATA, center_b);delay(1);
     digitalWrite(CLOCK, HIGH);delay(2);
     digitalWrite(CLOCK, LOW);delay(1);

     // 4 - SURROUND OUTPUT
     digitalWrite(DATA, sur_out_b);delay(1);
     digitalWrite(CLOCK, HIGH);delay(2);
     digitalWrite(CLOCK, LOW);delay(1);

     // 5 - SURROUND EFFECT
     digitalWrite(DATA, surr_ef_b);delay(1);
     digitalWrite(CLOCK, HIGH);delay(2);
     digitalWrite(CLOCK, LOW);delay(1);

     // 6 - DELAY TIME
 for(int i=0;i<2;i++){
     digitalWrite(DATA, del_time_b[del_time][i]);delay(1);
     digitalWrite(CLOCK, HIGH);delay(2);
     digitalWrite(CLOCK, LOW);delay(1);}

     // 7 - DELAY LPF
     digitalWrite(DATA, del_lpf_b);delay(1);
     digitalWrite(CLOCK, HIGH);delay(2);
     digitalWrite(CLOCK, LOW);delay(1);

     // 8 - DELAY EFFECT
     digitalWrite(DATA, del_ef_b);delay(1);
     digitalWrite(CLOCK, HIGH);delay(2);
     digitalWrite(CLOCK, LOW);delay(1);

     // 9 - DELAY GAIN
 for(int i=0;i<2;i++){
     digitalWrite(DATA, del_gain_b[del_gain][i]);delay(1);
     digitalWrite(CLOCK, HIGH);delay(2);
     digitalWrite(CLOCK, LOW);delay(1);}

     // 10 - DELAY FEED BACK GAIN
 for(int i=0;i<3;i++){
     digitalWrite(DATA, del_feed_gain_b[del_feed_gain][i]);delay(1);
     digitalWrite(CLOCK, HIGH);delay(2);
     digitalWrite(CLOCK, LOW);delay(1);}
     
     // DE 1
     digitalWrite(DATA, HIGH);delay(1);
     digitalWrite(CLOCK, HIGH);delay(2);
     digitalWrite(CLOCK, LOW);delay(1);
     // DF 0
     digitalWrite(DATA, LOW);delay(1);
     digitalWrite(CLOCK, HIGH);delay(2);
     digitalWrite(CLOCK, LOW);delay(2);
}
