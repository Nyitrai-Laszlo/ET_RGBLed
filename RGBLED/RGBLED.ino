int r=9;
int b=10;
int g=11;

byte fenyEro=0;
byte irany=1;

int poti=0;

int kapcs=2;

bool mukodik=true;

void setup() {
 pinMode(r, OUTPUT);
 pinMode(b, OUTPUT);
 pinMode(g, OUTPUT); 
pinMode(A0, INPUT); Serial.begin(9600); 
pinMode(A1,INPUT);
  pinMode(A2,INPUT);
pinMode(kapcs, INPUT_PULLUP);
  
 digitalWrite(r,1); delay(500); 
 
 digitalWrite(r,0);
digitalWrite(b,1); delay(500);

digitalWrite(b,0);
digitalWrite(g,1); delay(500);

digitalWrite(r,1);
digitalWrite(b,1); delay(500);

digitalWrite(r,0);
digitalWrite(g,0);
digitalWrite(b,0);

//analogWrite(r,125);
//analogWrite(g,15);
//analogWrite(b,214);

}


void loop() {

 if (mukodik){
  
 

poti=analogRead(A0);
fenyEro=map (poti,0,1023,0,255);
analogWrite(r,fenyEro);

poti=analogRead(A1);
fenyEro=map (poti,0,1023,0,255);
analogWrite(g,fenyEro);

poti=analogRead(A2);
fenyEro=map (poti,0,1023,0,255);
analogWrite(b,fenyEro);
 }
 else
 {
  digitalWrite(r,0);
  digitalWrite(g,0);
  digitalWrite(b,0);
 }

if(digitalRead(kapcs)==0)
{
  delay(100);
  if (digitalRead(kapcs)==0){
    mukodik=!mukodik;
    Serial.println(mukodik);
    }
  
  }
  /*Serial.print("Analóg érték: ");
  Serial.print(poti_3);
  Serial.print("; Fényerő: ");
  Serial.println(fenyEro);*/
  

    
  //analogWrite(r,fenyEro);
 //analogWrite(b,fenyEro);
 //analogWrite(g,fenyEro);
 /*if (fenyEro==255) irany=-1;
 if (fenyEro==0) irany=1;
 fenyEro=fenyEro+irany;
 delay(10);*/

}
