#include <Adafruit_NeoPixel.h>
#include <Bounce2.h>
#define PIN        12
#define NUMPIXELS 32

const int ROWS = 5;
const int COLS = 4;
char keys[ROWS][COLS] = {
  {'A', 'B', 'C', 'D'},
  {'E', 'F', 'G', 'H'},
  {'J', 'K', 'N', 'P'},
  {'I', 'L', 'M', 'O'},
  {'Q', 'R', 'S', 'Z'}
};
int rowPins[ROWS] = {2, 3, 4, 5, 10};
int colPins[COLS] = {6, 7, 8, 9};

Bounce debouncers[ROWS][COLS];

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r12 = 0, r13 = 0, r14 = 0, r15 = 0, r16 = 0;
int b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0, b7 = 0, b8 = 0, b9 = 0, b10 = 0, b11 = 0, b12 = 0, b13 = 0, b14 = 0, b15 = 0, b16 = 0;
int g1 = 0, g2 = 0, g3 = 0, g4 = 0, g5 = 0, g6 = 0, g7 = 0, g8 = 0, g9 = 0, g10 = 0, g11 = 0, g12 = 0, g13 = 0, g14 = 0, g15 = 0, g16 = 0;

// Serial buffer variables
char serialBuffer[256];
int bufferIndex = 0;

void setup()
{
  pixels.begin();
  Serial.begin(9600);
  while (!Serial);

  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      pinMode(colPins[c], OUTPUT);
      digitalWrite(colPins[c], HIGH);
      pinMode(rowPins[r], INPUT_PULLUP);
      debouncers[r][c].attach(rowPins[r]);
      debouncers[r][c].interval(10);
    }
  }
}

void loop()
{
  pixels.clear(); 

  for (int c = 0; c < COLS; c++) {
    digitalWrite(colPins[c], LOW);
    for (int r = 0; r < ROWS; r++) {
      debouncers[r][c].update();
      if (debouncers[r][c].fell()) {
        Serial.println(keys[r][c]);
      }
    }
    digitalWrite(colPins[c], HIGH);
  } 

  // Read incoming serial data into the buffer
  while (Serial.available()) {
    char incomingChar = Serial.read();
    if (incomingChar == '\n') {
      // End of a message, process the buffer
      serialBuffer[bufferIndex] = '\0';  // Null-terminate the buffer
      processSerialData(serialBuffer);   // Process the received data
      bufferIndex = 0;                   // Reset the buffer index
    } else {
      // Add the character to the buffer
      serialBuffer[bufferIndex] = incomingChar;
      bufferIndex++;
      if (bufferIndex >= sizeof(serialBuffer) - 1) {
        // Buffer overflow, reset the buffer
        bufferIndex = 0;
      }
    }
  }

  // Update the NeoPixel colors
  pixels.setPixelColor(0, pixels.Color(r1, g1, b1));
  pixels.setPixelColor(2, pixels.Color(r2, g2, b2));
  pixels.setPixelColor(4, pixels.Color(r3, g3, b3));
  pixels.setPixelColor(6, pixels.Color(r4, g4, b4));
  pixels.setPixelColor(8, pixels.Color(r5, g5, b5));
  pixels.setPixelColor(10, pixels.Color(r6, g6, b6));
  pixels.setPixelColor(12, pixels.Color(r7, g7, b7));
  pixels.setPixelColor(14, pixels.Color(r8, g8, b8));
  pixels.setPixelColor(16, pixels.Color(r9, g9, b9));
  pixels.setPixelColor(18, pixels.Color(r10, g10, b10));
  pixels.setPixelColor(20, pixels.Color(r11, g11, b11));
  pixels.setPixelColor(22, pixels.Color(r12, g12, b12));
  pixels.setPixelColor(24, pixels.Color(r13, g13, b13));
  pixels.setPixelColor(26, pixels.Color(r14, g14, b14));
  pixels.setPixelColor(28, pixels.Color(r15, g15, b15));
  pixels.setPixelColor(30, pixels.Color(r16, g16, b16));
  pixels.show();
}

void processSerialData(char* data)
{
  int state = atoi(data);
  
  // Handle different states
if (state == 1) r1 = 150;
if (state == 2) g1 = 150;
if (state == 3) b1 = 150;
if (state == 4) r1 = 0, b1 = 0, g1 = 0;

if (state == 5) r2 = 150;
if (state == 6) g2 = 150;
if (state == 7) b2 = 150;
if (state == 8) r2 = 0, b2 = 0, g2 = 0;

if (state == 9) r3 = 150;
if (state == 10) g3 = 150;
if (state == 11) b3 = 150;
if (state == 12) r3 = 0, b3 = 0, g3 = 0;

if (state == 13) r4 = 150;
if (state == 14) g4 = 150;
if (state == 15) b4 = 150;
if (state == 16) r4 = 0, b4 = 0, g4 = 0;

if (state == 17) r5 = 150;
if (state == 18) g5 = 150;
if (state == 19) b5 = 150;
if (state == 20) r5 = 0, b5 = 0, g5 = 0;

if (state == 21) r6 = 150;
if (state == 22) g6 = 150;
if (state == 23) b6 = 150;
if (state == 24) r6 = 0, b6 = 0, g6 = 0;

if (state == 25) r7 = 150;
if (state == 26) g7 = 150;
if (state == 27) b7 = 150;
if (state == 28) r7 = 0, b7 = 0, g7 = 0;

if (state == 29) r8 = 150;
if (state == 30) g8 = 150;
if (state == 31) b8 = 150;
if (state == 32) r8 = 0, b8 = 0, g8 = 0;

if (state == 33) r9 = 150;
if (state == 34) g9 = 150;
if (state == 35) b9 = 150;
if (state == 36) r9 = 0, b9 = 0, g9 = 0;

if (state == 37) r10 = 150;
if (state == 38) g10 = 150;
if (state == 39) b10 = 150;
if (state == 40) r10 = 0, b10 = 0, g10 = 0;

if (state == 41) r11 = 150;
if (state == 42) g11 = 150;
if (state == 43) b11 = 150;
if (state == 44) r11 = 0, b11 = 0, g11 = 0;

if (state == 45) r12 = 150;
if (state == 46) g12 = 150;
if (state == 47) b12 = 150;
if (state == 48) r12 = 0, b12 = 0, g12 = 0;

if (state == 49) r13 = 150;
if (state == 50) g13 = 150;
if (state == 51) b13 = 150;
if (state == 52) r13 = 0, b13 = 0, g13 = 0;

if (state == 53) r14 = 150;
if (state == 54) g14 = 150;
if (state == 55) b14 = 150;
if (state == 56) r14 = 0, b14 = 0, g14 = 0;

if (state == 57) r15 = 150;
if (state == 58) g15 = 150;
if (state == 59) b15 = 150;
if (state == 60) r15 = 0, b15 = 0, g15 = 0;

if (state == 61) r16 = 150;
if (state == 62) g16 = 150;
if (state == 63) b16 = 150;
if (state == 64) r16 = 0, b16 = 0, g16 = 0;

  // Handle other states...

  // Reset the buffer after processing
  memset(serialBuffer, 0, sizeof(serialBuffer));
}