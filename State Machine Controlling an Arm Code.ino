#define bp1 13
#define bp2 12
#define IR1 3
#define IR2 2
#define M_droit 8
#define M_gauch 7
#define vitesse 5


int etat_bp1,etat_bp2,etat_ir1,etat_ir2;

int memoir_bp1=HIGH;
int memoir_bp2=HIGH;
int memoir_ir1=HIGH;
int memoir_ir2=HIGH;






void setup() {
 pinMode(bp1,INPUT);
 pinMode(bp2,INPUT);
 pinMode(IR1,INPUT);
 pinMode(IR2,INPUT);

 pinMode(M_gauch,OUTPUT);
 pinMode(M_droit,OUTPUT);

 attachInterrupt(digitalPinToInterrupt(IR1),IR_1, LOW);
 attachInterrupt(digitalPinToInterrupt(IR2),IR_2, LOW);


}
enum{etat0,etat1,etat2,etat3,etat4};
int etat=etat0;


void IR_1(){
  etat_ir1=LOW;
}

void IR_2(){
  etat_ir2=LOW;
}

void M_gauch_10(){
  digitalWrite(M_droit,LOW);
  digitalWrite(M_gauch,HIGH);
  analogWrite(vitesse,25);
  
}

void M_droit_10(){
  digitalWrite(M_droit,HIGH);
  digitalWrite(M_gauch,LOW);
  analogWrite(vitesse,25);
  
}

void M_gauch_100(){
  digitalWrite(M_droit,LOW);
  digitalWrite(M_gauch,HIGH);
  analogWrite(vitesse,255);
  
}

void M_droit_100(){
  digitalWrite(M_droit,HIGH);
  digitalWrite(M_gauch,LOW);
  analogWrite(vitesse,255);
  
}


void loop() {
etat_bp1=digitalRead(bp1);
etat_bp2=digitalRead(bp2);
etat_ir1=digitalRead(IR1);
etat_ir2=digitalRead(IR2);



;
switch(etat){
  case etat0:
  if(etat_bp1==1&&etat_bp2==1){etat=etat1;}
  if(etat_bp1==1&&etat_bp2==0){etat=etat4;}
  if(etat_bp1==0&&etat_bp2==1){etat=etat3;}
  break;

  case etat1:
  M_droit_10();
  if(etat_bp2!=memoir_bp2&&etat_bp2==LOW){etat=etat4;}
  break;

  case etat2:
  M_gauch_10();
  if(etat_bp1!=memoir_bp1&&etat_bp1==LOW){etat=etat3;}
  break;

  case etat3:
  M_droit_100();
  if(etat_ir2!=memoir_ir2&&etat_ir2==LOW){etat=etat1;}
  break;

  case etat4:
  M_gauch_100();
  if(etat_ir1!=memoir_ir1&&etat_ir1==LOW){etat=etat2;}
  break;
}

memoir_bp1=etat_bp1;
memoir_bp2=etat_bp2;
memoir_ir1=etat_ir1;
memoir_ir2=etat_ir2;
  
  
}
