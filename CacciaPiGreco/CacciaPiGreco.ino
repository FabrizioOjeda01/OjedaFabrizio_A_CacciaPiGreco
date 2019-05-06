int btn_Inizio;
int btn_Uno;
int btn_Due;
int btn_Tre;
int btn_Quattro;
int btn_Cinque;
int tempo;
int vite;
int punti;

void setup() {
  // put your setup code here, to run once:

  tempo = 2000;
  vite  = 5;
  punti = 0;

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

int DefinisciSimboli() {
  int i = random(1, 3)
  if (i == 1) {
    //P
  } else if (i == 2) {
    //B
  } else {
    //M
  }
}

int NomeDaSpecificare() {

  int pos = (random (1, 5)) * 3) - 2
  lcd.setCursor(pos, 1);
  print("p");
  int premuto = 0;

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
