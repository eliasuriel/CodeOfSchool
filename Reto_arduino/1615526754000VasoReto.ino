
#include <DHT.h>

const int trigger = 4;
const int echo = 3;
int foto=A0;
int led=6;

const int DHTPin = 8;
DHT dht(DHTPin,DHT11);

void setup() {
Serial.begin(9600);
pinMode(5, OUTPUT);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
digitalWrite(trigger, LOW);
pinMode(foto,INPUT);
pinMode(led,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
Serial.begin(9600);
Serial.println("Prueba del sensor DHT11");
dht.begin();
}
void loop()
{
long tiempo;
long dist;
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
tiempo = pulseIn(echo, HIGH);
dist = tiempo/59;
Serial.print("Distancia: ");
Serial.print(dist);
Serial.print("cm");
Serial.println();
if (dist>=2 && dist<=320){
  digitalWrite(5, HIGH);
}
else {
  digitalWrite(5, LOW);
}
delay(300);

///Fotoresistencia
int val = analogRead(foto);
int val2 = map(val,54,500,0,300);
analogWrite(led, val2);
Serial.print("El valor es: ");
Serial.println(val2);
if (val2<=10){
  digitalWrite(led,HIGH);
}
else {
  digitalWrite(led,LOW);
}  

//sensor de temperatura
delay(2000);
float h = dht.readHumidity();
float t= dht.readTemperature();
if(isnan(h)||isnan(t)){
  Serial.println("Error en medición del sensor!");
  return;
  }
  Serial.print("Humedad:");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature:");
  Serial.print(t);
  Serial.print("*C");
  Serial.println();
  if(t>=25){
    digitalWrite(9,HIGH);
  }
  else{
    digitalWrite(10,HIGH);
  }
  }
