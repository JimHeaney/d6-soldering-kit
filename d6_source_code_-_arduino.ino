//D6 Soldering Kit
//Version 1.3, Dec 2020
//Designed by: Jim Heaney
//CC-BY-SA-NC 4.0

//Designed to be run on AtTiny 45 or AtTiny 85

int result = 0;
long seed = 0;

int dt = 50;

void setup() {
  // put your setup code here, to run once:

  //Temporarily read the floating voltage on one of the pins
  pinMode(2, INPUT);

  //Get Seed
  seed = analogRead(2);

  //Seed RNG
  randomSeed(seed);
  
  //Determine Random Number
  result = random(1,7);

  //Set pins as outputs
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  //Starting Code:
  delay(50);
  cycle(2);
  dt = dt + 50;
  cycle(1);
  dt = dt + 50;
  cycle(1);


  //Count to and hold the final number
    digitalWrite(3, HIGH);
    digitalWrite(0, LOW);
    delay(200);
    if (result == 1){
      finish();
    }
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    delay(200);
    if (result == 2){
      finish();
    }
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    delay(200);
    if (result == 3){
      finish();
    }
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(0, LOW);
    delay(200);
    if (result == 4){
      finish();
    }
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    delay(200);
    if (result == 5){
      finish();
    }
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    delay(200);
    if (result == 6){
      finish();
    }
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
  
}

void finish() {
  //Pretty much do nothing but keep the LED on.
  while (1 == 1){
    delay(1000);
  }
}
void cycle(int x){
  //Scroll through all the LEDs, delaying between them. 
  for(int i = 0; i < x; i++){
    digitalWrite(3, HIGH);
    digitalWrite(0, LOW);
    delay(dt);
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    delay(dt);
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    delay(dt);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(0, LOW);
    delay(dt);
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    delay(dt);
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    delay(dt);
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
  }
}
