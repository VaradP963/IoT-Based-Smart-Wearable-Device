
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <SPI.h>

MPU6050 mpu6050(Wire);

  long timer = 0;
  int steps=0;
  float distanceinonestep= 71 ; 
  float distance;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  
}

void loop() {
  mpu6050.update();
 
if(millis() - timer > 1000){
  Serial.print("\taccY : ");
  Serial.println(mpu6050.getAccY());   
  }
  
if(mpu6050.getAccY()>0.7)
{
  steps+=1;
  delay(600);
}

if((mpu6050.getAccX() > 1.8)|| (mpu6050.getAccY() > 1.8) || (mpu6050.getAccZ() > 1.8))
{
  Serial.println("\t\tAccident Detected!!!");
  }

//if( SOSButton == HIGH){
//  Serial.println("Alert Sent to Emergency Number!");
//  }  

  Serial.print("steps");
  Serial.println(steps);
  
  distance = steps*distanceinonestep/100;  
  Serial.print("distance");
  Serial.println(distance);
  Serial.println("");
  delay(100);
  
   }
