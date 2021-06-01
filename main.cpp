#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin5(D5), pin6(D6);
BBCar car(pin5, pin6, servo_ticker);

int main() {
   while(1){
      car.goStraight(200);
      ThisThread::sleep_for(1s);
      car.stop();
      ThisThread::sleep_for(1s);
   }
}