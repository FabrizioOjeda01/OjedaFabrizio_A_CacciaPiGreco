#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Variabili INPUT

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
int premuto;
int pos;

void setup() {
  // put your setup code here, to run once:

  record = 0;

  btn_Inizio  = 2;
  btn_Uno     = 8;
  btn_Due     = 9;
  btn_Tre     = 10;
  btn_Quattro = 11;
  btn_Cinque  = 12;

  lcd.init();
  lcd.backlight();
  pinMode(btn_Inizio,  INPUT);
  pinMode(btn_Uno,     INPUT);
  pinMode(btn_Due,     INPUT);
  pinMode(btn_Tre,     INPUT);
  pinMode(btn_Quattro, INPUT);
  pinMode(btn_Cinque,  INPUT);
}


bool NomeDaSpecificare(String s) {
  delay(1500);
  int pos = ((random (1, 5)) * 3) - 2;
  lcd.setCursor(pos, 1);
  lcd.print(s);
  int premuto = 0;

  for (int i = 0; i < tempo; i++) {
    if (digitalRead(btn_Uno) == HIGH) {
      premuto = 1;
      break;
    }
    else if (digitalRead(btn_Due) == HIGH) {
      premuto = 4;
      break;
    }
    else if (digitalRead(btn_Tre) == HIGH) {
      premuto = 7;
      break;
    }
    else if (digitalRead(btn_Quattro) == HIGH) {
      premuto = 10;
      break;
    }
    else if (digitalRead(btn_Cinque) == HIGH) {
      premuto = 13;
      break;
    }
    delay(1);
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

  tempo = 2000;
  vite  = 5;
  punti = 0;
  while (digitalRead(btn_Inizio) == LOW) {}
  lcd.clear();

  while (vite > 0) {
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Punti:" + String(punti));
    lcd.setCursor(9, 0);
    lcd.print("Vite:" + String(vite));

    int i = random(1, 11);
    if (i == 1) {
      b = NomeDaSpecificare("M");
      if (b == true) {
        punti--;
      }
    } else if (i == 2) {
      b = NomeDaSpecificare("B");
      if (b == true) {
        vite++;
        tempo += 50;
      }
    }
    else {
      b = NomeDaSpecificare("P");
      if (b == true) {
        punti++;
        tempo -= 50;
      }
      else {
        vite--;
      }
    }
  }

  if (record < punti) {

    record = punti;

  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Record:" + String(record));
  lcd.setCursor(0, 1);
  lcd.print("Punteggio:" + String(punti));
}
