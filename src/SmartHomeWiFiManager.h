#ifndef SMART_HOME_WIFI_MANAGER_H
#define SMART_HOME_WIFI_MANAGER_H

#include <ESP8266WiFi.h> // https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <RemotePrint.h> // https://github.com/exstan/smart-home-remote-print

class SmartHomeWiFiManager {
public:

  void init(String apSSID     = "",
            String apPassword = "");
  void connect();
  void reconnectIfNeeded();

private:

  WiFiManager wifiManager;
  String apSSID;
  String apPassword;
};

#endif // ifndef SMART_HOME_WIFI_MANAGER_H
