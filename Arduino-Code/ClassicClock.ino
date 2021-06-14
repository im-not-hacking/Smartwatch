
//FLASHLIGHT
const unsigned char f_symbol [] PROGMEM = {
  0x6d, 0x80, 0x6d, 0x80, 0x6d, 0x80, 0x6d, 0x80, 0x00, 0x00, 0x7f, 0x80, 0x7f, 0x80, 0x7f, 0x80, 
  0x7f, 0x80, 0x7f, 0x80, 0x7f, 0x80, 0x3f, 0x80, 0x3f, 0x00, 0x3f, 0x00, 0x33, 0x00, 0x3f, 0x00, 
  0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x1e, 0x00
};

void wait_clock_completion(){
  while (changing == 1){
    delay(50);
  }
}

void getClock(bool select){
  if (!select){
    //if(!isWeatherDisplayed){isWeatherDisplayed = true;print_weather_time();}
    print_time_classic();
    print_date();
  }
  else{
    print_time_vintage();
    batt_num(getVarPerc);
  }
}

//// Function used to print the current time in the OLED Display
void print_time_classic(){

  Oled.setTextColor(WHITE);
  DateTime now = rtc.getCurrentDateTime();
  
  cH24 = now.hour();
  if ((cH24 > 0) && (cH24 <= 9)){
    cH_print = "0" + String(cH24);
  }
  else if ((cH24 > 9) && (cH24 <= 12)){
    cH_print = String(cH24);
  }
  else if ((cH24 > 12) && (cH24 < 22)){
    cH_print = "0" + String(cH24 - 12);
  }
  else if (cH24 >= 22){
    cH_print = String(cH24 - 12);
  }
  else if (cH24 == 0){
    cH_print = "12";
  }
  
  cM = now.minute();
  if ((cM >= 0) && (cM <= 9)){
    cM_print = "0" + String(cM);
  }
  else if (cM > 9){
    cM_print = String(cM);
  }

  
  cS = now.second();
  if ((cS >= 0) && (cS <= 9)){
    cS_print = "0" + String(cS);
  }
  else if (cS > 9){
    cS_print = String(cS);
  }

  
  
  if (cH_print != prevHour){
    changing = 1;
    Oled.setFont(&Lato_Regular_27);
    Oled.setTextColor(BLACK);
    drawCentreString(prevHour, 64-22, 64);
    drawCentreString(":",64,64);
    Oled.setTextColor(color);
    prevHour = cH_print;
    drawCentreString(prevHour, 64-22, 64);
    drawCentreString(":",64,64);
    if ((cH24 < 12) && (ampm != "AM")){
      Oled.setFont(&Lato_Regular_16);
      Oled.setTextColor(BLACK);
      drawCentreString("PM", 64, 85);
      Oled.setTextColor(color);
      drawCentreString("AM", 64, 85);
      ampm = "AM";
    }
    else if ((cH24 >= 12) && (ampm != "PM")){
      Oled.setFont(&Lato_Regular_16);
      Oled.setTextColor(BLACK);
      drawCentreString("AM", 64, 85);
      Oled.setTextColor(color);
      drawCentreString("PM", 64, 85);
      ampm = "PM";
    }
  }
   
  if (cM_print != prevMinute){
    changing = 1;
    Oled.setFont(&Lato_Regular_27);
    Oled.setTextColor(BLACK);
    drawCentreString(prevMinute, 64+22, 64);
    prevMinute = cM_print;
    Oled.setTextColor(color);
    drawCentreString(prevMinute, 64+22, 64);
  }
  
  if (cS_print != prevSecond){
    changing = 1;
    Oled.setFont(&Lato_Regular_27);
    Oled.setTextColor(BLACK);
    seconds_bar(cS);
    //drawCentreString(prevSecond, 102, 94);
    prevSecond = cS_print;
    //Oled.setTextColor(color);
    //drawCentreString(prevSecond, 102, 94);
  }
  
  changing = 0;
}


void print_date(){
  DateTime now = rtc.getCurrentDateTime();
  cMo_print= (months[now.month()-1]);
  currentDayWeek = daysOfTheWeek[now.dayOfTheWeek()];
  cD = now.day();
  if (cD < 10){
    cD_print = "0" + String(cD);
  }
  else{
    cD_print = String(cD);
  }
  if (prevDay != cD_print){
    changing = 1;
    Oled.setTextColor(color);
    Oled.setFont();
    Oled.setTextSize(1);
    Oled.setCursor(32, 105);
    Oled.print(currentDayWeek + ", " + String(cMo_print.substring(0, 3)) + " " + cD_print);
    prevDay = cD_print;
    delay(100);
    changing = 0;
    delay(100);
  }
}


int getBattPerc(){
  //float newperc = ((analogRead(batt)*3.6/4095)*45.5) - 79.6; Not used

  // For Rene
  //float newperc = (analogRead(batt)*0.00175);

  // For Ale
  float newperc = (analogRead(batt)*0.00165);
  
  Serial.println(String(newperc)+ " V");

  if(digitalRead(chg) == HIGH){newperc-=0.01;}
  newperc = (newperc*142.86)-500;
  
  Serial.println("Aqui esta la bateria chingadamadre:");
  Serial.println(String(newperc));
  
  int newnewperc = newperc;

  if (newnewperc > 100){
      newnewperc = 100;
    }
  if (newnewperc < 1){
      newnewperc = 1;
    }
  
  return newnewperc;
}


void print_battery(){
  Oled.drawRect(110, 4, 17, 11, WHITE);
  Oled.fillRect(127, 6, 2, 7, WHITE);
  
  if ((perc == 0) || (digitalRead(chg) == LOW)){
    perc = ((analogRead(batt)*3.6/4095)*45.5) - 79.6;
    Serial.print(analogRead(batt)*3.6/4095);
    Serial.print("\n"+String(perc));
    
    if (perc > 15){
      perc = 15;
    }
    if (perc < 1){
      perc = 1;
    }

    Oled.fillRect(111, 5, 15, 9, BLACK);
    
    if (digitalRead(chg) == HIGH){
      goto stat_change;
    }
    
    if (perc <= 3){
      Oled.fillRect(111, 5, perc, 9, RED);
    }
    
    else if ((perc > 3) && (perc <= 5)){
      Oled.fillRect(111, 5, perc, 9, YELLOW);
    }
    
    else{
      Oled.fillRect(111, 5, perc, 9, GREEN);
    }
  }
  

  else if (digitalRead(chg) == HIGH){
    stat_change:
    if (perc <= 14){
      Oled.fillRect(111, 5, perc, 9, CYAN);
    }
  
    else{
      Oled.fillRect(111, 5, perc, 9, BLUE);
    }
  }

  Serial.print("\n"+String(perc*100/15));
  Serial.print("\n"+String(digitalRead(chg)));
}



void buzzer(){
  delay(100);
  ledcWriteTone(Channel, 2048);
  delay(100);
  ledcWriteTone(Channel, 0);
}



void flashlight(){
  if (flash_status == 0){
    digitalWrite(19,HIGH);
    flash_status = 1;
  }
  else if (flash_status == 1){
    digitalWrite(19,LOW);
    flash_status = 0;
  }
}



void flash_symbol(){
  if (flash_status == 0){
    Oled.drawBitmap(116, 104, f_symbol, 11, 23, BLACK);
  }
  else if (flash_status == 1){
    Oled.drawBitmap(116, 104, f_symbol, 11, 23, colors_list[red_f]); 
  }
}



void stopwatch(){
  beg:
  Oled.fillScreen(BLACK);
  drawedge(selected);
  Oled.setFont(&Orbitron_Medium_32);
  Oled.fillRect(0, 29, 128, 80, BLACK);
  flash_symbol();
  int min_ = 0;
  String min_print;
  String min_past_print = "00:";
  int sec_ = -1;
  String sec_print;
  String sec_past_print = "00";
  int cS_past = -1;
  int starting = 0;
  int mill_ = 0;
  int start_mill;
  String mill_print;
  byte prev_chg = digitalRead(chg);
  byte curr_chg = digitalRead(chg);
  Oled.setTextColor(color);
  drawCentreString("00:", 32, 66);
  drawCentreString("00", 96, 66);
  Oled.setFont(&Orbitron_Medium_24);
  drawCentreString("000", 64, 99);
  
  wait_bottom();
  
  while(digitalRead(m_button) == HIGH){
    
    if (digitalRead(t_button) == LOW){
      wait_top();
      if(makeSound){buzzer();}
      goto beg;
    }
    
    else if(digitalRead(b_button) == LOW){
      goto main;
    }
    
    curr_chg = digitalRead(chg);
    if (curr_chg != prev_chg){
      if(!isVintage){batt_bar(getVarPerc);}else{batt_num(getVarPerc);}
      prev_chg = curr_chg;
    }
    
    delay(50);
  }

  
  wait_middle();
  
  if(makeSound){buzzer();}
  start_mill = millis();
  Oled.setTextColor(BLACK);
  drawCentreString("000", 64, 99);

  while(digitalRead(m_button) == HIGH){
    res:
    DateTime now = rtc.getCurrentDateTime();
    cS = now.second();
    if(cS != cS_past){
      Oled.setFont(&Orbitron_Medium_32);
      start_mill = millis();
      sec_ += 1;
      
      if (sec_ == 60){
        sec_ = 0;
        min_ += 1;
        if (min_ == 100){
          min_ = 0;
        }
        Oled.setTextColor(BLACK);
        drawCentreString(min_past_print, 32, 66);
        drawCentreString(sec_past_print, 96, 66);
        if (min_ < 10){
          min_print = "0" + String(min_) + ":";
        }
    
        else{
          min_print = String(min_) + ":";
        }
        Oled.setTextColor(color);
        drawCentreString(min_print, 32, 66);
        min_past_print = min_print;
      }

      if (sec_ < 10){
        sec_print = "0" + String(sec_);
      }


      else{
        sec_print = String(sec_);
      }


      curr_chg = digitalRead(chg);
      if (curr_chg != prev_chg){
        if(!isVintage){batt_bar(getVarPerc);}else{batt_num(getVarPerc);}
        prev_chg = curr_chg;
        delay(50);
      }

        
      Oled.setTextColor(BLACK);
      drawCentreString(sec_past_print, 96, 66);
      Oled.setTextColor(color);
      drawCentreString(sec_print, 96, 66);
      sec_past_print = sec_print;
      cS_past = cS;
    }
    
    mill_ = millis() - start_mill;
    if (mill_ < 10){
      mill_print = "00" + String(mill_);
    }
    else if (mill_ < 100){
      mill_print = "0" + String(mill_);
    }
    else{
      mill_print = String(mill_);
    }
    Oled.setFont(&Orbitron_Medium_24);
    Oled.setTextColor(color);
    drawCentreString(mill_print, 64, 99);
    delay(20);
    Oled.setTextColor(BLACK);
    drawCentreString(mill_print, 64, 99); 
  }
  
  Oled.setTextColor(color);
  drawCentreString(mill_print, 64, 99);

  if(makeSound){buzzer();}
  wait_middle();
  
  while ((digitalRead(b_button) != LOW) && (digitalRead(m_button) != LOW) && (digitalRead(t_button) != LOW)){
    delay(50);
    curr_chg = digitalRead(chg);
    if (curr_chg != prev_chg){
      if(!isVintage){batt_bar(getVarPerc);}else{batt_num(getVarPerc);}
      prev_chg = curr_chg;
    }
    delay(50);
  }


  if (digitalRead(b_button) == LOW){
    main:
    wait_bottom();
    if(makeSound){buzzer();}
    Oled.fillRect(0, 29, 128, 80, BLACK);
    prevMinute = -1;
    prevHour = -1;
    prevSecond = -1;
    v_prevhour = -1;
    v_prevminute = -1;
    v_prevsecond = -1;
    ampm = "None";
  }


  else if (digitalRead(m_button) == LOW){
    wait_middle();
    if(makeSound){buzzer();}
    Oled.setTextColor(BLACK);
    drawCentreString(mill_print, 64, 99); 
    goto res;
  }


  else if (digitalRead(t_button) == LOW){
    wait_top();
    if(makeSound){buzzer();}
    goto beg;
  }
}
