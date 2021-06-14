int xpos = 0;
int ypos = 20;

int xball = 64;
int yball = 64;
float slope = 0.5;
int b = 96;
bool opp = false;

int level=0;
int life = 1;
bool lose = false;
int dcolor = WHITE;

boolean isSoundOn(){
  return true;
}

void printline(){
  //print line with 20 squares starting from y = 20
  for (int y_delta = 20; y_delta < 125; y_delta += 10){
    Oled.drawLine(64, y_delta,64, y_delta + 3, dcolor);
  }
  Oled.fillRect(7,20,4,128,BLACK);
}

void printbase(bool down = true){
  if(ypos>=20 && ypos<=103){
    if (down){
      Oled.fillRect(5,ypos-5,2,25,BLACK);
      }
  else{
    Oled.fillRect(5,ypos+5,2,25,BLACK);
    }
  Oled.fillRect(5,ypos,2,25,dcolor);  
  }
  else{
    if (down){ypos = 103;}
    else{ypos = 20;}
  }
}

void printball(int x = 10, int y = 25, int col = WHITE){
  Oled.fillRect(x,y,5,5,col);
}

void printTrajectory(){

  checkBounce();

  int c = 1;
  if (opp){c = -1;}

  printball(xball-c,yball, BLACK);
  
  yball = (-slope*xball)+b;

  printball(xball,yball);
  printbase();
  
  xball += c;

  
}

void bounceSound(){
  ledcWriteTone(Channel, 700);
  delay(5);
  ledcWriteTone(Channel, 0);
}

void checkBounce(){
  if (xball>124){
    if (slope<=0){
      b = 124+b;
    }
    else{
      b = -(124-b);
    }
    bounceSound();
    slope *= -1;
    opp = !opp;
  }
  if (xball<5){
    if(ypos>yball | yball>ypos+20){
      loseLife();
      xball = 64;
      yball = 64;
      b = 96;
      opp = false;
      life+=1;
      printball(xball,yball, BLACK);
      printbase();
      ledcWriteTone(Channel, 700);
      delay(5);
      ledcWriteTone(Channel, 500);
      delay(5);
      ledcWriteTone(Channel, 300);
      delay(5);
      ledcWriteTone(Channel, 0);
    }
    else{
      bounceSound();
      printbase();
      newLevel();
      slope *= -1;
      opp = !opp;
    }
  }
  if (yball <24){
    b= ((b/2)-24)*-2;
    slope *= -1;
    bounceSound();
  }
  if (yball >124){
    if(slope<=0){
      b = (xball/2)+124;
      slope *=-1;
    }
    else{
      Serial.println(b);
      b = b-xball-4;
      Serial.println(xball);
      Serial.println(b);
      Serial.println("----");
      slope *=-1;
    }
    bounceSound();
  }
}

void printscore(){
  Oled.setFont();
  dcolor= WHITE;
  Oled.setTextColor(dcolor);
  Oled.setCursor(2,2);
  Oled.print("Lvl.");
  Oled.setCursor(30,2);
  Oled.print(level);
  Oled.fillCircle(100,4,2,GREEN);
  Oled.fillCircle(108,4,2,GREEN);
  Oled.fillCircle(116,4,2,GREEN);
}

void newLevel(){

  if(dcolor==WHITE){
    
  Oled.setTextColor(BLACK);
  Oled.setCursor(30,2);
  Oled.print(level);

  Oled.setTextColor(dcolor);
  Oled.setCursor(30,2);
  Oled.print(level+1);

  level+=1;
  }
}

void loseLife(){
  for (int i =0;i<life; i++){
    Oled.fillCircle(100+(i*8),4,2,RED);
  }
  if (life ==3){
    dcolor = RED;
    Oled.setTextColor(dcolor);
    Oled.setCursor(2,2);
    Oled.print("Lvl.");
    Oled.setCursor(30,2);
    Oled.print(level);
    printbase();
  }
}

void ndelay(){
  if (50-(level*5)<=1){
    delay(5);
  }
  else{
    delay(50-(level*5));
  }
}



void pong(){
  pinMode(32, OUTPUT);
  digitalWrite(32, HIGH);
  Oled.fillScreen(BLACK);
  printscore();
  printline();
  printbase();
  delay(1000);
  
  printTrajectory();
  ndelay();
  
  waiting_main:
    while ((digitalRead(b_button) ==  HIGH) && (digitalRead(m_button) ==  HIGH) && (digitalRead(t_button) ==  HIGH)){
      ndelay();
      printTrajectory();
      printline();
    }
    
    //// BOTTOM BUTTON
    if (digitalRead(b_button) == LOW){
      ypos += 5;
      printbase(true);
      printTrajectory();
      ndelay();
      goto waiting_main;
    }
  
  
    //// MIDDLE BUTTON
    else if (digitalRead(m_button) == LOW){
      xpos = 0;
      ypos = 20;
  
      xball = 64;
      yball = 64;
      slope = 0.5;
      b = 96;
      opp = false;
  
      level=0;
      life = 1;
      lose = false;
  
      int wait = 0;
      
      while (digitalRead(m_button) ==  LOW){
        if (wait >= 1000){
          if(makeSound){buzzer();}
          goto end_pong;
        }
        delay(10);
        wait += 10;
      }
  
      if (wait<1000){
        Oled.fillScreen(BLACK);
        printscore();
        printline();
        printbase();
        delay(1000);
  
        printTrajectory();
        ndelay();
        
        goto waiting_main;
    
      }
      
    }
  
  
  
    //// TOP BUTTON
    else if (digitalRead(t_button) == LOW){
      ypos -= 5;
      printbase(false);
      printTrajectory();
      ndelay();
      goto waiting_main;
    }
   end_pong:
    Serial.println("end pong");
}
