const int _pin=8;
const int _pin2=7;
const int _pin3=6;
const int _pin4=5;
const float window = 10;
const float width = 100;

void setup() {
  Serial.begin(9600);    //initializes display on Serial Monitor at 9600 baud
}

void loop() {
  float distance = 0;
  
  //Sensor 1 - door
  float trigger1 = ping(_pin, width);
  Serial.print(trigger1);
  Serial.print(" ");
  float trigger2 = ping(_pin2, width);
  Serial.print(trigger2);
  Serial.print(" ");
  float trigger3 = ping(_pin3, width);
  Serial.print(trigger3);
  Serial.print(" ");
  float trigger4 = ping(_pin4, width);
  Serial.print(trigger4);
  Serial.print(" ");

  distance = distance - trigger4; //Always subtract the first sensor, then check others
  if (distance < 0){
    distance = distance - trigger3;
    if (distance < -1){
      distance = distance - trigger2;
      if (distance < -2){
        distance = distance - trigger1;
      }
    }
  } else if (trigger3 == 1) {
    distance = distance - trigger3;
    if(distance < 0){
      distance = distance - trigger2;
      if (distance < -1){
        distance = distance - trigger1;
      }
    }    
  }
  //Serial.print("Distance from counter: ");
  Serial.println(abs(distance));
  
  delay(50);

}

float ping(int sensor, float width){
  int triggered = 0;
  pinMode(sensor, OUTPUT);
  digitalWrite(sensor, LOW);
  delayMicroseconds(2);
  
  digitalWrite(sensor, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor,LOW);
  
  pinMode(sensor,INPUT);
  float duration = pulseIn(sensor,HIGH);
  float RangeInCentimeters = duration/29/2; 
  if (RangeInCentimeters < width){
    triggered = 1;   
  } 
  return triggered;  
}


