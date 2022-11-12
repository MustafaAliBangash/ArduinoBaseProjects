int analogInpin = A0;
int ledPin1 = 3;
int ledPin2 = 5;

int sensorValue = 0;
int outPutvalue = 0;
 
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);

}

void loop() {
  //put your main code here, to run repeatedly:
  sensorValue = analogRead(analogInpin); 
 // Serial.print(" SensorValue = ");
  //Serial.println(sensorValue);
delay(30);
    outPutvalue = map(sensorValue,0 , 1024, 0, 255);
  Serial.print("Output value = ");
  Serial.println(outPutvalue);

 if(outPutvalue == 127){
  analogWrite(ledPin1, LOW);
  analogWrite(ledPin2, LOW); 
 }else if(outPutvalue >= 0 && outPutvalue <= 125){
    outPutvalue = map(sensorValue,0 , 512,255 ,0);
   analogWrite(ledPin2,LOW);
  analogWrite(ledPin1, outPutvalue);
   
 }else if(outPutvalue >=129 && outPutvalue <=255){
    outPutvalue = map(sensorValue,0 , 512, 0, 255);
 		analogWrite(ledPin1, LOW);
   		analogWrite(ledPin2, outPutvalue);
 }
  
}