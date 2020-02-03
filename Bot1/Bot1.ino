#define pwm2 7
#define pwm1 2
#define in1 3
#define in2 4
#define in3 5
#define in4 6
boolean flag=true;
const int lineFollowSensor0 = 52;
const int lineFollowSensor1 = 50;
const int lineFollowSensor2 = 48;
const int lineFollowSensor3 = 46;
const int lineFollowSensor4 = 44;
const int lineFollowSensor5 = 42;
const int lineFollowSensor6 = 40;
const int lineFollowSensor7 = 38;
int pos[8] = { -4, -3, 0, -1, 1, 0, 3, 4};
int LFSensor[8] = { 0, 0, 0, 0, 0, 0, 0, 0};
int e;
int n;
void Whiteline();
void Blackline();
int error()
{ 
  e = 0;
  for (int i = 0; i < 8; i++)
  {
    e+= pos[i] * LFSensor[i];
  }
  return e;
}
void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(lineFollowSensor0,INPUT);
  pinMode(lineFollowSensor1,INPUT);
  pinMode(lineFollowSensor2,INPUT);
  pinMode(lineFollowSensor3,INPUT);
  pinMode(lineFollowSensor4,INPUT);
  pinMode(lineFollowSensor5,INPUT);
  pinMode(lineFollowSensor6,INPUT);
  pinMode(lineFollowSensor7,INPUT);
}


void Blackline()
  {
 
  if((LFSensor[3]==0 && LFSensor[4]==0)  && (LFSensor[0]==1 && LFSensor[7]==1)) //straight
  {
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);
//   flag1=true;
  }
 else if(LFSensor[4]==0 && LFSensor[3]==0  && LFSensor[5]==0 && LFSensor[6]==0 && LFSensor[7]==0 && LFSensor[1]==0 && LFSensor[2]==0 && LFSensor[0]==0)//right
 {
  turn_right();
//  flag1=false;
 }
 else if(LFSensor[4]==0 && LFSensor[3]==0  && LFSensor[0]==0 && LFSensor[1]==0 && LFSensor[2]==0 && LFSensor[6]==1 && LFSensor[7]==1)//left
 {
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
//    flag1=false;
 }
 else if(LFSensor[4]==0 && LFSensor[3]==0 &&  LFSensor[5]==0 && LFSensor[6]==0 && LFSensor[7]==0)//right
 {
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
//    flag1=false;
  }
else if(LFSensor[4]==0 && LFSensor[3]==1)
 {
   digitalWrite(in1,LOW);
   digitalWrite(in2,HIGH);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);
//    flag1=false;
 }
 else if(LFSensor[4]==1 && LFSensor[3]==0)
 {
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
   digitalWrite(in4,HIGH);
//    flag1=false;
 }
 else if((LFSensor[3]==1 ||LFSensor[4]==1) && (LFSensor[0]==0 &&LFSensor[7]==0))
 flag=true;
 
}
void m_stop()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,HIGH);
  delay(2000);

}

void turn_right()
{
  analogWrite(pwm1,150);
  analogWrite(pwm2,150);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  delay(300);
}

void Whiteline()
{
  //println("It's White");
  if((LFSensor[3]==1 && LFSensor[4]==1)  && (LFSensor[0]==0 && LFSensor[7]==0)) //straight
  {
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW); 
  }
  else if(LFSensor[4]==1 && LFSensor[3]==1  && LFSensor[5]==1 && LFSensor[6]==1 && LFSensor[7]==1 && LFSensor[1]==1 && LFSensor[2]==1 && LFSensor[0]==1)//stop and right
 { 
  turn_right();
 }
 else if(LFSensor[4]==1 && LFSensor[3]==1  && LFSensor[0]==1 &&LFSensor[1]==1 && LFSensor[2]==1 && LFSensor[6]==0 && LFSensor[7]==0)//left
 {
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW); 
 }
 else if(LFSensor[4]==1 && LFSensor[3]==1 &&  LFSensor[5]==1 && LFSensor[6]==1 && LFSensor[7]==1)//right
 {
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW); 
 }

 else if(LFSensor[4]==1 && LFSensor[3]==0)
 {
   digitalWrite(in1,LOW);
   digitalWrite(in2,HIGH);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);
  
 }
 else if(LFSensor[4]==0 && LFSensor[3]==1)
 {
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
   digitalWrite(in4,HIGH);  
 }
 else if((LFSensor[3]==0 ||LFSensor[4]==0) && (LFSensor[0]==1 &&LFSensor[7]==1))
 flag=false;
}



void loop() {
LFSensor[0] = digitalRead(lineFollowSensor0);
LFSensor[1] = digitalRead(lineFollowSensor1);
LFSensor[2] = digitalRead(lineFollowSensor2);
LFSensor[3] = digitalRead(lineFollowSensor3);
LFSensor[4] = digitalRead(lineFollowSensor4);
LFSensor[5] = digitalRead(lineFollowSensor5);
LFSensor[6] = digitalRead(lineFollowSensor6);
LFSensor[7] = digitalRead(lineFollowSensor7);
//if (LFSensor[4]==1 && LFSensor[3]==1  && LFSensor[5]==1 && LFSensor[6]==1 && LFSensor[7]==1 && LFSensor[0]==1 && LFSensor[1]==1  && LFSensor[2]==1)
 analogWrite(pwm1,130-(error()*3));
 analogWrite(pwm2,130+(error()*3));
 if(flag==true) 
 Whiteline();
 
 else if(flag==false)
 Blackline();    
}
