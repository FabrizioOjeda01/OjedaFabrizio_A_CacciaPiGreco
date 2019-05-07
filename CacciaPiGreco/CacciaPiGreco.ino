int btn_Inizio;
int btn_Uno;
int btn_Due;
int btn_Tre;
int btn_Quattro;
int btn_Cinque;
int tempo;
int vite;
int punti;
int record;
bool b;

void setup() {
  // put your setup code here, to run once:

  tempo = 2000;
  vite  = 5;
  punti = 0;
  record = 0;

  btn_Inizio  = 7;
  btn_Uno     = 8;
  btn_Due     = 9;
  btn_Tre     = 10;
  btn_Quattro = 11;
  btn_Cinque  = 12;

  pinMode(btn_Inizio,  INPUT);
  pinMode(btn_Uno,     INPUT);
  pinMode(btn_Due,     INPUT);
  pinMode(btn_Tre,     INPUT);
  pinMode(btn_Quattro, INPUT);
  pinMode(btn_Cinque,  INPUT);
}


bool NomeDaSpecificare(String s) {

  int pos = ((random (1, 5)) * 3) - 2;
  //  lcd.setCursor(pos, 1);
  //  lcd.print(s);
  int premuto = 0;

  for (int i = 0; i < tempo; i++) {
    if (btn_Uno == HIGH) {
      premuto = 1;
      break;
    }
    else if (btn_Due == HIGH) {
      premuto = 2;
      break;
    }
    else if (btn_Tre == HIGH) {
      premuto = 3;
      break;
    }
    else if (btn_Quattro == HIGH) {
      premuto = 4;
      break;
    }
    else if (btn_Cinque == HIGH) {
      premuto = 5;
      break;
    }
  }
  if (pos == premuto) {
    return true;
  }
  else {
    return false;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  while (digitalRead(btn_Inizio) == LOW) {}
  lcd.clear();

  while (vite > 0) {

    int i = random(1, 3);
    if (i == 1) {
      b = NomeDaSpecificare("M");
      if (b == true) {
        punti--;
      }
    } else if (i == 2) {
      b = NomeDaSpecificare("B");
      if (b == true) {
        punti++;
        tempo += 50;
      }
    }
    else {
      b = NomeDaSpecificare("P");
      if (b == true) {
        punti++;
        tempo -= 50;
      }
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Punti:" + punti);
    lcd.setCursor(0, 9);
    lcd.print("Vite:" + vite);
  }

  if (record < punti) {

    record = punti;

  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Record attuale:" + record);
  lcd.setCursor(0, 1);
  lcd.print("Punteggio del match:" + punti);
}
for (int i = 0; i < tempo; i++) {
  if (btn_Uno == HIGH) {
    premuto = 1;
  } break;
  else if (btn_Due == HIGH) {
    premuto = 2;
  } break;
  else if (btn_Tre == HIGH) {
    premuto = 3;
  } break;
  else if (btn_Quattro == HIGH) {
    premuto = 4;
  } break;
  else if (btn_Cinque == HIGH) {
    premuto = 5;
  } break;
}

if (pos == premuto) {
  punti++;
  tempo -= 40
} else {
  vite--;
}
}

void loop() {
  // put your main code here, to run repeatedly:

}
