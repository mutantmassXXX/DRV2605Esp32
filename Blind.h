/* 
 Written by Jacob Policar, Jolo Tolentino, 古紹宏,胡晉騰
*/

#include <Wire.h>
#include "Arduino.h"
#ifndef Blind_h
#define Blind_h

class Blind{
  public:    
    TwoWire Setup(int PWMpin, int Channelpin, int Clock, int Data, int motorID);
    void Transmit(byte address, byte command,TwoWire motor); 
    
  private:
     const int  &_Freq = 5000;
     const int  &_resolution = 8; 
     int _address,_task,_MotorId,_PWMPin,_Channel,_Clock,_Data; 
    //  TwoWire _I2C;
  
};
#endif
