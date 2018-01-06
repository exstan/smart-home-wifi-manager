#include <SmartHomeWiFiManager.h>

SmartHomeWiFiManager smartHomeWiFiManager;

#define WIFI_AP_SSID "my_esp_ap_name"
#define WIFI_AP_PASSWORD "myEspApPassword"

void setup() {
  smartHomeWiFiManager.init(WIFI_AP_SSID, WIFI_AP_PASSWORD);

  // or smartHomeWiFiManager.init();
  // or smartHomeWiFiManager.init(WIFI_AP_SSID); // not secured
  smartHomeWiFiManager.connect();
}

void loop() {
  smartHomeWiFiManager.reconnectIfNeeded();

  // Do something
}
