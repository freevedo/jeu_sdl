#define joyX A0
#define joyY A2
char data;
int xValue;
int yValue;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(8,OUTPUT);//leds test pour la proximite
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0)
  {
    //read from the terminal the data from the game 
    //1 if collision
    //2 if near
     data = (char) Serial.read();//read only one byte
    delay(5);
  }
  if (data == '1')
  {
    digitalWrite(8,HIGH);
  }
  else if (data == '2')
  {
    digitalWrite(9,HIGH);
    //digitalWrite(8,LOW);
  }
  
  else if (data == '0')
  {
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }

  xValue=analogRead(joyX);
   yValue=analogRead(joyY);

   Serial.println(xValue);
   //printf("\t");
  // Serial.println(yValue);
   
   if (xValue>530&&xValue<=1023)
   Serial.println("3");
   if (xValue==0)
    Serial.println("7");
    if (xValue>530&&xValue<=1023)
   Serial.println("1");
   if (yValue==0)
    Serial.println("2");
       
}
