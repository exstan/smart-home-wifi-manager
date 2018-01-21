#include <SmartHomeWiFiManager.h>

void SmartHomeWiFiManager::init(String apSSID,
                                String apPassword) {
  this->apSSID     = apSSID;
  this->apPassword = apPassword;

  delay(2000); // required, if missing the WiFi.status() call is returning WL_CONNECT_FAILED and stops trying to connect

  // Reset settings
  // wifiManager.resetSettings();

  wifiManager.setConnectTimeout(60);

  // Sets timeout (in seconds) until configuration portal gets turned off
  wifiManager.setConfigPortalTimeout(180);

  // Set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
  wifiManager.setAPCallback([](WiFiManager *_wifiManager) -> void {
    PRINTLN("Created WiFi Config Portal on AP \"" + String(_wifiManager->getConfigPortalSSID()) + "\"");
  });
}

void SmartHomeWiFiManager::connect() {
  // Fetches ssid and pass and tries to connect
  // If it does not connect it starts an access point with the specified name and goes into a blocking loop awaiting
  // configuration
  if (!wifiManager.autoConnect(apSSID.c_str(), apPassword.c_str())) {
    PRINTLN_E("Failed to connect WiFi and the timeout exceeded. Resetting...");
    delay(3000);

    // Reset and try again
    ESP.reset();
    delay(5000);
  }

  // Connected to WiFi is successful
  PRINTLN(
    "\nWiFi connected to SSID \"" + WiFi.SSID() + "\". IP address: " + WiFi.localIP().toString() + " Gateway: " +
    WiFi.gatewayIP().toString());
}

void SmartHomeWiFiManager::reconnectIfNeeded() {
  if (WiFi.status() != WL_CONNECTED) {
    connect();
  }
}
