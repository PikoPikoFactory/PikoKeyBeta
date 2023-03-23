//---------------------------
//   Piko Key
//   Sample Program
//   ver 0.1
//   2023/2/23
//   by Synth Senpai
//---------------------------

#include <MIDI.h>
USING_NAMESPACE_MIDI

//*********************************
//Variable

bool sw_state[15] ;
bool note_state[15] ;
byte note_offset = 48 ;
byte channel  = 1;

// Pins
const byte LED_DN = 2;
const byte LED_UP = 3;
const byte LED_1  = 4;
const byte SW_UP  = 5;
const byte SW_DN  = 6;
const byte SW15   = 7;
const byte SW14   = 8;
const byte SW13   = 9;
const byte SW12   = 10;
const byte SW11   = 11;
const byte SW10   = 12;
const byte SW09   = 21;
const byte SW08   = 20;
const byte SW07   = 19;
const byte SW06   = 18;
const byte SW05   = 17;
const byte SW04   = 16;
const byte SW03   = 15;
const byte SW02   = 14;
const byte SW01   = 13;
byte sw_map[] = { SW01, SW02, SW03, SW04, SW05, SW06, SW07, SW08, SW09, SW10, SW11, SW12, SW13, SW14};
const byte MAXKEY = 14;

//midi
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

//*********************************************
// setup

void setup() {
  pinMode(LED_DN, OUTPUT);
  pinMode(LED_UP, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(SW_UP, INPUT_PULLUP);
  pinMode(SW_DN, INPUT_PULLUP);
  pinMode(SW15, INPUT_PULLUP);

  for ( byte i = 0 ; i < MAXKEY; i++ )
  {
    pinMode(sw_map[i], INPUT_PULLUP);
  }

  //midi
  MIDI.begin();

  //Start up Animation
  digitalWrite(LED_DN, HIGH);
  delay(200);
  digitalWrite(LED_UP, HIGH);
  delay(200);
  digitalWrite(LED_1, HIGH);
  delay(200);
  digitalWrite(LED_DN, LOW);
  delay(200);
  digitalWrite(LED_UP, LOW);
  delay(200);
  digitalWrite(LED_1, LOW);

  for ( byte i = 0 ; i < MAXKEY; i++ )
  {
    note_state[i] == true;
  }
}
// Setup end
//*********************************************

//*********************************************
// Main

void loop() {
  for ( byte i = 0 ; i < MAXKEY; i++ )
  {
    sw_state[i] =   digitalRead(sw_map[i]);
    if (sw_state[i] == false)
    {
      if (note_state[i] == true)
      {
        note_on(i);
        note_state[i] = false ;
      }
    }
    else
    {
      if (note_state[i] == false)
      {
        note_off(i);
        note_state[i] = true ;
      }
    }
  }
}

//  Main end

//********************************************
//MIDI

void note_on(byte keyno)
{
  digitalWrite(LED_1, HIGH);
  byte velocity  = 127;
  byte note;
  note = keyno + note_offset ;
  MIDI.sendNoteOn(note, velocity, channel);
}

void note_off(byte keyno)
{
  digitalWrite(LED_1, LOW);
  byte velocity  = 0;
  byte note;
  note = keyno + note_offset ;
  MIDI.sendNoteOn(note, velocity, channel);
}
