// Handles all animations for LEDs

enum RAMP_STATES { NO_RAMP, RAMP_UP, RAMP_DOWN };

// Structure to hold the parameters for each ring
struct RingParams {
  device deviceName;               // Which system LED device 
  CRGB* ledsArray;                // Pointer to the LED array
  uint8_t numLEDs;                 // Number of LEDs in the ring
  uint16_t revolutionTime = 500;   // Time for one complete rotation, in milliseconds
  CRGB ledColor;                   // Color of the LEDs
  millisDelay ledTimer;            // Delay object for timing
  uint16_t rampTime = 6000;        // Time for ramp up/down, in milliseconds
  uint16_t rampStep = 5;           // Increase speed by some factor per LED
  uint8_t rampPercent = 0;         // Percent of ramp time completed so far
  RAMP_STATES rampState = NO_RAMP; // Current ramping state
  uint8_t currentLED = 0;          // Current LED index
  uint8_t previousLED = 0;         // Previous LED index
};

// Function to animate the LED ring
void animateRing(RingParams &ring) {
  // Calculate the delay time for each LED
  uint16_t delayTime = ring.revolutionTime / ring.numLEDs;

  // Start the delay if it hasn't been started
  if (!ring.ledTimer.isRunning()) {
    ring.ledTimer.start(delayTime);
  }

  // Check if the delay has timed out
  if (ring.ledTimer.justFinished()) {
    // Turn on the current LED using the color (with saturation and brightness) as specified
    ring.ledsArray[ring.currentLED] = ring.ledColor;
    ring.ledsArray[ring.previousLED] = CRGB::Black; // Turn off the previous pixel

    // Show changes to the LEDs
    FastLED.show();

    // Move to the next LED in the ring (starting over as necessary)
    ring.previousLED = ring.currentLED; // Remember as previous LED
    ring.currentLED = (ring.currentLED + 1) % ring.numLEDs;

    // Restart the delay
    ring.ledTimer.repeat();
  }
}

// Function to ramp up the animation speed
void ringRampUp(RingParams &ring) {
  for (uint16_t time = ring.rampTime / ring.rampStep; time <= ring.rampTime; time += (ring.rampTime / ring.rampStep)) {
    debugln(time);
    animateRing(ring);
  }
}

// Function to ramp down the animation speed
void ringRampDown(RingParams &ring) {
  for (uint16_t time = ring.rampTime; time >= ring.rampTime / ring.rampStep; time -= (ring.rampTime / ring.rampStep)) {
    animateRing(ring);
  }
}