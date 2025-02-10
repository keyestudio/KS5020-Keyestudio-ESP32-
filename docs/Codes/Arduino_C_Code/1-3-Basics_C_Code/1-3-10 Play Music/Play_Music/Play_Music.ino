/*
 * Filename: Play music
 * Function: passive buzzer plays music
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
int LEDC_CHANNEL_0 = 0; // The LEDC timer uses channel 0

int LEDC_TIMER_13_BIT = 8; // LEDC timer uses 8-bit precision

const int BUZZER_PIN = 13; // Defines tool I/O ports

// Create a music melody list
int melody[] = {330,330,330,262,330,392,196,262,196,165,220,247,233,220,196,330,392,440,349,392,330,262,294,247,262,196,165,220,247,233,220,196,330,392,440,349,392,330,262,294,247,392,370,330,311,330,208,220,262,220,262,294,392,370,330,311,330,523,523,523,392,370,330,311,330,208,220,262,220,262,294,311,294,262,262,262,262,262,294,330,262,220,196,262,262,262,262,294,330,262,262,262,262,294,330,262,220,196};

// Create a list of tone durations
int noteDurations[] = {8,4,4,8,4,2,2,3,3,3,4,4,8,4,8,8,8,4,8,4,3,8,8,3,3,3,3,4,4,8,4,8,8,8,4,8,4,3,8,8,2,8,8,8,4,4,8,8,4,8,8,3,8,8,8,4,4,4,8,2,8,8,8,4,4,8,8,4,8,8,3,3,3,1,8,4,4,8,4,8,4,8,2,8,4,4,8,4,1,8,4,4,8,4,8,4,8,2};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);  // Set the buzzer to output mode
}

void loop() {
  int noteDuration;  // Create a variable called noteDuration
  for (int i = 0; i < sizeof(noteDurations); ++i){
      noteDuration = 800/noteDurations[i];
      ledcSetup(LEDC_CHANNEL_0, melody[i]*2, LEDC_TIMER_13_BIT);
      ledcAttachPin(BUZZER_PIN, LEDC_CHANNEL_0);
      ledcWrite(LEDC_CHANNEL_0, 50);
      delay(noteDuration * 1.30);  // Delay
  }
}
