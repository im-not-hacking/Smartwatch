int prevsec = 0;
int current_if = 0;
int initialx = 10;
int width = 0;
int prevperc = 0;
String loadtext = "Loading ...";

void printName(){
  Oled.setTextColor(WHITE);
  Oled.setFont();
  Oled.setCursor(15,100);
  Oled.print (loadtext);
  Oled.setFont(&Lato_Regular_20);
  drawCentreString("Welcome,",64,30);
  Oled.setFont(&Lato_Regular_16);
  //Cambiar para Rene
  drawCentreString("Rene",64,60);
  //Cambiar para el Don
  //drawCentreString("Mr. Placitelli",64,60);
}

void load_seconds(float sec){

  float percentage = (sec/60);

  float max_total = 111;

  int initialy = 80;

  int width = max_total*percentage;

  if(prevsec > 58){
    Oled.fillRect(initialx,initialy,max_total,10, BLACK);
  }

  //draw first color rect
  if (sec < 21){
    current_if = 1;
    initialx = 6;
    //Rene
    Oled.fillRect(initialx,initialy,width,10,GREEN);
    //Alessandro
    //Oled.fillRect(initialx,initialy,width,10,YELLOW);
  }
  //draw second color rect
  if (sec < 41 and sec >20){
    
    int initialxy = (max_total*(0.333));
    Serial.println(initialxy);
    //Rene
    Oled.fillRect(45,initialy,width-initialxy,10,WHITE);
    //Alessandro
    //Oled.fillRect(45,initialy,width-initialxy,10,BLUE);
  }
  //draw third color rect
  if (sec > 40){

    int initialxz = (max_total*(0.666));

    //Rene
    Oled.fillRect(85,initialy,width-initialxz,10,RED);
    //Alessandro
    //Oled.fillRect(85,initialy,width-initialxz,10,RED);
  }


  
  //int int_prevsec = prevsec;
  //int int_sec = sec;

  float newperc = percentage * 100;
  int int_prevperc = prevperc;
  int int_perc = newperc;

  Oled.setFont();
  Oled.setCursor(70,88);
  Oled.setTextColor(BLACK);
  drawCentreString(String(int_prevperc) + " %",100,100);

  Oled.setTextColor(WHITE);
  drawCentreString(String(int_perc) + " %",100,100);

  initialx = 10;
  

  prevsec = sec;
  prevperc = newperc;
}

void eraseLoadText(){
  Oled.setCursor(15,100);
  Oled.setTextColor(BLACK);
  Oled.print (loadtext);
}

void startLoad(){
  Oled.fillScreen(BLACK);

  printName();
  for (float i = 0; i<60; i++){
    load_seconds(i);
    delay(10);
  }
  loadtext = "Retrying...";
}
