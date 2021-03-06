// 'rotate', 30x30px
const unsigned char rotate [] PROGMEM = {
  0x00, 0x1f, 0xe0, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x31, 0xff, 0xfe, 0x00, 0x3f, 0xe0, 0x1f, 0x80, 
  0x3f, 0x80, 0x07, 0xc0, 0x3e, 0x00, 0x01, 0xe0, 0x3f, 0x03, 0x00, 0xe0, 0x3f, 0x87, 0x80, 0x70, 
  0x7f, 0x8f, 0xc0, 0x78, 0x60, 0x1f, 0xe0, 0x38, 0x00, 0x3f, 0xf0, 0x38, 0x00, 0x7f, 0xf8, 0x1c, 
  0x00, 0xff, 0xfc, 0x1c, 0x01, 0xff, 0xfe, 0x1c, 0x03, 0xff, 0xff, 0x1c, 0xe1, 0xff, 0xfe, 0x1c, 
  0xe0, 0xff, 0xfc, 0x1c, 0xe0, 0x7f, 0xf8, 0x1c, 0xe0, 0x3f, 0xf0, 0x1c, 0x70, 0x1f, 0xe0, 0x38, 
  0x70, 0x0f, 0xc0, 0x38, 0x78, 0x07, 0x80, 0x78, 0x38, 0x03, 0x00, 0x70, 0x1c, 0x00, 0x00, 0xe0, 
  0x1e, 0x00, 0x01, 0xe0, 0x0f, 0x80, 0x07, 0xc0, 0x07, 0xe0, 0x1f, 0x80, 0x01, 0xff, 0xfe, 0x00, 
  0x00, 0xff, 0xfc, 0x00, 0x00, 0x1f, 0xe0, 0x00
};

// 'speaker', 28x28px
const unsigned char speaker [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x3c, 0x0c, 0x00, 
  0x00, 0x7c, 0x0e, 0x00, 0x00, 0x7c, 0x07, 0x00, 0x00, 0xfc, 0x03, 0x80, 0x01, 0xfc, 0x01, 0xc0, 
  0x03, 0xfc, 0x70, 0xe0, 0xff, 0xfc, 0x38, 0x60, 0xff, 0xfc, 0x1c, 0x60, 0xff, 0xfc, 0x0c, 0x70, 
  0xff, 0xfc, 0x0c, 0x30, 0xff, 0xfc, 0x0e, 0x30, 0xff, 0xfc, 0x0e, 0x30, 0xff, 0xfc, 0x0c, 0x30, 
  0xff, 0xfc, 0x0c, 0x70, 0xff, 0xfc, 0x1c, 0x60, 0xff, 0xfc, 0x38, 0x60, 0x03, 0xfc, 0x70, 0xe0, 
  0x01, 0xfc, 0x01, 0xc0, 0x00, 0xfc, 0x03, 0x80, 0x00, 0x7c, 0x07, 0x00, 0x00, 0x7c, 0x0e, 0x00, 
  0x00, 0x3c, 0x0c, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


// 'diagonal', 30x30px
const unsigned char diagonal [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x03, 0xc0, 
  0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x1c, 0x00, 
  0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0xe0, 0x00, 
  0x00, 0x01, 0xe0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x07, 0x00, 0x00, 
  0x00, 0x0f, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 
  0x00, 0x70, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 
  0x03, 0x80, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// 'mute_speaker', 28x28px
const unsigned char m_speaker [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 
  0x00, 0x7c, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 
  0x03, 0xfc, 0xe1, 0xc0, 0xff, 0xfc, 0x73, 0x80, 0xff, 0xfc, 0x73, 0x80, 0xff, 0xfc, 0x3f, 0x00, 
  0xff, 0xfc, 0x1e, 0x00, 0xff, 0xfc, 0x1e, 0x00, 0xff, 0xfc, 0x1e, 0x00, 0xff, 0xfc, 0x3f, 0x00, 
  0xff, 0xfc, 0x73, 0x80, 0xff, 0xfc, 0x73, 0x80, 0xff, 0xfc, 0xe1, 0xc0, 0x03, 0xfc, 0x00, 0x00, 
  0x01, 0xfc, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 
  0x00, 0x3c, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define GREY            0x2363cc

int posx_s[4]={35, 93, 35, 93};
int posy_s[4]={37, 37, 91, 91};

int colorSetting[4]={WHITE,BLUE,YELLOW,YELLOW};

void chooseTime(int x, int y){
  Oled.fillCircle(x,y,19,colorSetting[0]);
  if (EEPROM.read(0)){

    Oled.fillRect(x,y-2,15,4,BLACK);

    Oled.fillRect(x-2,y-13,4,15,BLACK);
    
  }
  else{
    Oled.setFont(&Lato_Bold_24);
    Oled.setTextColor(BLACK);
    drawCentreString("12",x-1,y+9);
  }
}

void chooseSleep(int x, int y){
  if (EEPROM.read(1)){
    Oled.drawBitmap(96-17,32-9,rotate, 30, 30, WHITE);
  }
  else{
    Oled.drawBitmap(96-17,32-9, rotate, 30, 30, BLACK);
  }
}

void chooseColor(int x, int y, int color, int i_color = 0){
  //if (EEPROM.read(2) > 6){EEPROM.write(2,0);EEPROM.commit();}
  Oled.fillCircle(35, 91, 19, colorColor[EEPROM.read(2)]);
}

void chooseSound(int x, int y, int color, boolean isOn){
  Oled.fillCircle(posx_s[3],posy_s[3],19, YELLOW);
  if (EEPROM.read(3)){
    Oled.drawBitmap(96-16,96-18, speaker, 28, 28, BLACK);
  }
  else{
    Oled.drawBitmap(96-16,96-18, m_speaker, 28, 28, BLACK);
  }
}

void select_setting(int number){
  switch (number){
    case 0:
      if (EEPROM.read(0)){EEPROM.write(0, 0);}
      else{EEPROM.write(0, 1);}
      EEPROM.commit();
      updateVars();
      chooseTime(35,37);
      break;
    case 1:
      if (EEPROM.read(1)){EEPROM.write(1, 0);}
      else{EEPROM.write(1, 1);}
      EEPROM.commit();
      updateVars();
      chooseSleep(posx_s[1]-15,posy_s[1]-15);
      break;
    case 2:
      if (EEPROM.read(2) > 6){EEPROM.write(2,0);EEPROM.commit();}
      else{EEPROM.write(2, EEPROM.read(2)+1);}
      EEPROM.commit();
      updateVars();
      chooseColor(32-15,96-15,WHITE,false);
      break;
    case 3:
      if (EEPROM.read(3)){EEPROM.write(3, 0);}
      else{EEPROM.write(3, 1);}
      EEPROM.commit();
      updateVars();
      chooseSound(posx_s[3]-15,posy_s[3]-15,WHITE,false);
      break;
  }
  
}

void chooseSetting(int bitmap, int x, int y, int color, boolean BIG = false){
  switch (bitmap){
    case 0:
      chooseTime(x,y);
      break;
    case 1:
      chooseSleep(x-15,y-15);
      break;
    case 2:
      chooseColor(x-15,y-15,color,BIG);
      break;
    case 3:
      chooseSound(x-15,y-15,color,BIG);
      break;
  }
}


void drawSettings(){

  for (int i=0; i<4; i++){
    if (i!=2){
      Oled.fillCircle(posx_s[i],posy_s[i],19,colorSetting[i]);
    }
    else{
      Oled.fillCircle(posx_s[i],posy_s[i],19,colorColor[EEPROM.read(2)]);
    }
    chooseSetting(i,posx_s[i],posy_s[i], WHITE, false);
  }
    
}

void hoverSetting(int current, int prev = 0){
  int c_color = colorSetting[current];
  int p_color = colorSetting[prev];

  if (current == 2){ c_color = colorColor[EEPROM.read(2)];  } 
  if (prev == 2){ p_color = colorColor[EEPROM.read(2)];  } 

  Oled.fillCircle(posx_s[prev],posy_s[prev],23,BLACK);
  Oled.fillCircle(posx_s[prev],posy_s[prev],21,p_color);
  chooseSetting(prev,posx_s[prev],posy_s[prev],p_color);

  Oled.fillCircle(posx_s[current],posy_s[current],23,color);
  Oled.fillCircle(posx_s[current],posy_s[current],21,BLACK); 

  Oled.fillCircle(posx_s[current],posy_s[current],19,c_color); 
  chooseSetting(current,posx_s[current],posy_s[current],c_color);
}

void hoverClick(int current){
  int c_color = colorSetting[current];

  if (current == 2){ c_color = colorColor[EEPROM.read(2)];  } 

  Oled.fillCircle(posx_s[current],posy_s[current],23,color);
  Oled.fillCircle(posx_s[current],posy_s[current],21,BLACK); 

  Oled.fillCircle(posx_s[current],posy_s[current],19,c_color); 
  chooseSetting(current,posx_s[current],posy_s[current],c_color);
}

void selectSetting(int current){
  int c_color = colorSetting[current];
  if (current == 2){ c_color = colorColor[EEPROM.read(2)];  } 
  Oled.fillCircle(posx_s[current],posy_s[current],23,BLACK);
  Oled.fillCircle(posx_s[current],posy_s[current],21,color); 
  Oled.fillCircle(posx_s[current],posy_s[current],19,c_color);
  chooseSetting(current,posx_s[current],posy_s[current],c_color);
}

void updateVars(){
  color = colorColor[EEPROM.read(2)];
  isVintage = EEPROM.read(0);
  makeSound = EEPROM.read(3);
  wakeRotation = EEPROM.read(1);   
}

void settings(){
  int index = 0;
  
  Oled.fillScreen(GREY);
  Oled.fillRect(3,3,122,122,BLACK);
  
  //Oled.fillCircle(0,0,30,RED);
  beg_menuu:
  Serial.print("nada");

  menuu:
    hoverSetting(index);
    drawSettings();
    
    wait_middle();
  
  waiting:
    wait_for_any_button();
  
  //// BUTTOM BUTTON
    if (digitalRead(b_button) ==  LOW){
      wait_bottom();
      if (index<3){
        index+=1;
        hoverSetting(index, index-1);
      }
      else{
        index=0;
        hoverSetting(index,3);
      }
      goto waiting;
    }
    //// END OF BOTTOM BUTTON
  
  
    //// TOP BUTTON
    else if (digitalRead(t_button) ==  LOW){
      wait_top();
      if (index>0){
        index-=1;
        hoverSetting(index, index+1);
      }
      else{
        index=3;
        hoverSetting(index,0);
      }
      goto waiting;
    }
  
    //// MIDDLE BUTTON
    else if (digitalRead(m_button) ==  LOW){

      wait = 0;
      while (digitalRead(m_button) ==  LOW){
        if (wait >= 1000){
          if(makeSound){buzzer();}
          goto end_menu;
        }
        delay(10);
        wait += 10;
      }

      select_setting(index);
      selectSetting(index);
      delay(150);
      hoverClick(index);
      delay(250);
      //select_setting(index);
      delay(250);
      goto waiting;
    }
    //// END OF MIDDLE BUTTON


  end_menu:
    //if(makeSound){buzzer();}
    updateVars();
    Oled.fillScreen(BLACK);
  
}
