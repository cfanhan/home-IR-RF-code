

#include <RCSwitch.h>
boolean on=0;
RCSwitch mySwitch = RCSwitch();


void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
   Serial.begin(9600); 
  mySwitch.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2
}

void loop() {
 if (mySwitch.available()) {
 int value = mySwitch.getReceivedValue();
Serial.println( mySwitch.getReceivedValue() );
 if(mySwitch.getReceivedValue()==14505456)//冷水
 {
  digitalWrite(6, LOW);
  delay(300);
 }
 if(mySwitch.getReceivedValue()==14505423)//热水
 {
  digitalWrite(6, HIGH);
  delay(300);
 }
 if(mySwitch.getReceivedValue()==14505420)//水泵开
 {
  digitalWrite(4,LOW);
  delay(300);
  }
  if(mySwitch.getReceivedValue()==14505411)//水泵关
 {
  digitalWrite(4, HIGH);
  delay(300);
  }
 if(mySwitch.getReceivedValue()==14505408)//上水
 {
  digitalWrite(3, LOW);
  delay(500);
  digitalWrite(3,HIGH);
  delay(300);
 }
 if(mySwitch.getReceivedValue()==14505276)//加热
 {
  digitalWrite(5, LOW);
  delay(500);
  digitalWrite(5,HIGH);
  delay(300);
  
 }
  mySwitch.resetAvailable();
  
 }
 
 }

