#include <Wire.h>
#include "Arduino.h"
#include "Blind.h"


TwoWire Blind::Setup(int PWMpin, int Channelpin, int Clock, int Data, int motorID){
  _PWMPin =PWMpin;_Channel = Channelpin;_Clock = Clock;_Data = Data; _MotorId = motorID; 
  ledcSetup(_Channel,_Freq,_resolution); 
  ledcAttachPin(_PWMPin,_Channel);
  TwoWire I2C = TwoWire(motorID);
  Serial.print("Motor "); Serial.print(_MotorId); Serial.println(" Initialized");
  return I2C;
}

void Blind::Transmit (byte address, byte command, TwoWire motor) {
  motor.beginTransmission((byte)0x5A);
  motor.write((byte)address); motor.write((byte)command);
  motor.endTransmission();
}
