#include <SoftwareSerial.h> 
#include <TinyGPS.h> 

int state = 1; 
const int btnPin = 9; 
const int ledPin = 10; 
float gpslat, gpslon; 

TinyGPS gps; 
SoftwareSerial sgps(4, 5); 
SoftwareSerial sgsm(2, 3); 

void setup() 
{ 
  Serial.begin(9600); 
  sgsm.begin(9600); 
  sgps.begin(9600); 
  pinMode(10,OUTPUT); 
  pinMode(9, INPUT); 
} 
void loop()  
{ 
  sgps.listen(); 
  while (sgps.available()) 
  { 
    int c = sgps.read(); 
    if(gps.encode(c)) 
    { 
      gps.f_get_position(&gpslat, &gpslon); 
    } 
  } 
  if (digitalRead(btnPin) == HIGH) 
  { 
    digitalWrite(ledPin,HIGH); 
    delay(3000); 
    digitalWrite(ledPin,LOW); 
    sgsm.listen(); 
    sgsm.print("\r"); 
    delay(1000); 
    sgsm.print("AT+CMGF=1\r"); 
    delay(1000); 
    /*Replace XXXXXXXXXX to 10 digit mobile number & ZZ to 2 digit country code*/ 
    sgsm.print("AT+CMGS=\"+ZZXXXXXXXXXX\"\r"); 
    delay(1000); 
    sgsm.print("https://www.google.com/maps/?q="); 
    sgsm.print("ALERT HELP NEEDED"); 
    sgsm.print(gpslat, 6); 
    sgsm.print(","); 
    sgsm.print(gpslon, 6);      
    delay(1000); 
    sgsm.write(0x1A); 
    delay(1000); 
    state=1;
    Serial.println(gpslat); 
    Serial.println(gpslon); 
    digitalWrite(btnPin, LOW); 
  } 
  if (digitalRead(btnPin) == LOW) 
  { 
    state = 0; 
  }
  delay(100);
}
