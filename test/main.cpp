#include<Arduino.h>
#include <Servo.h>

Servo myServo;
const int servopin = 2;
const int btnUpin = 3;
const int btnDpin = 4;
int angle = 90;
const unsigned long longPressT = 400;
const unsigned long stepInterval = 500;
bool ULongPress = false;
bool DLongPress = false;
bool laser = LOW;                     // 激光当前状态(初始为暗)
bool lastButtonStep = HIGH;           // 上一次按钮状态
void setup() {
  myServo.attach(servopin);
  myServo.write(angle);
  pinMode(btnUpin, INPUT_PULLUP);
  pinMode(btnDpin, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, OUTPUT);
}

void loop() {
  Btn(btnUpin, true);
  Btn(btnDpin, false);
bool button = digitalRead(6);
  if (lastButtonStep == HIGH && button == LOW)    //检测啥时候按钮按下
  {
    laser = !laser;           // 状态反转
    digitalWrite(7, laser);
    delay(200);                      
  }
  lastButtonStep = button;    //重置上一次按钮状态为当前状态
}
void Btn(int pin, bool increase)
 {
  bool pressed;
  if(digitalRead(pin)==LOW)
  {
    pressed=true;  
  }
  else
  {
    pressed=false;
  }
  unsigned long now = millis();
  static unsigned long pressT[2];
  static unsigned long lastStepT[2];
  static bool longPressed[2];
  int i = increase ? 0 : 1;
  if (pressed)
   {
    if (pressT[i] == 0)     //判断是不是第一次按按钮
    {
      pressT[i] = now;
      lastStepT[i] = now;
      longPressed[i] = false;
    }
    if (!longPressed[i] && now - pressT[i] >= longPressT)     //如果还没被判断成长按且达到长按要求，设置成长按
    {
      longPressed[i] = true;
    }
    if (longPressed[i] && now - lastStepT[i] >= stepInterval)   //如果是长按，以长按方式转
    {
      angle += increase ? 10 : -10;
      angle = constrain(angle, 0, 180);
      myServo.write(angle);
      delay(200);
      lastStepT[i] = now;
    }
  } 
  else                        //松手的时候判断是不是点按
  {
    if (pressT[i] != 0 && !longPressed[i])  //如果是点按，以点按方式转
     {
      angle += increase ? 45 : -45;
      angle = constrain(angle, 0, 180);
      myServo.write(angle);
      delay(200);
    }
    pressT[i] = 0;
    longPressed[i] = false;     //状态重置
  }
}
