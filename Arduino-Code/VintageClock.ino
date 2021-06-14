///arrays to store positions of 12 clock positions
int clock_x_outer[60]={64, 70, 76, 83, 88, 94, 99, 104, 109, 113, 116, 119, 121, 123, 124, 124, 124, 123, 121, 119, 116, 113, 109, 104, 99, 94, 88, 83, 76, 70, 64, 58, 52, 45, 40, 34, 29, 24, 19, 15, 12, 9, 7, 5, 4, 4, 4, 5, 7, 9, 12, 15, 19, 24, 29, 34, 40, 45, 52, 58};
int clock_y_outer[60]={4, 4, 5, 7, 9, 12, 15, 19, 24, 29, 34, 40, 45, 52, 58, 64, 70, 76, 83, 88, 94, 99, 104, 109, 113, 116, 119, 121, 123, 124, 124, 124, 123, 121, 119, 116, 113, 109, 104, 99, 94, 88, 83, 76, 70, 64, 58, 52, 45, 40, 34, 29, 24, 19, 15, 12, 9, 7, 5, 4};

//int clock_x_inner_60[60]={64, 69, 74, 79, 84, 89, 93, 97, 101, 104, 107, 110, 112, 113, 114, 114, 114, 113, 112, 110, 107, 104, 101, 97, 93, 89, 84, 79, 74, 69, 64, 59, 54, 49, 44, 39, 35, 31, 27, 24, 21, 18, 16, 15, 14, 14, 14, 15, 16, 18, 21, 24, 27, 31, 35, 39, 44, 49, 54, 59};
//int clock_y_inner_60[60]={14, 14, 15, 16, 18, 21, 24, 27, 31, 35, 39, 44, 49, 54, 59, 64, 69, 74, 79, 84, 89, 93, 97, 101, 104, 107, 110, 112, 113, 114, 114, 114, 113, 112, 110, 107, 104, 101, 97, 93, 89, 84, 79, 74, 69, 64, 59, 54, 49, 44, 39, 35, 31, 27, 24, 21, 18, 16, 15, 14};

int clock_x_inner[13]={64, 89, 107, 114, 107, 89, 64, 39, 21, 14, 21, 39};
int clock_y_inner[13]={14, 21, 39, 64, 89, 107, 114, 107, 89, 64, 39, 21};

//array of positions of minute circle
int clock_x_hour[60]={64, 68, 72, 76, 80, 84, 88, 91, 94, 96, 99, 101, 102, 103, 104, 104, 104, 103, 102, 101, 99, 96, 94, 91, 88, 84, 80, 76, 72, 68, 64, 60, 56, 52, 48, 44, 40, 37, 34, 32, 29, 27, 26, 25, 24, 24, 24, 25, 26, 27, 29, 32, 34, 37, 40, 44, 48, 52, 56, 60};
int clock_y_hour[60]={24, 24, 25, 26, 27, 29, 32, 34, 37, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 91, 94, 96, 99, 101, 102, 103, 104, 104, 104, 103, 102, 101, 99, 96, 94, 91, 88, 84, 80, 76, 72, 68, 64, 60, 56, 52, 48, 44, 40, 37, 34, 32, 29, 27, 26, 25, 24};

///Functions to print time in vintage way, da real way, da way
void drawHour(int h){
  Oled.drawLine(64,64,clock_x_hour[v_prevhour],clock_y_hour[v_prevhour],BLACK);
  Oled.drawLine(64,64,clock_x_hour[h],clock_y_hour[h],color);
}
void drawMinute(int m){
  Oled.drawLine(64,64,clock_x_outer[v_prevminute],clock_y_outer[v_prevminute],BLACK);
  Oled.drawLine(64,64,clock_x_outer[m],clock_y_outer[m],color);
}
void drawSecond(int s){
  if(v_hour_modified != v_prevsecond && v_minute != v_prevsecond){
    Oled.drawLine(64,64,clock_x_hour[v_prevsecond],clock_y_hour[v_prevsecond],BLACK);
  }
  if(v_hour_modified != v_second && v_minute != v_second){
    if(color == WHITE){
    Oled.drawLine(64,64,clock_x_hour[s],clock_y_hour[s],RED);
    }
    else{
    Oled.drawLine(64,64,clock_x_hour[s],clock_y_hour[s],WHITE);
    }
   }   
}


//Function to handle drastic changes in values
int handleException(){
   if(v_prevsecond==-1){
    return 0;
   }
   if(v_second==0){
    return 1;
   }
}

///Function to print 12 hr grid for vintage clock
void printGrid(){
  for (int i=0; i<12; i++){
    Oled.drawLine(clock_x_inner[i],clock_y_inner[i],clock_x_outer[i*5],clock_y_outer[i*5],color);
  }
}

//// Function used to print the current time in the OLED Display the "good ol' way"
void print_time_vintage(){
  mainv:
  DateTime now = rtc.getCurrentDateTime();
  
  v_hour = now.hour();
  if (v_hour>=12){v_hour-=12;}
  v_minute = now.minute();
  v_second = now.second();
  Serial.println(v_second);

  v_hour_modified = (v_hour*5) + round(v_minute/15);

  printGrid();

  //if(handleException()){delay(100);goto mainv;}

  
  if (v_hour_modified != v_prevhour){
    drawHour(v_hour_modified);
    v_prevhour = v_hour_modified;
    v_changing = 1;
  }
   
  if (v_minute != v_prevminute){
    drawMinute(v_minute);
    v_prevminute=v_minute;
    v_changing = 1;
  }
  
  if (v_second != v_prevsecond){
    drawSecond(v_second);
    v_prevsecond=v_second;
    v_changing = 1;
  }
  
  changing = 0;
}
