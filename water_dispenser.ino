//WATER DISPENSER
#define trigger 5
#define echo 4
#define Relay 6

float time=0
float distance=0;
 
void setup()
{
Serial.begin(9600);

 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(Relay,OUTPUT);

 delay(2000);
}
 
void loop()
{
 measure_distanceFromSensor();

 if(distance<5)
 {
   digitalWrite(Relay,HIGH); //if the object is near the relay triggers the motor
 }
 else
 {
   digitalWrite(Relay,LOW);  //if the object is not near, the reading is ignored
 }

 delay(250);
}

void measure_distanceFromSensor()
{
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH); 
 
 distance=time*500/50000; //distance calculation formula
}
