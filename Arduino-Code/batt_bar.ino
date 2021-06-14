int prev_batt = 0;

void batt_bar(float battp){

  float percentage = (battp/100);

  float max_total = 101;

  int initialx = 5;
  int initialy = 125;

  int width = max_total*percentage;

  int color_b = GREEN;

    
  if (battp <= 20){
    color_b = RED;
  }
    
  else if ((perc > 20) && (perc <= 40)){
    color_b = YELLOW;
  }
    
  if (digitalRead(chg) == HIGH){
      Serial.println("[CHARGING] : " + String(digitalRead(chg)));
      color_b = BLUE;
  }

  Oled.fillRect(initialx,initialy-width,10,width,color_b);
   
  int int_prevsec = prev_batt;
  int int_sec = battp;

  Oled.setFont();
  Oled.setCursor(70,88);
  Oled.setTextColor(BLACK);
  drawCentreString(String(int_prevsec),11,10);

  Oled.setTextColor(color);
  drawCentreString(String(int_sec),11,10);

  initialy = 10;
  

  prev_batt = battp;
}

void batt_num (float battp){
  int int_prevsec = prev_batt;
  int int_sec = battp;

  Oled.setFont();
  //Oled.setTextColor(BLACK);
  //drawCentreString(String(int_prevsec),11,3);

  Oled.setTextColor(color);
  drawCentreString(String(int_sec),11,3);
  
  prev_batt = battp;
  
}

void startBattLoad(){

  while(true){
    Oled.fillRect(5,10,10,110, WHITE);
    for (float i = 0; i<100; i++){
      batt_bar(i);
      delay(250);
    }
  }
}
