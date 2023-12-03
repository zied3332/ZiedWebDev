#include "DHT.h"
#define moutout 13  
#define ahmer 8
#define buzzer 4//le numéro de la broche sur laquelle la lampe 2  est branchée
#define PIN_LED2 7 // Le numéro de la broche sur laquelle la lampe 1 
//(par défaut intégrée dans la carte) est branchée 
#define pas  20 // incrément de l'intensité
char data; // variable contenant le caractère lu
int x; // variable contenant l'intensité de la deuxième lampe
DHT dht (2, DHT11);

float temp, hum ;

void setup() {
  // Configure la broche 11 sur laquelle est reliée notre LED  en sortie
  //inMode(moutout,OUTPUT);
//La LED reliée à la broche 11 est intialisé à l'état LOW

  // Configure la broche 13 sur laquelle est reliée notre LED  en sortie
  pinMode(PIN_LED2,OUTPUT);
//La LED reliée à la broche 13 est intialisé à l'état LOW
pinMode(moutout,OUTPUT);
  analogWrite(moutout, 0); 
  Serial.begin(9600); //Permet d'initialiser le moniteur série à 9600 bauds 
  x=0; // Intialiser l'intensité de la deuxième lampe 

  dht.begin();


}

void sendTemperatureData() {
   Serial.print(temp);


}

void loop() {
  
  temp= dht.readTemperature();
    hum= dht.readHumidity();
       
  if (Serial.available()){     
    //Si un message a été reçu  faire ceci
     data=Serial.read();  
     // controler la lampe 1 reliée à la broche 13
     //récuperer le caractère reçu
     if(data=='1') //si le caractère lu est égale à 1
    {
      // alumer la lampe 
      tone(buzzer,500,1000);
       digitalWrite(moutout,HIGH); 
         digitalWrite(PIN_LED2,LOW);
               digitalWrite(ahmer,HIGH);
               
      Serial.write('1'); //envoyer le nouvel état de la lampe  
     }  
     else if(data=='2') //si le caractère lu est égale à 0

     {
       digitalWrite(PIN_LED2,HIGH);
        digitalWrite(moutout,LOW);
        digitalWrite(ahmer,LOW);
        //envoyer le nouvel état de la lampe
     
     }   
     // Régler l'intensité de la luminosité de la deuxième lampe branchée sur la broche 11
     else if(data=='3') //si le caractère reçu est égale à 2
     {
       
     }  
    
     else if(data=='4')
     {
 sendTemperatureData() ;

        Serial.write('4'); 
     
     }
      else if(data=='0')
     {
 digitalWrite(PIN_LED2,LOW);

      
     
     }
    
  }
}
