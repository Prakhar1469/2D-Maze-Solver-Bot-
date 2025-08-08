// final sketch to be improved
int const IN1 = 10;
int const IN2 = 9;
int const IN3 = 5;
int const IN4 = 3;
int const SL=12;
int const SM=7;
int const SR=2;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(SL,INPUT);
  pinMode(SM,INPUT);
  pinMode(SR,INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void blink() {
  while(1){
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(500);                      // wait for a second
  }
}

void moveForward(){
  analogWrite(IN1,55);
  analogWrite(IN2,0);
  analogWrite(IN3,55);
  analogWrite(IN4,0);
}

  
void moveBackward(){
analogWrite(IN1,0);
analogWrite(IN2,55);
analogWrite(IN3,0);
analogWrite(IN4,55);
}
void moveRight(){
analogWrite(IN1,55);
analogWrite(IN2,0);  
analogWrite(IN3,0);
analogWrite(IN4,55);
}

void moveRight1(){
analogWrite(IN1,83);
analogWrite(IN2,0);  
analogWrite(IN3,0);
analogWrite(IN4,83);
}

void moveLeft(){
analogWrite(IN1,0);
analogWrite(IN2,55);
analogWrite(IN3,55);
analogWrite(IN4,0);
}

void stop(){
analogWrite(IN1,0);
analogWrite(IN2,0);
analogWrite(IN3,0);
analogWrite(IN4,0);
}

void loop() {
  // put your main code here, to run repeatedly:
    int l=digitalRead(SL);
    int m=digitalRead(SM);
    int r=digitalRead(SR);

    // straight
    if(l==0 && m==1 && r==0){
    moveForward();
    delayMicroseconds(10);
    }
  
    //left
    else if(l==1 && m==0 && r==0){
    moveLeft();  // while moving forward 
    delay(900); //900 // 750 //650 // before speed change = 650
    moveForward();
    delay(550);//400 // bsc 350
    }
    //right
    else if((l==0 && m==0 && r==1)){
    moveRight();  // while moving forward 
    delayMicroseconds(5); // 1ms original
    }
  
    else if(l==1 && m==1 && r==0){
    
    moveLeft();
    delay(900);// 900
    moveForward();
    delay(550);
    // delayMicroseconds(50);
    }

    else if(l==1 && m==0 && r==1){
      moveLeft();
      delay(900);// 900 // 550 // 550
      moveForward();
      delay(550);//500 // 400
    }

    else if(l==1 && m==1 && r==1){
    // moveLeft();
    // delay(700);
     moveLeft();
     delay(900); // time // 100

    //  if (l == 1 && m == 1 && r == 1)
    //     {
    //       // Serial.println("ËND OF MAZE");
    //       stop();
    //       blink();
    //     }
    //  else
    //     {
    //     //  Serial.println("FOUR WAY INTERSECTION");
    //      moveLeft();
    //      delay(100);
    //     }
    }
    
    else if(l==0 && m==1 && r==1){ // LSRB
     moveForward();
     delay(1);
    }

    else if(l==0 && m==0 && r==0)
   {
      // moveForward();
      // delay(40);
      moveRight();
      delay(60);//10
       //if(l == 0 && m == 0 && r == 0)
       //{
        //moveRight();
       //}
       //else if(l==0 && m==1 && r==0)
       //{
        //moveForward();
        //delayMicroseconds(10);
       //}
    // moveForward();
    // delay(150);
    // int i = 1; doesnt work
    // while(i == 1){
    //   moveForward();
    //   delay(1);
    //   i++;
    // }
    // moveForward();
    // delay(2000);
    
   }
}

