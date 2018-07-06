
const int L1 = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(L1, OUTPUT); //L1 est une broche de sortie

}

void loop() {
  //contenu du programme
 saidSOS();
}


void lightOnce(int time){
  digitalWrite(L1, HIGH); //allumer L1
  delay(time); // attendre 1 seconde
  digitalWrite(L1, LOW); // Eteindre L1
  delay(time); // attendre 1 seconde
}

void saidSOS(){
   lightOnce(200);
  lightOnce(200);
  lightOnce(200);
  delay(500);
  lightOnce(800);
  lightOnce(800);
  lightOnce(800);
  lightOnce(200);
  lightOnce(200);
  lightOnce(200);
  delay(2000); // attendre 1 seconde
}





