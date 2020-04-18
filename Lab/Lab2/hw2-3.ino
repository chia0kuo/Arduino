const int LEDs[]={8,9,10,11,12,14,15,16};
const byte SW =6;
int i,j=0;
int delaytime=1000;
boolean buttonstate;

void setup(){
  for (i=0;i<8;i++) {
  pinMode(LEDs[i], OUTPUT);
  }
  pinMode(6,INPUT);
}

void loop() {
  boolean val =digitalRead(6);

if(val){          
  delay(20);
  
    for(i=0;i<8;i++){             //左移
      digitalWrite(LEDs[i],HIGH);
      delay(delaytime);
      digitalWrite(LEDs[i],LOW);
    }

    for(i=0;i<8;i++){
    digitalWrite(LEDs[i],LOW);
    }
    delay(delaytime);
    

    for(i=7;i>=0;i--){             //右移
      digitalWrite(LEDs[i],HIGH); 
      delay(delaytime); 
      digitalWrite(LEDs[i],LOW);
    }

     for(i=0;i<8;i++){
      digitalWrite(LEDs[i],LOW);
    }
    delay(1000);
  
}


  else{                           //ON
  delay(20);
  
  for(i=0;i<8;i++){               //所有LED亮滅兩次
    digitalWrite(LEDs[i],HIGH);
  }
  delay(300);
  for(i=0;i<8;i++){
    digitalWrite(LEDs[i],LOW);
  }
  delay(300);

  for(i=0;i<8;i++){               
    digitalWrite(LEDs[i],HIGH);
  }
  delay(delaytime);
  for(i=0;i<8;i++){
    digitalWrite(LEDs[i],LOW);
  }
  delay(300);
  

  for(j=0;j<8;j++){              //左移八次
    for(i=0;i<8;i++){  
      digitalWrite(LEDs[i],HIGH);
      delay(300);
      digitalWrite(LEDs[i],LOW);
    }

    for(i=0;i<8;i++){
    digitalWrite(LEDs[i],LOW);
    }
    delay(300);
  }

  for(i=0;i<8;i++){               //所有LED亮滅兩次
    digitalWrite(LEDs[i],HIGH);
  }
  delay(300);
  for(i=0;i<8;i++){
    digitalWrite(LEDs[i],LOW);
  }
  delay(300);

  for(i=0;i<8;i++){               
    digitalWrite(LEDs[i],HIGH);
  }
  delay(300);
  for(i=0;i<8;i++){
    digitalWrite(LEDs[i],LOW);
  }
  delay(300);

  for(j=0;j<8;j++){             //右移八次
    for(i=7;i>=0;i--){
      digitalWrite(LEDs[i],HIGH); 
      delay(300); 
      digitalWrite(LEDs[i],LOW);
    }

    for(i=0;i<8;i++){
      digitalWrite(LEDs[i],LOW);
    }
    delay(300);
  }

  }
  
  
}
