//  M65857FP MITSUBISHI SOUND PROCESSOR ICs
//  Alexander Liman
//  liman324@yandex.ru
//  rcl-radio.ru

#ifndef  M65857FP_H
#define  M65857FP_H

#include <Arduino.h>


class  M65857FP
  {
    public:

  M65857FP(uint8_t, uint8_t, uint8_t);
  void setReg(bool mode_b, bool in_b, bool center_b, bool sur_out_b, bool surr_ef_b, byte del_time_b, bool del_lpf_b, bool del_ef_b, bool del_gain_b, byte del_feed_gain_b);
  
    private:

  uint8_t DATA;
  uint8_t CLOCK;
  uint8_t LATCH;

  };
#endif
