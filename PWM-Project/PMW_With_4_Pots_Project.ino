int analogInpin1=  A0;
int analogInpin2 = A1;
int ledPin1 = 3;
int ledPin2 = 5;
int ledPin3 = 6;
int ledPin4 = 9;

int sensorValue1 = 0;
int outPutvalue1 = 0;
int sensorValue2 = 0;
int outPutvalue2 = 0;
 
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);

}

void loop() {
  //put your main code here, to run repeatedly:
  sensorValue1 = analogRead(analogInpin1); 
 // Serial.print(" SensorValue = ");
  //Serial.println(sensorValue);
delay(30);
    outPutvalue1 = map(sensorValue1,0 , 1024, 0, 255);
  // Serial.print("Output value1 = ");
  // Serial.println(outPutvalue1);

 if(outPutvalue1 == 127){
  analogWrite(ledPin1, LOW);
  analogWrite(ledPin2, LOW); 
 }else if(outPutvalue1 >= 0 && outPutvalue1 <= 125){
    outPutvalue1 = map(sensorValue1,0 , 512,255 ,0);
   analogWrite(ledPin2,LOW);
  analogWrite(ledPin1, outPutvalue1);
   
 }else if(outPutvalue1 >=129 && outPutvalue1 <=255){
    outPutvalue1 = map(sensorValue1,0 , 512, 0, 255);
 		analogWrite(ledPin1, LOW);
   		analogWrite(ledPin2, outPutvalue1);
 }

// delay(1000);

  sensorValue2 = analogRead(analogInpin2); 
 // Serial.print(" SensorValue = ");
  //Serial.println(sensorValue);
delay(30);
    outPutvalue2 = map(sensorValue2,0 , 1024, 0, 255);
  Serial.print("Output value2 = ");
  Serial.println(outPutvalue2);

 if(outPutvalue2 == 127){
  analogWrite(ledPin3, LOW);
  analogWrite(ledPin4, LOW); 
 }else if(outPutvalue2 >= 0 && outPutvalue2 <= 125){
    outPutvalue2 = map(sensorValue2,0 , 512,255 ,0);
   analogWrite(ledPin4,LOW);
  analogWrite(ledPin3, outPutvalue2);
   
 }else if(outPutvalue2 >=129 && outPutvalue2 <=255){
    outPutvalue2 = map(sensorValue2,0 , 512, 0, 255);
 		analogWrite(ledPin3, LOW);
   		analogWrite(ledPin4, outPutvalue2);
 }
  
}