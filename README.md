# Automated-Traffic-Light-ESP32
ESP32-based automated traffic light control system with WiFi and MQTT support, pedestrian crosswalk handling, and emergency override functionality.
## Setup & Security

This project follows secure IoT development best practices by separating
application logic from sensitive configuration data.

### WiFi & MQTT Credentials
WiFi credentials, MQTT usernames, passwords, and certificates are **not**
stored in version control.

Create a local file named `secrets.h` inside the `src/` directory:

```cpp
#define WIFI_SSID "YOUR_WIFI_NAME"
#define WIFI_PASS "YOUR_WIFI_PASSWORD"
#define MQTT_BROKER "broker_address"
#define MQTT_USER "username"
#define MQTT_PASS "password"
