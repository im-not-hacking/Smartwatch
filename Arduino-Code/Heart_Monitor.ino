const byte RATE_SIZE = 14; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; 
byte rateSpot = 0;
long lastBeat = 0;
float beatsPerMinute;
int beatAvg;
String beat_past = "00";



const unsigned char heart_big [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x1f, 0x80, 0x0f, 0xf8, 0x7f, 0xe0, 
0x3f, 0xfc, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0xfc, 
0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xcf, 0xfc, 0xff, 0xff, 0x8f, 0xfc, 0xff, 0xff, 0x8f, 0xfc, 
0xff, 0xff, 0x07, 0xfc, 0x7f, 0x9f, 0x07, 0xfc, 0x7f, 0x0e, 0x23, 0xf8, 0x7f, 0x0e, 0x63, 0xf8, 
0x00, 0x04, 0x70, 0x00, 0x00, 0x60, 0xf0, 0x00, 0x1f, 0xe0, 0xff, 0xe0, 0x0f, 0xf1, 0xff, 0xc0, 
0x07, 0xf1, 0xff, 0x80, 0x03, 0xfb, 0xff, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 
0x00, 0x7f, 0xf8, 0x00, 0x00, 0x3f, 0xf0, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x07, 0x80, 0x00, 
0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


const unsigned char heart_small [] PROGMEM = {
0x00, 0x00, 0x00, 0x1f, 0x07, 0x80, 0x3f, 0x9f, 0xc0, 0x7f, 0xff, 0xe0, 0xff, 0xff, 0xf0, 0xff, 
0xf7, 0xf0, 0xff, 0xf7, 0xf0, 0xff, 0xe3, 0xf0, 0xfd, 0xc3, 0xf0, 0x7c, 0xcb, 0xe0, 0x00, 0xd8, 
0x00, 0x1e, 0x1f, 0xc0, 0x1f, 0x3f, 0xc0, 0x0f, 0x3f, 0x80, 0x07, 0xff, 0x00, 0x03, 0xfe, 0x00, 
0x01, 0xf8, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00
};


void heart_monitor(){
  heartSensor.begin(Wire, I2C_SPEED_FAST);
  heartSensor.setup(); 
  heartSensor.setPulseAmplitudeRed(0x0A); 
  heartSensor.setPulseAmplitudeGreen(0); 
  Oled.setTextColor(color);
  Oled.fillScreen(BLACK);
  drawedge(selected);
  Oled.setFont(&Orbitron_Medium_20);
  drawCentreString("BPM", 45, 107);
  start_hm:
  Oled.setFont(&Orbitron_Medium_38);
  drawCentreString("--", 64, 70);
  Oled.drawBitmap(85, 89, heart_small, 20, 20, RED); 
  
  wait_for_any_button();

  //// TOP BUTTON && BOTTOM BUTTON
  if ((digitalRead(t_button) == LOW) || (digitalRead(b_button) == LOW)){
    heartSensor.shutDown();
    if(makeSound){buzzer();}
    goto end_hm;
  }


  //// MIDDLE BUTTON
  else if (digitalRead(m_button) == LOW){
    wait_middle();
    if(makeSound){buzzer();}
    delay(500);
    double constant = 1.25;
    for(int i = 0; i < 2300; i++){
       heart_function();
       if ((beatAvg >= 50) && (beat_past != String(beatAvg))){
        int newpastbeatAvg = beat_past.toInt()*constant;
        Oled.setTextColor(BLACK);
        if (newpastbeatAvg == 0){drawCentreString("--", 64, 70);}
        else{drawCentreString(String(newpastbeatAvg), 64, 70);}
        Serial.println("PASTBEAT :"+String(newpastbeatAvg));
        Oled.setTextColor(color);
        int newbeatAvg = beatAvg*constant;
        drawCentreString(String(newbeatAvg), 64, 70);
        Serial.println("NEWBEAT :"+String(newbeatAvg));
        beat_past = String(beatAvg);
       }

       if (digitalRead(m_button) == LOW){
        wait_middle();
        goto wait_hm;
       }
       
       if (i%80 == 0){
        Oled.drawBitmap(85, 89, heart_small, 20, 20, BLACK); 
        Oled.drawBitmap(80, 84, heart_big, 30, 30, RED); 
        goto cont;
       }
        
       else if (i%40 == 0){
        Oled.drawBitmap(80, 84, heart_big, 30, 30, BLACK); 
        Oled.drawBitmap(85, 89, heart_small, 20, 20, RED); 
       }

      cont:;
    }

    wait_hm:
    if(makeSound){buzzer();}
    memset(rates, 0, sizeof(rates));
    wait_for_any_button();

    if (digitalRead(m_button) == LOW){
      wait_middle();
      if(makeSound){buzzer();}
      Oled.setTextColor(BLACK);
      Oled.fillRect(25,25,90,60,BLACK);
      Oled.setTextColor(color);
      beat_past = "00";
      beatAvg = 0;
      Oled.drawBitmap(85, 89, heart_small, 20, 20, BLACK); 
      Oled.drawBitmap(80, 84, heart_big, 30, 30, BLACK); 
      goto start_hm;
    }

    else if ((digitalRead(t_button) == LOW) || (digitalRead(b_button) == LOW)){
      heartSensor.shutDown();
      beat_past = "00";
      beatAvg = 0;
      if(makeSound){buzzer();}
      goto end_hm;
    }  
  }

  end_hm:;
}



void heart_function(){
  long irValue = heartSensor.getIR();

  if (checkForBeat(irValue) == true){
    //We sensed a beat!
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20){
      rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE; //Wrap variable

      beatAvg = 0;
      for (byte x = 0; x < RATE_SIZE; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
  }
}
