#define motor1IN1 4
#define motor1IN2 5
#define motor1IN3 6
#define motor1IN4 7
#include<SoftwareSerial.h>
SoftwareSerial BT(10,11); // 10 rx and 11 tx
char c;

void setup() 
{
Serial.begin(9600);
BT.begin(9600);
}

void loop() 
{
  while(BT.available())
  {
  delay(10);
  c=BT.read();
  
  Serial.println(c);
  switch(c)
    {
    case 'F':
      forward();
      break;
    case 'B':
      backward();
      break;
    case 'R':
     right();
     break;
    case 'L':
     left();
      break;
     case 'G':
      hardleft();
      break;
    case 'I':
      hardright();
      break;
    case 'S':
      brake();
      break;
     }
  }
}

void brake()
{
     
      digitalWrite(motor1IN1,LOW);
      digitalWrite(motor1IN2,LOW);
      digitalWrite(motor1IN3,LOW);
      digitalWrite(motor1IN4,LOW);
      BT.println("/n Brake");

}

void backward()
{
   
    digitalWrite(motor1IN1,LOW);
    digitalWrite(motor1IN2,HIGH);
    digitalWrite(motor1IN3,LOW);
    digitalWrite(motor1IN4,HIGH);
   BT.println("/n backward");
}

void forward()
{
    
    digitalWrite(motor1IN1,HIGH);
    digitalWrite(motor1IN2,LOW);
    digitalWrite(motor1IN3,HIGH);
    digitalWrite(motor1IN4,LOW);
    BT.println("/n forward");
}

void right()//forward right
{
    
    digitalWrite(motor1IN1,HIGH);
    digitalWrite(motor1IN2,LOW);
    digitalWrite(motor1IN3,LOW);
    digitalWrite(motor1IN4,HIGH);
    BT.println("/n hardright");
}


void left()//forward left
{
    digitalWrite(motor1IN1,LOW);
    digitalWrite(motor1IN2,HIGH);
    digitalWrite(motor1IN3,HIGH);
    digitalWrite(motor1IN4,LOW);
    BT.println("/n hardleft");    
}


void hardleft()
{     
    digitalWrite(motor1IN1,LOW);
    digitalWrite(motor1IN2,LOW);
    digitalWrite(motor1IN3,HIGH);
    digitalWrite(motor1IN4,LOW);
    BT.println("/n left");
    }


void hardright()
{
    
    digitalWrite(motor1IN1,HIGH);
    digitalWrite(motor1IN2,LOW);
    digitalWrite(motor1IN3,LOW);
    digitalWrite(motor1IN4,LOW);
    BT.println("/n right");
    }