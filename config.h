#ifndef CONFIG_H
#define CONFIG_H

/* ===============================
   HARDWARE PIN DEFINITIONS
   =============================== */

#define RED_NS        14
#define YELLOW_NS     12
#define GREEN_NS      13

#define RED_EW        25
#define YELLOW_EW     26
#define GREEN_EW      27

#define CROSSWALK_BTN 19
#define EMERGENCY_LED 16
#define BUZZER_PIN    32

/* ===============================
   TIMING CONSTANTS (ms)
   =============================== */

#define GREEN_DURATION     2000
#define YELLOW_DURATION    2000
#define RED_CLEAR_DELAY    1000
#define PEDESTRIAN_TIME    15000
#define EMERGENCY_BLINK    500

/* ===============================
   MQTT CONFIGURATION
   =============================== */

#define MQTT_PORT      1883
#define MQTT_TOPIC_CMD "traffic/control"
#define MQTT_CMD_ON    "ON"
#define MQTT_CMD_OFF   "OFF"

/* ===============================
   SYSTEM MODES
   =============================== */

enum SystemState {
  INIT,
  NORMAL_NS_GREEN,
  NORMAL_NS_YELLOW,
  NORMAL_EW_GREEN,
  NORMAL_EW_YELLOW,
  PEDESTRIAN_WAIT,
  PEDESTRIAN_CROSS,
  EMERGENCY_OVERRIDE
};

#endif
