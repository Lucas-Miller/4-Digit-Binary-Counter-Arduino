/************************************************
 *  CS-23301
 *  Lucas Miller
 *  Kent State University 
 *  02/17/2019
 ************************************************/

   
int led1 = 2;         // Represents lefthand side of binary digit
int led2 = 3;         // represents second binary digit
int led3 = 4;         // represents third binary digit
int led4 = 5;         // Represents righthand side binary digit
int joy_sw = A2;      // digital INPUT
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Start....");
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
  pinMode(joy_sw, INPUT);   
  digitalWrite(joy_sw, HIGH);  
  Serial.print("Setup is done\n");
}

void loop() {
  // put your main code here, to run repeatedly:

  
  if(digitalRead(joy_sw) == LOW){
    delay(250);
    counter++;

    int d = counter % 2;
    int c = counter / 2 % 2;
    int b = counter/4 % 2;
    int a = counter/8 % 2;

    digitalWrite(led4, d);
    digitalWrite(led3, c);
    digitalWrite(led2, b);
    digitalWrite(led1, a);
    
    if(counter == 16)
      counter = 0;
      
  } 
   Serial.println(counter);


}




void toggleLED(int argLED_pin){
  digitalWrite(argLED_pin, !digitalRead(argLED_pin));
}
