// Transport keys for DAW by Damizon, tested on fruity loops.
// Switches going to pinouts D2,D3,D4,D5,D6 and GND, TX pin and +5v goes to midi port.
// MIDI Universal Real Time SysEx Message Format, MMC Message Format
// F0(240), 7F(127), <Device-ID>(127=all devices), <Sub-ID#1>(6=Command), <Sub-ID#2>, F7(247) 
// More info https://en.wikipedia.org/wiki/MIDI_Machine_Control 

// SUB-ID#2 List
// 01 Stop,02 Play, 03 Deferred Play (play after no longer busy), 04 Fast Forward, 05 Rewind, 06 Record Strobe (AKA [[Punch in/out|Punch In]]), 07 Record Exit (AKA [[Punch out (music)|Punch out]]),
// 08 Record Pause, 09 Pause (pause playback), 0A Eject (disengage media container from MMC device), 0B Chase,0D MMC Reset (to default/startup state)

void setup() {
 Serial.begin (31250); //Set bitrate for midi output
 pinMode (2, INPUT_PULLUP);
 pinMode (3, INPUT_PULLUP);
 pinMode (4, INPUT_PULLUP);
 pinMode (5, INPUT_PULLUP);
 pinMode (6, INPUT_PULLUP);
}

void midiSysEX(int dataByte1, int dataByte2, int dataByte3,int dataByte4, int dataByte5, int dataByte6) {
 Serial.write(dataByte1);
 Serial.write(dataByte2);
 Serial.write(dataByte3);
 Serial.write(dataByte4);
 Serial.write(dataByte5);
 Serial.write(dataByte6);
 }

 void loop() {
 if (digitalRead(2) == LOW){
  midiSysEX(240,127,127,6,5,247);
  delay(200);
 }
 if (digitalRead(3) == LOW){
  midiSysEX(240,127,127,6,4,247);
  delay(200);
 }
 if (digitalRead(4) == LOW){
  midiSysEX(240,127,127,6,2,247);
  delay(500);
 }
 if (digitalRead(5) == LOW){
  midiSysEX(240,127,127,6,1,247);
  delay(500);
 }
 if (digitalRead(6) == LOW){
  midiSysEX(240,127,127,6,6,247);
  delay(500);
  }
}
