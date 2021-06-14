void nav(){ 
  pinMode(32, OUTPUT);
  digitalWrite(32, HIGH);
  int init=0;
  Oled.fillScreen(BLACK);
  drawedge(selected);
  while ((digitalRead(b_button) ==  HIGH) && (digitalRead(m_button) ==  HIGH) && (digitalRead(t_button) ==  HIGH)){
   int r = 4;
   Oled.drawCircle(62, 120, r, color);
   Oled.drawCircle(33, 112, r, color);
   Oled.drawCircle(12, 91, r, color);
   Oled.drawCircle(4, 62, r, color);
   Oled.drawCircle(12, 33, r, color);
   Oled.drawCircle(33, 12, r, color);
   Oled.drawCircle(62, 4, r, color);
   Oled.drawCircle(91, 12, r, color);
   Oled.drawCircle(112, 33, r, color);
   Oled.drawCircle(120, 62, r, color);
   Oled.drawCircle(112, 91, r, color);
   Oled.drawCircle(91, 112, r, color);

   String distance = sendBLE("/distance");
   String d= sendBLE("/degree");

   if(prevd!=distance | init==0){
    Oled.fillCircle(64,64,40,BLACK);
    drawCentreString(distance,64,64);
   }
   prevd=distance;
   
   if(prev!=d| init==0){
     if(prev=="6"){ Oled.fillCircle(62, 120, r, BLACK);}
     if(prev=="5"){ Oled.fillCircle(33, 112, r, BLACK);}
     if(prev=="4"){ Oled.fillCircle(12, 91, r, BLACK);}
     if(prev=="3"){ Oled.fillCircle(4, 62, r, BLACK);}
     if(prev=="2"){ Oled.fillCircle(12, 33, r, BLACK);}
     if(prev=="1"){ Oled.fillCircle(33, 12, r, BLACK);}
     if(prev=="0"){ Oled.fillCircle(62, 4, r, BLACK);}
     if(prev=="11"){ Oled.fillCircle(91, 12, r, BLACK);}
     if(prev=="10"){ Oled.fillCircle(112, 33, r, BLACK);}
     if(prev=="9"){ Oled.fillCircle(120, 62, r, BLACK);}
     if(prev=="8"){ Oled.fillCircle(112, 91, r, BLACK);}
     if(prev=="7"){ Oled.fillCircle(91, 112, r, BLACK);}
    
     if(d=="6"){ Oled.fillCircle(62, 120, r, color);}
     if(d=="5"){ Oled.fillCircle(33, 112, r, color);}
     if(d=="4"){ Oled.fillCircle(12, 91, r, color);}
     if(d=="3"){ Oled.fillCircle(4, 62, r, color);}
     if(d=="2"){ Oled.fillCircle(12, 33, r, color);}
     if(d=="1"){ Oled.fillCircle(33, 12, r, color);}
     if(d=="0"){ Oled.fillCircle(62, 4, r, color);}
     if(d=="11"){ Oled.fillCircle(91, 12, r, color);}
     if(d=="10"){ Oled.fillCircle(112, 33, r, color);}
     if(d=="9"){ Oled.fillCircle(120, 62, r, color);}
     if(d=="8"){ Oled.fillCircle(112, 91, r, color);}
     if(d=="7"){ Oled.fillCircle(91, 112, r, color);}
   }
   prev=d;
   init=1;
  }
  if(makeSound){buzzer();}
}
