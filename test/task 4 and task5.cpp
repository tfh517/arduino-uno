#include<Arduino.h>
#include <AFMotor.h>//下载Adafruit Motor Shield库
   
// 初始化电机引脚
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
   
int val;
int Speeed = 255; // 速度值，可在0到255之间调整
   
void setup()
{
  Serial.begin(9600);  // 设置蓝牙模块的波特率
}
void loop(){
  if(Serial.available() > 0){
    val = Serial.read();
       
    Stop(); // 初始状态：所有电机停止
       
          if (val == 'F'){
          forward();
          }
   
          if (val == 'B'){
          back();
          }
   
          if (val == 'L'){
          left();
          }
   
          if (val == 'R'){
          right();
          }
          if (val == 'I'){
          topright();
          }
   
          if (val == 'J'){
          topleft();
          }
   
          if (val == 'K'){
          bottomright();
          }
   
          if (val == 'M'){
          bottomleft();
          }
          if (val == 'T'){
          Stop();
          }
  }
}
            
   
  /*
    电机1= 左上 
    电机2= 左下
    电机3= 右下
    电机4= 右上
 
    电机1和电机4是两个前进电机
    电机2和电机3是两个后退电机
 
    
  */         
   
   
   
void forward()
{
  motor1.setSpeed(Speeed); 
  motor1.run(FORWARD); 
  motor2.setSpeed(Speeed); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(Speeed);
  motor3.run(FORWARD); 
  motor4.setSpeed(Speeed);
  motor4.run(BACKWARD); 
}
   
void back()
{
  motor1.setSpeed(Speeed); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(Speeed); 
  motor2.run(FORWARD); 
  motor3.setSpeed(Speeed); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(Speeed); 
  motor4.run(FORWARD);  
}
   
void left()
{
 
  motor1.setSpeed(Speeed); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(Speeed); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(Speeed); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(Speeed); 
  motor4.run(BACKWARD); 
 
   
}
   
void right()
{
 
  motor1.setSpeed(Speeed); 
  motor1.run(FORWARD); 
  motor2.setSpeed(Speeed); 
  motor2.run(FORWARD); 
  motor3.setSpeed(Speeed);
  motor3.run(FORWARD); 
  motor4.setSpeed(Speeed);
  motor4.run(FORWARD); 
   
}
   
void topleft(){
 
  motor1.setSpeed(Speeed); 
  motor1.run(FORWARD); 
//  motor2.setSpeed(Speeed/3.1); 
//  motor2.run(FORWARD); 
  motor3.setSpeed(Speeed);
  motor3.run(FORWARD); 
//  motor4.setSpeed(Speeed);
//  motor4.run(FORWARD); 
 
}
   
void topright()
{
 
//  motor1.setSpeed(Speeed); 
//  motor1.run(FORWARD); 
  motor2.setSpeed(Speeed); 
  motor2.run(BACKWARD); 
//  motor3.setSpeed(Speeed/3.1);
//  motor3.run(FORWARD); 
  motor4.setSpeed(Speeed);
  motor4.run(BACKWARD); 
   
}
   
void bottomleft()
{
 
//  motor1.setSpeed(Speeed); 
//  motor1.run(FORWARD); 
  motor2.setSpeed(Speeed); 
  motor2.run(FORWARD); 
//  motor3.setSpeed(Speeed/3.1);
//  motor3.run(FORWARD); 
  motor4.setSpeed(Speeed);
  motor4.run(FORWARD); 
 
   
}
   
void bottomright()
{
 
 
 
 
  motor1.setSpeed(Speeed); 
  motor1.run(BACKWARD); 
//  motor2.setSpeed(Speeed/3.1); 
//  motor2.run(FORWARD); 
  motor3.setSpeed(Speeed);
  motor3.run(BACKWARD); 
//  motor4.setSpeed(Speeed);
//  motor4.run(FORWARD); 
   
 
}
   
   
void Stop()
{
  motor1.setSpeed(0); 
  motor1.run(RELEASE); // 释放按钮时停止电机
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
  motor3.setSpeed(0); 
  motor3.run(RELEASE); 
  motor4.setSpeed(0); 
  motor4.run(RELEASE); 
}