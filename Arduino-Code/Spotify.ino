// 'play_pause', 40x40px
const unsigned char play_pause [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x08, 0x00, 0x07, 0xc3, 0xf0, 0x0c, 0x00, 0x07, 0xc3, 0xf0, 0x0f, 0x00, 0x07, 0xc3, 
  0xf0, 0x0f, 0xc0, 0x07, 0xc3, 0xf0, 0x0f, 0xf0, 0x07, 0xc3, 0xf0, 0x0f, 0xf8, 0x07, 0xc3, 0xf0, 
  0x0f, 0xfe, 0x07, 0xc3, 0xf0, 0x0f, 0xff, 0x87, 0xc3, 0xf0, 0x0f, 0xff, 0xe7, 0xc3, 0xf0, 0x0f, 
  0xff, 0xf7, 0xc3, 0xf0, 0x0f, 0xff, 0xf7, 0xc3, 0xf0, 0x0f, 0xff, 0xe7, 0xc3, 0xf0, 0x0f, 0xff, 
  0x87, 0xc3, 0xf0, 0x0f, 0xfe, 0x07, 0xc3, 0xf0, 0x0f, 0xf8, 0x07, 0xc3, 0xf0, 0x0f, 0xf0, 0x07, 
  0xc3, 0xf0, 0x0f, 0xc0, 0x07, 0xc3, 0xf0, 0x0f, 0x00, 0x07, 0xc3, 0xf0, 0x0c, 0x00, 0x07, 0xc3, 
  0xf0, 0x08, 0x00, 0x07, 0xc3, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};



#define BACK            1
#define PLAY            2
#define NEXT            3

#define GREY            0x2363cc

void createCircles(int x, int y){
  Oled.fillCircle(x,y,20,color);
  Oled.fillCircle(x-45,y,15,color);
  Oled.fillCircle(x+45,y,15,color);
}

void createRightButton(int x, int y, int color_c){
  Oled.fillTriangle(64+x, 72+y, 64+x, 72-y, 64+x+16, 72, color_c);
  Oled.fillRect(64+x+16,72-y,3,16,color_c);
}

void createLeftButton(int x, int y, int color_c){
  Oled.fillTriangle(64-x, 72+y, 64-x, 72-y, 64-x-16, 72, color_c);
  Oled.fillRect(64-x-16-2,72-y,3,16,color_c);
}

boolean isPlaying = false;

void createCenterButton(int x, int y, int color_c){
  if (!isPlaying){
    //Oled.fillTriangle(x-9, y+11, x-9, y-11, x+13, y, color_c);
    Oled.drawBitmap(64-20, 72-20, play_pause, 40, 40, color_c);
  }
  else{
    //Oled.fillRect(x-6-2,y-10,5,22, color_c);
    //Oled.fillRect(x+6-2,y-10,5,22, color_c);
    Oled.drawBitmap(64-20, 72-20, play_pause, 40, 40, color_c);
  }
}

void createMargin(int center_y, int separation){
  Oled.fillRect(0,center_y+separation,128,4,color);
  Oled.fillRect(0,center_y-separation,128,4,color);
}

void pulseButton(int op = 0){
  int newx = 36;
  int newy = 8;
  int color_l = BLACK;
  int color_m = BLACK;
  int color_r = BLACK;
  
  if(op == BACK){ color_l = GREY;}
  if(op == PLAY){ color_m = GREY;}
  if(op == NEXT){ color_r = GREY;}
  
  createCenterButton(64,72, color_m);
  createLeftButton(newx,newy, color_l);
  createRightButton(newx,newy, color_r);

  delay(50);
}

void initializeSpotify(){
  Oled.fillScreen(BLACK);
  drawedge(selected);
  createMargin(72,33);
  createCircles(64,72);
  //Oled.fillRoundRect(-5, 35, 138, 75, 105,BLACK);
}

void spotify(){
  pinMode(32, OUTPUT);
  digitalWrite(32, HIGH);
  
  Oled.fillScreen(BLACK);
  
  initializeSpotify();

  sendBLE("/play");

  isPlaying = true;
  
  pulseButton();
  
  
  waitpls:
  wait_for_any_button();

  //// BOTTOM BUTTON
  if (digitalRead(b_button) == LOW){
    while (!digitalRead(b_button)){
        pulseButton(BACK);
      }
    pulseButton();
    sendBLE("/lastSong"); 
    delay(1000); 
    goto waitpls;
  }


  //// MIDDLE BUTTON
  else if (digitalRead(m_button) == LOW){
    
    int wait = 0;
      
    while (digitalRead(m_button) ==  LOW){
        pulseButton(PLAY);
        if (wait >= 200){
          if(makeSound){buzzer();}
          goto endpls;
        }
        delay(10);
        wait += 10;
     }

    if (isPlaying){
      sendBLE("/pause"); 

    }
    else{
      sendBLE("/play"); 
    }
    
    Oled.fillCircle(64,72,20,color);
    isPlaying = !isPlaying;
    pulseButton();
    goto waitpls;
  }



  //// TOP BUTTON
  else if (digitalRead(t_button) == LOW){
    while (!digitalRead(t_button)){
        pulseButton(NEXT);
      }
    pulseButton();
    sendBLE("/nextSong"); 
    delay(1000);  
    goto waitpls;
  }

  endpls:
  Serial.println("end spotify");
  
}
