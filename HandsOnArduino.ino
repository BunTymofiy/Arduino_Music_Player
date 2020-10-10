#include "Notes.h"

const int notePin = 3; 
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

int speed=99;
void setup() 
{
  Serial.begin(9600);
  for (int thisNote = 0; HarryPotterMelodie[thisNote]!=-1; thisNote++) 
  {
    int noteDuration = speed*HarryPotterNoteDurations[thisNote];
    tone(3, HarryPotterMelodie[thisNote],noteDuration*.95);
    Serial.println(HarryPotterMelodie[thisNote]);

    delay(noteDuration);

    noTone(3);
  }

}

void loop() 
{
 
 
}
