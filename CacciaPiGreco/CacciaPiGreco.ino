int btn_Inizio;
int btn_Uno;
int btn_Due;
int btn_Tre;
int btn_Quattro;
int btn_Cinque;

void setup() {
  // put your setup code here, to run once:

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


void loop() {
  // put your main code here, to run repeatedly:

}
