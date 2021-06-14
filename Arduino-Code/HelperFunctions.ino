//// Function used for centering text
void drawCentreString(const String &buf, int x, int y){
  int16_t x1, y1;
  uint16_t w, h;
  Oled.getTextBounds(buf, 0, y, &x1, &y1, &w, &h); //calc width of new string
  Oled.setCursor(x - (w / 2), y);
  Oled.print(buf);
}

void Wait_SleepMode(){
  byte prev_chg = digitalRead(chg);
  sleep_beg:
  wait = 0;
  while ((digitalRead(b_button) != LOW) && (digitalRead(m_button) != LOW) && (digitalRead(t_button) != LOW)){
    delay(50);
    wait_clock_completion();
    byte curr_chg = digitalRead(chg);
    if (curr_chg != prev_chg){
      if(!isVintage){batt_bar(getVarPerc);}else{batt_num(getVarPerc);}
      prev_chg = curr_chg;
      delay(500);
      goto sleep_beg;
    }
    delay(50);

    Serial.println("[ROTATING] : "+String(digitalRead(acc)));

    if (digitalRead(acc) == HIGH){wait = 0;}
    
    else{wait += 100;}
    
    if (wait >= 10000){
      wait_clock_completion();
      vTaskDelete(Task1);
      delay(500);
      Oled.fillScreen(BLACK);
      delay(500);
      if(!wakeRotation){
      esp_sleep_enable_ext0_wakeup(GPIO_NUM_15, 0);
      }
      else{
      esp_sleep_enable_ext0_wakeup(GPIO_NUM_26, 1);
      }
      esp_deep_sleep_start();

      //rtc.setDateTimeFromISO8601(sendBLE("/time"));
      rtc.synchronize();
    }
  }
}
