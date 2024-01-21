// C++ code
#include<Servo.h>

int servoPin = 13; 
int inputPin = 2; 
int val = 0; 
int count = 0;

Servo sMotor;

void setup() { 
	pinMode(inputPin, INPUT);
	pinMode(servoPin, OUTPUT);
	sMotor.attach(servoPin);
	sMotor.write(0); 
	Serial.begin(9600);
}

void loop() {
	val = digitalRead(inputPin); // read input value
	if(val==HIGH) {
    	delay(2000);
    	count++;
    	Serial.println(count);
	}
  	if (val == HIGH && count%2==0) { // check if the input is HIGH
      for(int i = 0; i <= 90; i++) {
        sMotor.write(i);
        delay(50); 
      }
          
      Serial.print("Inside if : ");
      Serial.println(count);
      count = 0;
      delay(1000);
 		
	}
else {
    digitalWrite(servoPin,LOW);
	} 
}
