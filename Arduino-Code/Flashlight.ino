void drawflashanimation(int iteration){
  switch (iteration){
    case 0:
      Oled.fillCircle(64,64,30,YELLOW);
      break;

     case 1:
      Oled.drawCircle(64,64,40,YELLOW);
      Oled.drawCircle(64,64,39,YELLOW);
      Oled.drawCircle(64,64,38,YELLOW);
      Oled.drawCircle(64,64,37,YELLOW);
      break;

     case 2:
      Oled.drawCircle(64,64,50,YELLOW);
      Oled.drawCircle(64,64,49,YELLOW);
      Oled.drawCircle(64,64,48,YELLOW);
      Oled.drawCircle(64,64,47,YELLOW);
      break;
  }
}

bool flashon = false;

void flashlight_submenu(){
  Oled.fillScreen(BLACK);
  drawedge(selected);
  Oled.drawCircle(64,64,30,YELLOW);
  Oled.drawCircle(64,64,29,YELLOW);
  Oled.drawCircle(64,64,28,YELLOW);
  
  waiting:
  wait_for_any_button();
  
  //// BUTTOM BUTTON
    if (digitalRead(b_button) ==  LOW){
      if(makeSound){buzzer();}
      goto end_menu;
    }
    //// END OF BOTTOM BUTTON
  
  
    //// TOP BUTTON
    else if (digitalRead(t_button) ==  LOW){
      if(makeSound){buzzer();}
      goto end_menu;
    }
  
    //// MIDDLE BUTTON
    else if (digitalRead(m_button) ==  LOW){
      int pressed = 0;
      Oled.fillCircle(64,64,51,BLACK);

      if (flashon){
        digitalWrite(19,LOW);
        flashon = false;
        goto waiting;
      }
      
      while (digitalRead(m_button) ==  LOW){
        if (pressed > 1){
          drawflashanimation(2);
          digitalWrite(19,HIGH);
          flashon = true;
        }
        drawflashanimation(pressed);
        delay(1000);
        pressed += 1;
      }
      if (pressed < 3){
        Oled.fillCircle(64,64,51,BLACK);
        Oled.drawCircle(64,64,30,YELLOW);
        Oled.drawCircle(64,64,29,YELLOW);
        Oled.drawCircle(64,64,28,YELLOW);
      }
      goto waiting;
    }
    //// END OF MIDDLE BUTTON


  end_menu:
    //if(makeSound){buzzer();}
    digitalWrite(19,LOW);
    flashon = false;
    Oled.fillScreen(BLACK);
}
