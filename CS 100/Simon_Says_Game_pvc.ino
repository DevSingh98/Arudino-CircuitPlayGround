#include <Adafruit_CircuitPlayground.h>

int stage = 1;
int simonsColor[5],simonCT = 0;
int playersColor[5]; 
bool playstartupsound = true;
//int simonsColorDW[]= {0,1,2,3};
bool playersTurnSound = true;
int color = -1;
int red = 0;
int green = 1;
int yellow = 2;
int blue = 3;
bool playersLoseSound = true;
bool winSound = true;
int count = 0; 
void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  randomSeed(analogRead(0));
  pinMode(3, OUTPUT);      
  pinMode(2, OUTPUT);     
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(10, INPUT);      
  pinMode(9, INPUT);     
  pinMode(6, INPUT);
  pinMode(12, INPUT);
  }

void loop() {
  // put your main code here, to run repeatedly:
  if (stage == 1){
    startscreen();
  }
  if (stage == 2){
    gamescreenPVC();
  }
  if (stage == 3){
    playersTurn();
  }
  if (stage == 4){
    endscreen();
  }
}

void startscreen(){
   if(CircuitPlayground.leftButton()==1 || CircuitPlayground.rightButton()==1){
  stage = 2;
  }
for(int x = 0; x < 10; x++){
  CircuitPlayground.clearPixels();
  CircuitPlayground.setPixelColor(x,255,0,0);
  CircuitPlayground.setPixelColor(x+1,200,0,0);
  CircuitPlayground.setPixelColor(x+2,150,0,0);
  CircuitPlayground.setPixelColor(x+3,100,0,0);
  CircuitPlayground.setPixelColor(x+4,50,0,50);
  CircuitPlayground.setPixelColor(x+5,0,0,100);
  CircuitPlayground.setPixelColor(x+6,0,0,150);
  CircuitPlayground.setPixelColor(x+7,0,0,200);
  CircuitPlayground.setPixelColor(x+8,0,0,255);
  delay(250);
     if(CircuitPlayground.leftButton()==1 || CircuitPlayground.rightButton()==1){
  stage = 2;
  }
  
  }

}

void gamescreenPVC(){
  if(playstartupsound == true){
  CircuitPlayground.playTone(300, 500);
  delay(50);
  CircuitPlayground.playTone(400, 500);
  delay(50);
  CircuitPlayground.playTone(500, 500);
  playstartupsound = false;
  }
  // Tones ^^

  // Simons Random Colors
if(simonCT == 5){
  stage = 3;
  simonCT = 0;
}
else{
  simonsColor[simonCT]= random(0,3);
    CircuitPlayground.clearPixels();
    delay(400);
    CircuitPlayground.setPixelColor(simonsColor[simonCT],255,0,0);
    digitalWrite(simonsColor[simonCT],HIGH);
    delay(400);
    CircuitPlayground.clearPixels();
    digitalWrite(simonsColor[simonCT],LOW);
    simonCT++;
  
}
}

void playersTurn (){
  if(playersTurnSound == true){
  CircuitPlayground.playTone(300, 2000);
  delay(50);
  Serial.println("Did we get this far?");
  playersTurnSound = false;
  }
  while (simonCT < 5){
    color = -1;
    while(color < 0){
      delay(200);
      if(digitalRead(12)==1){
        Serial.println("red!");
        color=red;
      }
      if(digitalRead(6)==1){
        Serial.println("green!");
        color=green;
      }
      if(digitalRead(9)==1){
        Serial.println("yellow");
        color=yellow;
      }
      if(digitalRead(10)==1){
        Serial.println("blue");
        color=blue;
      }
    }
    Serial.println(simonsColor[0]);
    Serial.println( color);
    if (color == simonsColor[simonCT])
    {
      simonCT++;
      count ++;
    }
    else{
      // You lose
      // break out of game
     
    for(int x = 0; x < count; x++){
  CircuitPlayground.clearPixels();
  CircuitPlayground.setPixelColor(x,255,255,255);
  CircuitPlayground.setPixelColor(x,255,255,255);
  CircuitPlayground.setPixelColor(x,255,255,255);
  CircuitPlayground.setPixelColor(x,255,255,255);
  CircuitPlayground.setPixelColor(x,255,255,255);
  CircuitPlayground.setPixelColor(x,255,255,255);
  CircuitPlayground.setPixelColor(x,255,255,255);
  CircuitPlayground.setPixelColor(x,255,255,255);
  CircuitPlayground.setPixelColor(x,255,255,255);
  delay(250);
  }
   if(playersLoseSound == true){
        CircuitPlayground.playTone(800, 500);
        delay(50);
        CircuitPlayground.playTone(500, 500);
        delay(50);
        CircuitPlayground.playTone(200, 500);
        playersLoseSound = false;
    } 
  }
  stage =4;

      }
  
}

void endscreen(){
   if(winSound == true){
    CircuitPlayground.playTone(800, 500);
    delay(50);
    CircuitPlayground.playTone(300, 500);
    delay(50);
    CircuitPlayground.playTone(800, 500);
    winSound = false;
    
  }
  for(int x = 0; x < count; x++){
  CircuitPlayground.clearPixels();
  CircuitPlayground.setPixelColor(x,255,0,0);
  CircuitPlayground.setPixelColor(x+1,200,0,0);
  CircuitPlayground.setPixelColor(x,150,0,0);
  CircuitPlayground.setPixelColor(x,100,0,0);
  CircuitPlayground.setPixelColor(x,50,0,50);
  CircuitPlayground.setPixelColor(x,0,0,100);
  CircuitPlayground.setPixelColor(x,0,0,150);
  CircuitPlayground.setPixelColor(x,0,0,200);
  CircuitPlayground.setPixelColor(x,0,0,255);
  delay(250);
  }
}



