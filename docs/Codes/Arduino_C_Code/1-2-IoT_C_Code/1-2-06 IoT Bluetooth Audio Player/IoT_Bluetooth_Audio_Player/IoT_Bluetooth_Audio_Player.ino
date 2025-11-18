/*
 * Filename: IoT Bluetooth Audio Player
 * Function: Bluetooth controls the passive buzzer to play music
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/

// ==> Example to use built in DAC of ESP32

#include "BluetoothA2DPSink.h"

BluetoothA2DPSink a2dp_sink;

int LEDC_CHANNEL_0 = 0; // The LEDC timer uses channel 0

int LEDC_TIMER_13_BIT = 12; // LEDC timer uses 12-bit precision

const int BUZZER_PIN = 25; // Define tool I/O ports

// Create a music melody list
int melody[] = {330,330,330,262,330,392,196,262,196,165,220,247,233,220,196,330,392,440,349,392,330,262,294,247,262,196,165,220,247,233,220,196,330,392,440,349,392,330,262,294,247,392,370,330,311,330,208,220,262,220,262,294,392,370,330,311,330,523,523,523,392,370,330,311,330,208,220,262,220,262,294,311,294,262,262,262,262,262,294,330,262,220,196,262,262,262,262,294,330,262,262,262,262,294,330,262,220,196,330,330,330,262,330,392,196,262,196,165,220,247,233,220,196,330,392,440,349,392,330,262,294,247,262,196,165,220,247,233,220,196,330,392,440,349,392,330,262,294,247,392,370,330,311,330,208,220,262,220,262,294,392,370,330,311,330,523,523,523,392,370,330,311,330,208,220,262,220,262,294,311,294,262,262,262,262,262,294,330,262,220,196,262,262,262,262,294,330,262,262,262,262,294,330,262,220,196};

// Create a list of tone durations
int noteDurations[] = {8,4,4,8,4,2,2,3,3,3,4,4,8,4,8,8,8,4,8,4,3,8,8,3,3,3,3,4,4,8,4,8,8,8,4,8,4,3,8,8,2,8,8,8,4,4,8,8,4,8,8,3,8,8,8,4,4,4,8,2,8,8,8,4,4,8,8,4,8,8,3,3,3,1,8,4,4,8,4,8,4,8,2,8,4,4,8,4,1,8,4,4,8,4,8,4,8,2,8,4,4,8,4,2,2,3,3,3,4,4,8,4,8,8,8,4,8,4,3,8,8,3,3,3,3,4,4,8,4,8,8,8,4,8,4,3,8,8,2,8,8,8,4,4,8,8,4,8,8,3,8,8,8,4,4,4,8,2,8,8,8,4,4,8,8,4,8,8,3,3,3,1,8,4,4,8,4,8,4,8,2,8,4,4,8,4,1,8,4,4,8,4,8,4,8,2};


void setup() {
  const i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN),
    .sample_rate = 44100,                          // corrected by info from bluetooth
    .bits_per_sample = (i2s_bits_per_sample_t)16,  //the DAC module will only take the 8bits from MSB
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = (i2s_comm_format_t)I2S_COMM_FORMAT_STAND_MSB,
    .intr_alloc_flags = 0,  // default interrupt priority
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false
  };

  a2dp_sink.set_i2s_config(i2s_config);
  a2dp_sink.start("ESP32_Bluetooth");

  pinMode(BUZZER_PIN, OUTPUT);  // Set the buzzer to output mode
}

void loop() {
  int noteDuration;  // Create a variable noteDuration
  for (int i = 0; i < sizeof(noteDurations); ++i){
      noteDuration = 800/noteDurations[i];
      ledcSetup(LEDC_CHANNEL_0, melody[i]*2, LEDC_TIMER_13_BIT);
      ledcAttachPin(BUZZER_PIN, LEDC_CHANNEL_0);
      ledcWrite(LEDC_CHANNEL_0, 50);
      delay(noteDuration * 1.30);  // delay
  }
}
