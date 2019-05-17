#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define btn_Inizio   3      //variabili input
#define btn_Uno      12
#define btn_Due      11
#define btn_Tre      10
#define btn_Quattro  9
#define btn_Cinque   8

byte Bonus[8] = {           //creazione dei byte per Bonus,Malus, PiGreco
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};

byte Malus[8] = {
  B00000,
  B01110,
  B11111,
  B10101,
  B11111,
  B01110,
  B01110,
  B00000
};

byte PiGreco[8] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B01010,
  B01010,
  B01010,
  B00000
};

int tempo = 2000;
int record = 0;
bool b;
int pos;

void setup() {

  lcd.createChar(0, Bonus);
  lcd.createChar(1, Malus);
  lcd.createChar(2, PiGreco);
  lcd.init();
  lcd.backlight();

  pinMode(btn_Inizio,  INPUT);
  pinMode(btn_Uno,     INPUT);
  pinMode(btn_Due,     INPUT);
  pinMode(btn_Tre,     INPUT);
  pinMode(btn_Quattro, INPUT);
  pinMode(btn_Cinque,  INPUT);
}

bool DefinisciPos(String s) {     //metodo per definire le posizioni dei simboli nell'LCD
  delay(1500);
  int pos = ((random (1, 6)) * 3) - 2;
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

  int vite  = 5;
  int punti = 0;

  while (digitalRead(btn_Inizio) == LOW) {}      //finché il bottone di inizio non è premuto non comincerà nulla
  lcd.clear();

  while (vite > 0) {                             //finché le vite saranno maggiori di 0 il gioco continuerà
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Punti:" + String(punti));         //Scrive nella prima riga dell'LCD (a sx) i punti
    lcd.setCursor(9, 0);
    lcd.print("Vite:" + String(vite));           //Scrive nella prima riga dell'LCD (a dx) le vite

    int i = random(1, 11);
    if (i == 1) {
      b = DefinisciPos("M");                     //Definisce il Malus, diminuisce i punti di 1
      if (b == true) {
        punti--;
      }
    } else if (i == 2) {
      b = DefinisciPos("B");                     //Definisce il Bonus, si guadagna una vita ed il tempo di scomparsa del pigreco aumenta
      if (b == true) {
        vite++;
        tempo += 50;
      }
    }

    else {
      b = DefinisciPos("P");                    //Definisce il PiGreco, aumenta i punti di 1, e diminuisce il tempo di scomparsa del PiGreco
      if (b == true) {
        punti++;
        tempo -= 50;
      }
      else {
        vite--;
      }
    }
  }

  if (record < punti) {                         //Se i punti saranno maggiori del record, questi diventeranno il nuovo record
    record = punti;
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Record:" + String(record));
  lcd.setCursor(0, 1);
  lcd.print("Punteggio:" + String(punti));
}
