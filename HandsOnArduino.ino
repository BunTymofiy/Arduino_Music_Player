#include "Notes.h"
/////////////////////////
const int range = 1;
const int buzzerPin = A0;
const int keyPadPin = A1;
int speed=99;
int keyIn = -1;
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
                         "3. Imperial March"; 
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
      case '4': case '5': case '6': case '7': case '8': case '9': case '0': case 'A': case 'B': case 'C': case 'D': case '*': case '#':
        Serial.print(userChoice);
        Serial.println(". is not a listed choice");
        userChoice = ' ';
        break;
      default:
        inputNeeded = false;
        Serial.print(userChoice);
        Serial.print(". Great choice");
        break;
    }
  }  
  MusicChoise(userChoice);
  inputNeeded == true;
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
      for (int thisNote = 0; HarryPotterMelodie[thisNote]!=-1; thisNote++) 
      {
          int noteDuration = speed*HarryPotterNoteDurations[thisNote];
          tone(buzzerPin, HarryPotterMelodie[thisNote],noteDuration*.95);
          Serial.println(HarryPotterMelodie[thisNote]);
          delay(noteDuration);
          noTone(buzzerPin);
      }
   }

   if(choice == '2')
   {
     for (int thisNote = 0; StarWarsMainThemeMelodie[thisNote]!=-1; thisNote++) 
      {
          int noteDuration = speed*StarWarsMainThemeNoteDurations[thisNote];
          tone(buzzerPin, StarWarsMainThemeMelodie[thisNote],noteDuration*.95);
          Serial.println(StarWarsMainThemeMelodie[thisNote]);
          delay(noteDuration);
          noTone(buzzerPin);
      }
   }

   if(choice == '3')
   {
      for (int thisNote = 0; ImperialMarchMelodie[thisNote]!=-1; thisNote++) 
      {
          int noteDuration = speed*ImperialMarchNoteDurations[thisNote];
          tone(buzzerPin, ImperialMarchMelodie[thisNote],noteDuration*.95);
          Serial.println(ImperialMarchMelodie[thisNote]);
          delay(noteDuration);
          noTone(buzzerPin);
      }
    
   }
      
}
