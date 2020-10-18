#include "Notes.h"
/////////////////////////
const int range = 1;
const int buzzerPin = A0;
const int keyPadPin = A1;
int speed=99;
int keyIn = 0;
bool inputNeeded = true;
/////////////////////////

int keyVals [16] = 
{
  101, 175, 347, 107, 
  180, 350, 116, 188, 
  355, 194, 515, 518,
  520, 523, 124, 359
};
char keys[17] = 
{
  '1', '2', '3', '4', 
  '5', '6', '7', '8',
  '9', '0', 'A', 'B', 
  'C', 'D', '*', '#'
};
/////////////////////////
String initialMessage = "Chose a melody:\n" 
                         "1. Harry Potter\n"
                         "2. Star Wars Main Theme\n"
                         "3. Imperial March\n"
                         "4. Mario Main Theme\n"
                         "5. Cantina Band\n"; 
/////////////////////////
int HarryPotterMelodie[] = 
{
  NOTE_E3, NOTE_A3, NOTE_C4, NOTE_B3, NOTE_A3, NOTE_E4, NOTE_D4, NOTE_B3,
  NOTE_A3, NOTE_C4, NOTE_B3, NOTE_G3, NOTE_AS3, NOTE_E3, 
  NOTE_E3, NOTE_A3, NOTE_C4, NOTE_B3, NOTE_A3, NOTE_E4, NOTE_G4, NOTE_FS4, NOTE_F4,
  NOTE_CS4, NOTE_F4, NOTE_E4, NOTE_DS4, NOTE_DS3, NOTE_C4,NOTE_A3, END
};

int HarryPotterNoteDurations[] = 
{
  4, 6, 2, 4, 8, 4, 10, 10,
  6, 2, 4, 8, 4, 12,
  4, 6, 2, 4, 8, 4, 8, 4, 8, 4, 
  4, 2, 4, 8, 4, 12
};

int StarWarsMainThemeMelodie[] = 
{
  NOTE_D3, NOTE_D3, NOTE_D3, NOTE_G3, NOTE_D4, 
  NOTE_C4, NOTE_B3, NOTE_A3, NOTE_G4, NOTE_D4,
  NOTE_C4, NOTE_B3, NOTE_A3, NOTE_G4, NOTE_D4,
  NOTE_C4, NOTE_B3, NOTE_C4, NOTE_A3, END
};
int StarWarsMainThemeNoteDurations[] = 
{
  2, 2, 2, 8, 8, 
  2, 2, 2, 8, 4,
  2, 2, 2, 8, 4,
  2, 2, 2, 8
};
int ImperialMarchMelodie[] = 
{
  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_F3, NOTE_C4, NOTE_A3, NOTE_F3, NOTE_C4, NOTE_A3, Pause,
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_C4, NOTE_GS3, NOTE_F3, NOTE_C4, NOTE_A3,Pause,
  NOTE_A4, NOTE_A3, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_FS4, NOTE_F4, NOTE_FS4, NOTE_AS3, NOTE_DS4,
  NOTE_D4, NOTE_CS4, NOTE_C4, NOTE_B3, NOTE_C4, NOTE_F3, NOTE_GS3, NOTE_F3, NOTE_GS3, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_E4, END
  
};

int ImperialMarchNoteDurations[] = 
{
  8, 8, 8, 6, 2, 8, 6, 2, 8, 8,
  8, 8, 8, 6, 2, 8, 6, 2, 8, 8,
  8, 8, 8, 6, 2, 2, 2, 8, 4, 8, 8,
  8, 2, 2, 8, 4, 8, 6, 4, 8, 8, 2, 6, 1
};
int MarioMainThemeMelody[] = 
{
    NOTE_E4, NOTE_E4, Pause, NOTE_E4, Pause, NOTE_C4, NOTE_E4, Pause, NOTE_G4, Pause, NOTE_G3, END
};
int MarioMainThemeNoteDurations[] = 
{
  2, 2, 2, 2, 2, 2, 2, 2, 2, 6, 2, 2,
  
};
int CantinaBandMelody[] = 
{
    NOTE_A3, Pause,   NOTE_D4, Pause,   NOTE_A3,  Pause,   NOTE_D4, Pause,    NOTE_A3,  NOTE_D4, NOTE_A3,  NOTE_GS3, NOTE_A3, NOTE_A3,  NOTE_GS3, NOTE_A3, NOTE_G3, NOTE_F3,  NOTE_G3, NOTE_FS3, NOTE_F3,  NOTE_D3, 
    NOTE_A3, Pause,   NOTE_D4, Pause,   NOTE_A3,  Pause,   NOTE_D4, Pause,    NOTE_A3,  NOTE_D4, NOTE_A3,  NOTE_G3,  NOTE_A3, NOTE_G3,  NOTE_G3,  Pause,   NOTE_G3, NOTE_FS3, NOTE_G3, NOTE_C4,  NOTE_AS3, NOTE_A3, NOTE_G3, Pause,
    NOTE_A3, Pause,   NOTE_D4, Pause,   NOTE_A3,  Pause,   NOTE_D4, Pause,    NOTE_A3,  NOTE_D4, Pause,    NOTE_A3,  NOTE_G3, NOTE_A3,  NOTE_C4,  NOTE_C4, NOTE_A3, NOTE_G3,  NOTE_F3, NOTE_D3,  NOTE_D3,  NOTE_F3, NOTE_A3,
    NOTE_C4, NOTE_E4, NOTE_D4, Pause,   NOTE_GS3, NOTE_A3, Pause,
    NOTE_A3, Pause,   NOTE_F3, NOTE_A3, Pause,    NOTE_A3, Pause,   NOTE_F3,  NOTE_A3,  Pause,   NOTE_A3,  Pause,   NOTE_F3,  NOTE_GS3, NOTE_A3,  NOTE_F3, NOTE_D3, Pause,
    NOTE_A3, Pause,   NOTE_F3, NOTE_A3, Pause,    NOTE_A3, Pause,   NOTE_F3,  NOTE_A3,  Pause,   NOTE_A3,  Pause,   NOTE_F3,  NOTE_GS3, NOTE_A3,  Pause,   NOTE_G3,  NOTE_C3, Pause,
    NOTE_A3, Pause,   NOTE_F3, NOTE_A3, Pause,    NOTE_A3, Pause,   NOTE_F3,  NOTE_A3,  Pause,   NOTE_A3,  Pause,   NOTE_F3,  NOTE_GS3, NOTE_A3,  NOTE_F3, NOTE_D3, Pause,
    NOTE_AS2,NOTE_D3, NOTE_F3, Pause,   NOTE_B2,  NOTE_D3, NOTE_F3, Pause,    NOTE_GS4, NOTE_A4, NOTE_F4,  Pause,   NOTE_D3,  NOTE_G3,  NOTE_AS3, NOTE_D4, NOTE_GS4, NOTE_A4, NOTE_F4,
    NOTE_F3, END
    
};
int CantinaBandNoteDurations [] =
{
   2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4 ,2 ,4, 2, 2, 2, 4, 2, 2, 2, 6, 8,
   2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2, 4, 2, 4, 2, 2, 4, 2, 4, 4, 4, 2,
   2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 4, 4, 6, 2, 4, 6, 10,8, 8, 8, 8, 4, 4, 2 ,2 ,4 ,20,
   2, 2, 2, 2, 8, 2, 2, 2, 2, 8, 2, 2, 2, 2, 2, 4, 6, 8, 4,
   2, 2, 2, 2, 8, 2, 2, 2, 2, 8, 2, 2, 2, 2, 2, 4, 6, 10, 4,
   2, 2, 2, 2, 8, 2, 2, 2, 2, 8, 2, 2, 2, 2, 2, 4, 6, 10, 2,
   2, 2, 2, 4, 2, 2, 2, 4, 2, 4, 4, 6, 2, 2, 2, 2, 2, 4, 8, 2, 1  
};
/////////////////////////

void setup() 
{
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(keyPadPin, INPUT);
}

void loop() 
{
  char userChoice = ' ';
  while(inputNeeded == true)
  {
    Serial.println(initialMessage);
    while(userChoice == ' ')
    {  
      userChoice = userInput();
    }
    delay(500);
    switch(userChoice)
    {
        case '6': case '7': case '8': case '9': case '0': case 'A': case 'B': case 'C': case 'D': case '*': case '#':
        Serial.print(userChoice);
        Serial.println(". is not a listed choice\n");
        userChoice = ' ';
        break;
      default:
        inputNeeded = false;
        Serial.print(userChoice);
        Serial.println(". Great choice");
        break;
    }
  }  
  MusicChoise(userChoice); 
  inputNeeded = true;  
}

char userInput()
{
  keyIn = analogRead(keyPadPin);
  char temp = ' ';
  for(int i=0; i<=15; i++)
  {
    if(keyIn >= keyVals[i]-range && keyIn <= keyVals[i]+range)
    {
      temp = keys[i]; 
    }  
  }
  return temp;
}

void MusicChoise(char choice)
{
   if(choice == '1')
   {
      Serial.println("Hey Harry you are a wizard");
      for (int thisNote = 0; HarryPotterMelodie[thisNote]!=-1; thisNote++) 
      {
          int noteDuration = speed*HarryPotterNoteDurations[thisNote];
          tone(buzzerPin, HarryPotterMelodie[thisNote],noteDuration*.95);         
          delay(noteDuration);
          noTone(buzzerPin);
      }
   }

   if(choice == '2')
   {
     Serial.println("May the 4th be with you ;)");
     for (int thisNote = 0; StarWarsMainThemeMelodie[thisNote]!=-1; thisNote++) 
      {
          int noteDuration = speed*StarWarsMainThemeNoteDurations[thisNote];
          tone(buzzerPin, StarWarsMainThemeMelodie[thisNote],noteDuration*.95);        
          delay(noteDuration);
          noTone(buzzerPin);
      }
      
   }

   if(choice == '3')
   {
      Serial.println("Luke I am your father"); 
      for (int thisNote = 0; ImperialMarchMelodie[thisNote]!=-1; thisNote++) 
      {
          int noteDuration = speed*ImperialMarchNoteDurations[thisNote];
          tone(buzzerPin, ImperialMarchMelodie[thisNote],noteDuration*.95);         
          delay(noteDuration);
          noTone(buzzerPin);
      }   
   }

   if(choice == '4')
   {
      Serial.println("Hello! It's a me, Mario!"); 
      for (int thisNote = 0; MarioMainThemeMelody[thisNote]!=-1; thisNote++) 
      {
          int noteDuration = speed*MarioMainThemeNoteDurations[thisNote];
          tone(buzzerPin, MarioMainThemeMelody[thisNote],noteDuration*.95);   
          delay(noteDuration);
          noTone(buzzerPin);
      }      
   }
   if(choice == '5')
   {
      speed = 70;
      Serial.println(""); 
      for (int thisNote = 0; CantinaBandMelody[thisNote]!=-1; thisNote++) 
      {
          int noteDuration = speed*CantinaBandNoteDurations[thisNote];
          tone(buzzerPin, CantinaBandMelody[thisNote],noteDuration*.95);   
          delay(noteDuration);
          noTone(buzzerPin);
      }  
      speed = 99;    
   }
      
}
