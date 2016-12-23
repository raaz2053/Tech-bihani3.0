// Bluetooth Control
#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);
const int m1a=6;
const int m1b=5;
const int m2a=7;
const int m2b=8;
const int en1=3;
const int en2=9;
boolean abc=false;
char Bdata;
int thres=500;
void setup()
{ pinMode(m1a,OUTPUT);
pinMode(m1b,OUTPUT);
pinMode(m2a,OUTPUT);
pinMode(m1b,OUTPUT);
pinMode(en1,OUTPUT);
pinMode(en2,OUTPUT);
BT.begin(9600);
Serial.begin(9600);
}
void loop() {
if (BT.available()){
  if(BT.available()>0){
    delay(3);
    Bdata=BT.read();
   }
}
Serial.println(Bdata);
//Serial.println(count);
if(Bdata=='W')
{ abc=true;
}
{
if(abc)
{ automatic();
  }
else
{
  manual();
   }
  }
  
 }

void fd()
{ digitalWrite(m1a,1);
digitalWrite(m1b,0);
digitalWrite(m2a,1);
digitalWrite(m2b,0);
analogWrite(en1,160);
analogWrite(en2,160);
}
void forward()
{ digitalWrite(m1a,1);
digitalWrite(m1b,0);
digitalWrite(m2a,1);
digitalWrite(m2b,0);
analogWrite(en1,200);
analogWrite(en2,200);
}
void left()
{ digitalWrite(m1a,1);
digitalWrite(m1b,0);
digitalWrite(m2a,0);
digitalWrite(m2b,1);
analogWrite(en1,200);
analogWrite(en2,200);
}
void right()
{ digitalWrite(m1a,0);
digitalWrite(m1b,1);
digitalWrite(m2a,1);
digitalWrite(m2b,0);
analogWrite(en1,200);
analogWrite(en2,200);
}
void lt()
{ digitalWrite(m1a,1);
digitalWrite(m1b,0);
digitalWrite(m2a,0);
digitalWrite(m2b,1);
analogWrite(en1,160);
analogWrite(en2,160);
}
void rt()
{ digitalWrite(m1a,0);
digitalWrite(m1b,1);
digitalWrite(m2a,1);
digitalWrite(m2b,0);
analogWrite(en1,160);
analogWrite(en2,160);
}
void back()
{ digitalWrite(m1a,0);
digitalWrite(m1b,1);
digitalWrite(m2a,0);
digitalWrite(m2b,1);
analogWrite(en1,200);
analogWrite(en2,200);
}
void halt()
{ digitalWrite(m1a,1);
digitalWrite(m1b,1);
digitalWrite(m2a,1);
digitalWrite(m2b,1);
analogWrite(en1,200);
analogWrite(en2,200);
}
void forlft()
{ digitalWrite(m1a,1);
digitalWrite(m1b,0);
digitalWrite(m2a,1);
digitalWrite(m2b,0);
analogWrite(en1,200);
analogWrite(en2,100);
}
void forrht()
{ digitalWrite(m1a,1);
digitalWrite(m1b,0);
digitalWrite(m2a,1);
digitalWrite(m2b,0);
analogWrite(en1,100);
analogWrite(en2,200);
}
void bcklft()
{ digitalWrite(m1a,0);
digitalWrite(m1b,1);
digitalWrite(m2a,0);
digitalWrite(m2b,1);
analogWrite(en1,200);
analogWrite(en2,100);

}
void bckrht()
{ digitalWrite(m1a,0);
digitalWrite(m1b,1);
digitalWrite(m2a,0);
digitalWrite(m2b,1);
analogWrite(en1,100);
analogWrite(en2,200);

}
void automatic()
{ int a0=analogRead(A0);
  int a1=analogRead(A1);
  int a2=analogRead(A2);
  Serial.println(a0);
  if(a0<thres&&a1>thres&&a2<thres||a0>thres&&a1>thres&&a2>thres)
  { fd();
  }
  else if(a0>thres&&a1<thres&&a2<thres||a0>thres&&a1>thres&&a2<thres)
  { lt();
  }
  else if(a0<thres&&a1>thres&&a2>thres||a0<thres&&a1<thres&&a2>thres)
  { rt();
  }
  else
  { halt();
  }
 
}
void manual()
{ switch(Bdata)
{ case 'F': forward();
break;
case 'R': right();
break;
case 'L': left();
break;
case 'B': back();
break;
case 'G':forlft();
break;
case 'I':forrht();
break;
case 'J':bckrht();
break;
case 'H':bcklft();
break;
default: halt();
break;

 }
}
 

