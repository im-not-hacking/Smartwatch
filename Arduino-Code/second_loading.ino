int prevsec_b = 0;

void seconds_bar(float sec){

  float percentage = (sec/60);

  float max_total = 101;

  int initialx = 114;
  int initialy = 125;

  int width = max_total*percentage;

  if(prevsec_b > 58){
    Oled.fillRect(114,11,10,111, BLACK);
  }

  Oled.fillRect(initialx,initialy-width,10,width,RED);
   
  int int_prevsec = prevsec_b;
  int int_sec = sec;

  Oled.setFont();
  Oled.setCursor(70,88);
  Oled.setTextColor(BLACK);
  drawCentreString(String(int_prevsec),119,10);

  Oled.setTextColor(color);
  drawCentreString(String(int_sec),119,10);

  initialy = 10;
  

  prevsec_b = sec;
}

void startSecLoad(){

  while(true){
    Oled.fillRect(114,11,10,111, WHITE);
    for (float i = 0; i<60; i++){
      seconds_bar(i);
      delay(250);
    }
  }
}
