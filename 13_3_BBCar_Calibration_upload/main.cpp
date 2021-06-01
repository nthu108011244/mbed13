#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin5(D5), pin6(D6);

BBCar car(pin5, pin6, servo_ticker);

int main() {
   // please contruct you own calibration table with each servo
   double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
   double speed_table0[] = {-12.357, -16.343, -15.227, -11.639, -5.421, 0.000, 6.537, 12.437, 15.466, 11.401, 12.199};
   double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
   double speed_table1[] = {-12.357, -16.024, -15.067, -12.118, -6.139, 0.000, 5.660, 11.560, 14.669, 11.401, 12.199};

   // first and fourth argument : length of table
   car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);

   while (1) {
      car.goStraightCalib(5);
      ThisThread::sleep_for(5s);
      car.stop();
      ThisThread::sleep_for(5s);
   }
}