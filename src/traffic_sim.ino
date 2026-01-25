/*
 Simulation Build (Wokwi)
 - Networking disabled
 - Logic identical to hardware build
*/


// ---------- PINS ----------
const int redNS = 14;
const int yellowNS = 12;
const int greenNS = 13;

const int redEW = 25;
const int yellowEW = 26;
const int greenEW = 27;

const int crosswalkBtn = 19;

// ---------- FSM ----------
enum TrafficState {
  NS_GREEN,
  NS_YELLOW,
  EW_GREEN,
  EW_YELLOW,
  PEDESTRIAN
};

TrafficState state = NS_GREEN;
unsigned long lastChange = 0;
bool crosswalkRequested = false;

// ---------- HELPERS ----------
void setLights(bool rNS, bool yNS, bool gNS,
               bool rEW, bool yEW, bool gEW) {
  digitalWrite(redNS, rNS);
  digitalWrite(yellowNS, yNS);
  digitalWrite(greenNS, gNS);

  digitalWrite(redEW, rEW);
  digitalWrite(yellowEW, yEW);
  digitalWrite(greenEW, gEW);
}

// ---------- FSM LOGIC ----------
void updateTraffic(unsigned long now) {

  switch (state) {

    case NS_GREEN:
      setLights(LOW, LOW, HIGH, HIGH, LOW, LOW);
      if (now - lastChange >= 3000) {
        state = NS_YELLOW;
        lastChange = now;
      }
      break;

    case NS_YELLOW:
      setLights(LOW, HIGH, LOW, HIGH, LOW, LOW);
      if (now - lastChange >= 2000) {
        state = EW_GREEN;
        lastChange = now;
      }
      break;

    case EW_GREEN:
      setLights(HIGH, LOW, LOW, LOW, LOW, HIGH);
      if (now - lastChange >= 3000) {
        state = EW_YELLOW;
        lastChange = now;
      }
      break;

    case EW_YELLOW:
      setLights(HIGH, LOW, LOW, LOW, HIGH, LOW);
      if (now - lastChange >= 2000) {
        state = NS_GREEN;
        lastChange = now;
      }
      break;

    case PEDESTRIAN:
      setLights(HIGH, LOW, LOW, HIGH, LOW, LOW);
      if (now - lastChange >= 5000) {
        state = NS_GREEN;
        lastChange = now;
      }
      break;
  }
}

// ---------- SETUP ----------
void setup() {
  pinMode(redNS, OUTPUT);
  pinMode(yellowNS, OUTPUT);
  pinMode(greenNS, OUTPUT);

  pinMode(redEW, OUTPUT);
  pinMode(yellowEW, OUTPUT);
  pinMode(greenEW, OUTPUT);

  pinMode(crosswalkBtn, INPUT_PULLUP);
}

// ---------- LOOP ----------
void loop() {
  unsigned long now = millis();

  // Poll button instead of interrupt (Wokwi-safe)
  if (digitalRead(crosswalkBtn) == LOW && state != PEDESTRIAN) {
    state = PEDESTRIAN;
    lastChange = now;
  }

  updateTraffic(now);
}
