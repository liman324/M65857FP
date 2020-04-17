#include <M65857FP.h>

M65857FP sur(2,3,4); // DATA, CLOCK, LATCH

void setup(){
   audio();
}

void loop(){}

void audio(){
  sur.setReg(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
          // 1  2  3  4  5  6  7  8  9  10
  // 1 - MODE bool 0...1 === By_pass...QSurround_5.1
  // 2 - INPUT bool 0...1 === Mono...Stereo
  // 3 - CENTER bool 0...1 === OFF...ON
  // 4 - Surround output bool 0...1 === OFF...ON
  // 5 - Surround effeсt bool 0...1 === Narrow...Wide
  // 6 - Delay time byte 0...3 === 20 30 40 50 (ms)
  // 7 - Delay LPF bool 0...1 === 3...7 (kHz)
  // 8 - Delay effect bool 0...1 === OFF...ON
  // 9 - Delay gain bute 0...2 === 1 2 3 4 (gain low...high)
  // 10 - Delay feed back gain byte 0...4 === -3 -6 -9 -12 ∞ (dB)
  }
