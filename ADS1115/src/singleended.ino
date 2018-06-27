#include <Wire.h>
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads1(0x48);
Adafruit_ADS1115 ads2(0x49);
void setup(void)
{
  Serial.begin(9600);
  Serial.println("Hello!");
  Serial.println("Getting single-ended readings from AIN0..3");
  Serial.println("ADC Range: +/- 6.144V (1 bit =  188uV)");
  // 2/3x gain +/- 6.144V  1 bit = 3mV    0.1875mV (default)
  ads1.begin();
  ads2.begin();
}
void loop(void)
{
  int16_t adc0, adc1, adc2, adc3, adc4, adc5;
  float volt0, volt1, volt2, volt3, volt4, volt5;
  adc0 = ads1.readADC_SingleEnded(0);
  adc1 = ads1.readADC_SingleEnded(1);
  adc2 = ads1.readADC_SingleEnded(2);
  adc3 = ads1.readADC_SingleEnded(3);
  adc4 = ads2.readADC_SingleEnded(0);
  adc5 = ads2.readADC_SingleEnded(1);
  //Convert Back
  volt0 = adc0*0.000188;
  volt1 = adc1*0.000188;
  volt2 = adc2*0.000188;
  volt3 = adc3*0.000188;
  volt4 = adc4*0.000188;
  volt5 = adc5*0.000188;
  //Print
  Serial.print("LED-01: ");
  Serial.print(adc0);
  Serial.print(" ");
  Serial.print(volt0, 4);
  Serial.println(" vdc");
  
  Serial.print("LED-02: ");
  Serial.print(adc1);
  Serial.print(" ");
  Serial.print(volt1, 4);
  Serial.println(" vdc");
  
  Serial.print("LED-03: ");
  Serial.print(adc2);
  Serial.print(" ");
  Serial.print(volt2, 4);
  Serial.println(" vdc");
  
  Serial.print("LED-04: ");
  Serial.print(adc3);
  Serial.print(" ");
  Serial.print(volt3, 4);
  Serial.println(" vdc");
  
  Serial.print("LED-05: ");
  Serial.print(adc4);
  Serial.print(" ");
  Serial.print(volt4, 4);
  Serial.println(" vdc");
  
  Serial.print("LED-06: ");
  Serial.print(adc5);
  Serial.print(" ");
  Serial.print(volt5, 4);
  Serial.println(" vdc");
  Serial.println(" ");
  delay(1000);
}
