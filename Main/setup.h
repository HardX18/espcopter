#include "Arduino.h"


void mainSetup(){

  // Begin Serail
  Serial.begin(115200);// 921600   

  
  //analogWriteFreq(20000); 
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);

  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);
  digitalWrite(D7, LOW);
  digitalWrite(D8, LOW);


  // Initialize the PWM
  // Initial duty -> all off
  for (uint8_t channel = 0; channel < PWM_CHANNELS; channel++) {
    pwm_duty_init[channel] = 0;
  }


  // Period
  uint32_t period = PWM_PERIOD;


  // Initialize
  pwm_init(period, pwm_duty_init, PWM_CHANNELS, io_info);


  // Commit
  pwm_start();



  esp.redLed_Digital(false);
  esp.blueLed_Digital(false);
  esp.greenLed_Digital(false);
  
  
  EEPROM.begin(512);


  ahrs.Initialize();

  if(Trim_DF == 1){
  EEPROM.write(60,highByte(Trim_Roll_DF));
  EEPROM.write(61,lowByte(Trim_Roll_DF));

  EEPROM.write(62,highByte(Trim_Pitch_DF));
  EEPROM.write(63,lowByte(Trim_Pitch_DF));

  EEPROM.write(64,highByte(Trim_Yaw_DF));
  EEPROM.write(65,lowByte(Trim_Yaw_DF));
  
  EEPROM.commit();
  }

  Trim_Roll_Bs = word(EEPROM.read(60),EEPROM.read(61));
  Trim_Pitch_Bs = word(EEPROM.read(62),EEPROM.read(63));
  Trim_Yaw_Bs = word(EEPROM.read(64),EEPROM.read(65));

  yaw.SetItermRate(Trim_Yaw_Bs);

  
  roll.SetGain(15.2, 25.0, 0.18,0.0,1.4);
  roll.SetLimit(4500, 3000, 6000);
   
  pitch.SetGain(15.2, 25.0, 0.18,0.0,1.4);
  pitch.SetLimit(4500, 3000, 6000);
   
  yaw.SetGain(0.8,0.3,0.5,0.9,0.0);
  yaw.SetLimit(4500, 1000, 6000); 
   
  oto.SetGain(0.0, 0.0, 1.8,1.5,750.0);
  oto.SetLimit(1000, 1000, 6500); 
    
  esp.redLed_Digital(false);
  esp.blueLed_Digital(false);
  esp.greenLed_Digital(true);


  setupWiFi();
}
