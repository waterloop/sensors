 #define outputA 6
 #define outputB 7

 int aState;
 int bState;
 int aLastState;
 
 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   
   Serial.begin (250000);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);
 } 
 
 void loop() { 
  float counter = 0.0;
  int rpm = 0;
  float startTime = millis();
  while(millis()-startTime < 1000){
    aState = digitalRead(outputA); // Reads the "current" state of the outputA

   if(!aLastState && aState){
    counter++;
   }
   aLastState = aState; // Updates the previous state of the outputA with the current state
  }  
  rpm = computeRpm(counter);
  Serial.println(rpm);
 }

 int computeRpm(float counter){
  float cycles = counter/400.0;
  return cycles*60;
 }
