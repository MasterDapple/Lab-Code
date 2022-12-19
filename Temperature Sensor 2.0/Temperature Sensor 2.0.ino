#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;
int led = 7;



void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  pinMode(7, OUTPUT);

}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print("Current Humidity (Percentage)= ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("Temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    delay(500);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
     if(DHT.humidity > 50.)
    {
    	digitalWrite(led, HIGH);
    }
  else{
       digitalWrite(led, LOW);
  }
}// end loop() 

