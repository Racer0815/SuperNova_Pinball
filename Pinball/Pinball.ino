#include <LiquidCrystal_I2C.h>
#include <Shiftout.h>
#include <Animator.h>

bool S_LED;
bool S_LED2;
bool S_LED3;
bool S_LED4;
bool S_LED5;
bool S_cow;
bool S_Alien;
String color = "red";

bool color_change = true;
bool flash;

int Speaker = 10;
int i;


Subanimator S_1(100);


Animator animation(0, 500);
Shiftout Registers(6, 4, 5);
LiquidCrystal_I2C lcd(0x27, 16, 2);

int Balls = 3;
int Score = 0;
int Highscore = 0;

void setup() {
  lcd.begin();
  lcd.print("Booting...");
   pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(8,HIGH);
  pinMode(3, OUTPUT);
  delay(5000);
  tone(Speaker,200);
  delay(500);
  noTone(Speaker);
  delay(500);
   tone(Speaker,200);
  delay(500);
  noTone(Speaker);
  digitalWrite(3, HIGH);
  lcd.clear();
  lcd.print("Ready to Play");
  delay(1000);
  lcd.clear();
  lcd.home();
  lcd.print("Balls: ");
  lcd.print(Balls);
  lcd.setCursor(0,1);
  lcd.print("Score: ");
  lcd.print(Score);
  Registers.Pin_HIGH(3,1);
  analogWrite(9,255);
  delay(10);
}

void loop() {
  if(Balls == -1)
  {
    Registers.Pin_LOW(3,1);
      if(Score > Highscore)
    {
    lcd.clear();
    lcd.home();
    lcd.print("Neuer Highscore");
    lcd.setCursor(0,1);
    lcd.print("Score: ");
    lcd.print(Score);
    Highscore = Score;
  tone(Speaker,261);
  delay(200);
  tone(Speaker,293);
  delay(200);
  tone(Speaker,329);
  delay(200);
   tone(Speaker,349);
  delay(200);
   tone(Speaker,391);
  delay(200);
  noTone(Speaker);
    }
    else
    {
    lcd.clear();
    lcd.home();
    lcd.print("Game Over");
    lcd.setCursor(0,1);
    lcd.print("Score: ");
    lcd.print(Score);
 for(i = 261;i > 130; i--)
 {
  tone(Speaker,i);
  delay(5);
 }
 
 noTone(Speaker);
    }
    Balls = 3;
    Score = 0;
    delay(10000);
    lcd.clear();
    lcd.home();
     lcd.print("Balls: ");
  lcd.print(Balls);
  lcd.setCursor(0,1);
  lcd.print("Score: ");
  lcd.print(Score);
  Registers.Pin_HIGH(3,1);
  }

    int i = analogRead(A0);
  if (i > 600)
  {
    S_1.reset_tick();
    if (S_LED == true)
    {
      Registers.Pin_HIGH(1, 4);
      Registers.Pin_HIGH(1, 5);
      S_LED = false;
    }
    else
    {
      Registers.Pin_LOW(1, 4);
      Registers.Pin_LOW(1, 5);
      S_LED = true;
    }
    Balls = Balls-1;
    delay(1500);
    lcd_update();
  }

  int i3 = analogRead(A1);
  if (i3 > 600)
  {
    Score = Score + 100;
    lcd_update();
    Registers.Pin_HIGH(3,5);
    if (S_LED3 == true)
    {
      Registers.Pin_HIGH(3, 2);
      Registers.Pin_HIGH(3, 3);
      S_LED3 = false;
    }
    else
    {
      Registers.Pin_LOW(3, 2);
      Registers.Pin_LOW(3, 3);
      S_LED3 = true;
    }
   for(i = 293; i >= 261; i--)
  {
    tone(Speaker,i);
    delay(5);
  }
  noTone(Speaker);
    delay(30);
    Registers.Pin_LOW(3,5);
  }



  int i2 = analogRead(A2);
  if (i2 > 600)
  {
    Score = Score + 100;
    lcd_update();
    color_change = false;
    S_LED2 = false;
  }
  else
  {
    color_change = true;
    S_LED2 = true;
  }

  if (color_change == true)
  {
    if (animation.timed(1000))
    {
      if (color == "red")
      {
        Registers.Pin_LOW(1, 2);
        Registers.Pin_LOW(1, 3);
        Registers.Pin_HIGH(1, 1);
        color = "green";
      }


      else {
        if (color == "green")
        {
          Registers.Pin_LOW(1, 1);
          Registers.Pin_LOW(1, 3);
          Registers.Pin_HIGH(1, 2);
          color = "blue";
        }

        else {
          if (color == "blue")
          {
            Registers.Pin_LOW(1, 1);
            Registers.Pin_LOW(1, 2);
            Registers.Pin_HIGH(1, 3);
            color = "red";
          }

          else {

          }
        }
      }
    }
  }
    else {
      if (flash == true)
      {
        Registers.Pin_HIGH(1, 1);
        Registers.Pin_HIGH(1, 2);
        Registers.Pin_HIGH(1, 3);
        flash = false;
        delay(15);
      }
      else {
        Registers.Pin_LOW(1, 1);
        Registers.Pin_LOW(1, 2);
        Registers.Pin_LOW(1, 3);
        flash = true;
        delay(15);
      }

    }
  

  if (animation.timed(10000))
  {
    if (S_cow == true)
    {
      Registers.Pin_HIGH(2, 0);
      S_cow = false;
    }
    else
    {
      Registers.Pin_LOW(2, 0);
      S_cow = true;
    }
  }
  if (animation.timed(600))
  {
    if (S_Alien == true)
    {
      Registers.Pin_HIGH(1, 0);
      S_Alien = false;
    }
    else
    {
      Registers.Pin_LOW(1, 0);
      S_Alien = true;
    }
  }
  if (animation.timed(400))
  {
    if (S_LED4 == true)
    {
      Registers.Pin_HIGH(1, 6);
      S_LED4 = false;
    }
    else
    {
      Registers.Pin_LOW(1, 6);
      S_LED4 = true;
    }
  }
  if (animation.timed(1100))
  {
    if (S_LED5 == true)
    {
      Registers.Pin_HIGH(3, 4);
      S_LED5 = false;
    }
    else
    {
      Registers.Pin_LOW(3, 4);
      S_LED5 = true;
    }
  }
  blink();
  if(animation.timed(50))
  {
      S_1.tick();
  }


  animation.tick();
}


void blink(){

  if(S_1.timed_once(0))
  {
    Registers.Pin_HIGH(2,1);
    Registers.Pin_LOW(2,2);
  }
    if(S_1.timed_once(5)) 
  {
    Registers.Pin_LOW(2,1);
    Registers.Pin_HIGH(2,2);
  }
    if(S_1.timed_once(10)) 
  {
    Registers.Pin_HIGH(2,1);
    Registers.Pin_LOW(2,2);
  }
    if(S_1.timed_once(15)) 
  {
    Registers.Pin_LOW(2,1);
    Registers.Pin_HIGH(2,2);
  }
    if(S_1.timed_once(20)) 
  {
    Registers.Pin_HIGH(2,1);
    Registers.Pin_LOW(2,2);
  }
    if(S_1.timed_once(25)) 
  {
    Registers.Pin_LOW(2,1);
    Registers.Pin_HIGH(2,2);
  }
    if(S_1.timed_once(30)) 
  {
    Registers.Pin_HIGH(2,1);
    Registers.Pin_LOW(2,2);
  }
  if(S_1.timed_once(35)) 
  {
    Registers.Pin_LOW(2,1);
    Registers.Pin_HIGH(2,2);
  }
    if(S_1.timed_once(40)) 
  {
    Registers.Pin_HIGH(2,1);
    Registers.Pin_LOW(2,2);
  }
  if(S_1.timed_once(45)) 
  {
    Registers.Pin_LOW(2,1);
    Registers.Pin_HIGH(2,2);
  }
    if(S_1.timed_once(50)) 
  {
    Registers.Pin_HIGH(2,1);
    Registers.Pin_LOW(2,2);
  }
  if(S_1.timed_once(55)) 
  {
    Registers.Pin_LOW(2,1);
    Registers.Pin_HIGH(2,2);
  }
    if(S_1.timed_once(60)) 
  {
    Registers.Pin_HIGH(2,1);
    Registers.Pin_LOW(2,2);
  }
  if(S_1.timed_once(65)) 
  {
    Registers.Pin_LOW(2,1);
    Registers.Pin_HIGH(2,2);
  }
    if(S_1.timed_once(70)) 
  {
    Registers.Pin_HIGH(2,1);
    Registers.Pin_LOW(2,2);
  }
  if(S_1.timed_once(75)) 
  {
    Registers.Pin_LOW(2,1);
    Registers.Pin_HIGH(2,2);
  }
    if(S_1.timed_once(80)) 
  {
    Registers.Pin_HIGH(2,1);
    Registers.Pin_LOW(2,2);
  }
  if(S_1.timed_once(85)) 
  {
    Registers.Pin_LOW(2,1);
    Registers.Pin_HIGH(2,2);
  }
    if(S_1.timed_once(90)) 
  {
    Registers.Pin_HIGH(2,1);
    Registers.Pin_LOW(2,2);
  }
  if(S_1.timed_once(95)) 
  {
    Registers.Pin_LOW(2,1);
    Registers.Pin_HIGH(2,2);
  }
    if(S_1.timed_once(100)) 
  {
    Registers.Pin_LOW(2,1);
    Registers.Pin_LOW(2,2);
  }
}

void lcd_update()
{
  Serial.println(Score);
  lcd.clear();
  lcd.home();
  lcd.print("Balls: ");
  lcd.print(Balls);
  lcd.setCursor(0,1);
  lcd.print("Score: ");
  lcd.print(Score);
}
