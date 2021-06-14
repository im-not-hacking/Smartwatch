void wait_for_any_button(){
  while ((digitalRead(b_button) ==  HIGH) && (digitalRead(m_button) ==  HIGH) && (digitalRead(t_button) ==  HIGH)){
    delay(10);
  }
}

void wait_bottom(){
  while (digitalRead(b_button) ==  LOW){
    delay(10);
  }
}


void wait_middle(){
  while (digitalRead(m_button) ==  LOW){
    delay(10);
  }
}


void wait_top(){
  while (digitalRead(t_button) ==  LOW){
    delay(10);
  }
}
