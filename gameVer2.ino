int temp;
int currentStep = 0;
int gameWON=0;
int level=1;
int sequence[] = {1,2,4,3};
int sequence2[] = {1,2,4,3,4,1,3,2};
int sequence3[]={1,2,4,3,4,1,3,2,4,1,3,1,2,1};
int LED1=8;
int LED2=9;
int LED3=10;
int LED4=11;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  digitalWrite(2, HIGH);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
//////////////////////////////////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < sizeof(sequence) / sizeof(sequence[0]); i++) {
    if (sequence[i] != -1) {
      Serial.print(sequence[i]);
      if (sequence[i]==1){
        
        digitalWrite(LED1, LOW);
        delay(700);
        digitalWrite(LED1, HIGH);

      }else if(sequence[i]==2){
        
        digitalWrite(LED2, LOW);
        delay(700);
        digitalWrite(LED2, HIGH);
      }else if(sequence[i]==3){
        
        digitalWrite(LED3, LOW);
        delay(700);
        digitalWrite(LED3, HIGH);
      }else if(sequence[i]==4){
        
        digitalWrite(LED4, LOW);
        delay(700);
        digitalWrite(LED4, HIGH);
      }
    }
  }

  

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}
int buttons(){
  if(digitalRead(8)==0){
    return 1;
  }else if(digitalRead(8)==0){
    return 2;
  }else if(digitalRead(10)==0){
    return 3;
  }else if(digitalRead(11)==0){
    return 4;
  }
}
void display(){
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);

    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
      
      
      digitalWrite(LED1, LOW);
      delay(200);
      digitalWrite(LED2, LOW);
      delay(200);
      digitalWrite(LED3, LOW);
      delay(200);
      digitalWrite(LED4, LOW);
      delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int inputNumber=0;
  int i=0;
  int finale=0;
  int inputTaken=0;
  /*int button1=0;
  int button2=0;
  int button3=0;
  int button4=0;*/
  if(digitalRead(8)==1 && digitalRead(9)==1 && digitalRead(10)==1 && digitalRead(11)==1 && gameWON==0 ){
    Serial.println("WAITING");

  }else
  if(digitalRead(8)==0 && digitalRead(9)==1 && digitalRead(10)==1 && digitalRead(11)==1  )
  { 
    //button1=1;
    inputNumber=1;
    inputTaken=1;
  }else if(digitalRead(8)==1 && digitalRead(9)==0 && digitalRead(10)==1 && digitalRead(11)==1  )
  {
    //button2=1;
    inputNumber=2;
    inputTaken=1;
  }else if(digitalRead(8)==1 && digitalRead(9)==1 && digitalRead(10)==0 && digitalRead(11)==1  )
  {
    //button3=1;
    inputNumber=3;
    inputTaken=1;
  }else if(digitalRead(8)==1 && digitalRead(9)==1 && digitalRead(10)==1 && digitalRead(11)==0  ){
    //button4=1;
    inputNumber=4;
    inputTaken=1;
  }else if(gameWON==0){
    Serial.print("Error");
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  if (level==1 && inputTaken==1 && inputNumber == sequence[currentStep] && gameWON==0) {
      currentStep++;
      Serial.println("Correct!");
      digitalWrite(2, LOW);
      delay(250);
      digitalWrite(2, HIGH);
    } else if(inputTaken==1 && level==1) {
      // Handle incorrect input
      Serial.println("Incorrect input!");
      gameWON=2;
      // You can reset the game or take other actions here
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      
      currentStep = 0;
    }
    delay(10); // Debounce delay

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(level==2 && gameWON==1){
    delay(5000);
    digitalWrite(2, HIGH);
    for (int i = 0; i < sizeof(sequence2) / sizeof(sequence2[0]); i++) {
    if (sequence2[i] != -1) {
      Serial.print(sequence2[i]);
      if (sequence2[i]==1){
        
        digitalWrite(LED1, LOW);
        delay(700);
        digitalWrite(LED1, HIGH);

      }else if(sequence2[i]==2){
        
        digitalWrite(LED2, LOW);
        delay(700);
        digitalWrite(LED2, HIGH);
      }else if(sequence2[i]==3){
        
        digitalWrite(LED3, LOW);
        delay(700);
        digitalWrite(LED3, HIGH);
      }else if(sequence2[i]==4){
        
        digitalWrite(LED4, LOW);
        delay(700);
        digitalWrite(LED4, HIGH);
      }
      gameWON=0;
      
    }
  }
  }
  
  
  if (level==2 && inputTaken==1 && inputNumber == sequence2[currentStep] && gameWON==0) {
      currentStep++;
      Serial.println("Correct!");
      digitalWrite(2, LOW);
      delay(250);
      digitalWrite(2, HIGH);
    } else if(inputTaken==1 && level==2) {
      // Handle incorrect input
      Serial.println("Incorrect input!");
      gameWON=2;
      // You can reset the game or take other actions here
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      
      currentStep = 0;
    }
    delay(10); // Debounce delay
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  if(level==3 && gameWON==1){
    delay(5000);
    digitalWrite(2, HIGH);
    for (int i = 0; i < sizeof(sequence3) / sizeof(sequence3[0]); i++) {
    if (sequence3[i] != -1) {
      Serial.print(sequence3[i]);
      if (sequence3[i]==1){
        
        digitalWrite(LED1, LOW);
        delay(700);
        digitalWrite(LED1, HIGH);

      }else if(sequence3[i]==2){
        
        digitalWrite(LED2, LOW);
        delay(700);
        digitalWrite(LED2, HIGH);
      }else if(sequence3[i]==3){
        
        digitalWrite(LED3, LOW);
        delay(700);
        digitalWrite(LED3, HIGH);
      }else if(sequence3[i]==4){
        
        digitalWrite(LED4, LOW);
        delay(700);
        digitalWrite(LED4, HIGH);
      }
      gameWON=0;
     
    }
  }
  }
  
  
  if (level==3 && inputTaken==1 && inputNumber == sequence3[currentStep] && gameWON==0) {
      currentStep++;
      Serial.println("Correct!");
      digitalWrite(2, LOW);
      delay(250);
      digitalWrite(2, HIGH);
    } else if(inputTaken==1 && level==3) {
      // Handle incorrect input
      Serial.println("Incorrect input!");
      gameWON=2;
      // You can reset the game or take other actions here
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      
      currentStep = 0;
    }
    delay(10); // Debounce delay
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (currentStep == sizeof(sequence) / sizeof(sequence[0]) && gameWON==0 && level==1) {
          
  Serial.println("\tCONGRATULATIONS\n\t You win level 1.\n Still wanna play press r!!");
  gameWON=1;
  level++;
  currentStep = 0;
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);

  }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (currentStep == sizeof(sequence2) / sizeof(sequence2[0]) && gameWON==0 && level==2) {
          
  Serial.println("\tCONGRATULATIONS\n\t You win level 2.\n Still wanna play press r!!");
  gameWON=1;
  level++;
  currentStep = 0;
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);

  }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (currentStep == sizeof(sequence3) / sizeof(sequence3[0]) && gameWON==0 && level==3) {
          
  Serial.println("\tCONGRATULATIONS\n\t You win level3.\n Still wanna play press r!!");
  gameWON=1;
  level++;
  currentStep = 0;
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);

  }
    
  
}
