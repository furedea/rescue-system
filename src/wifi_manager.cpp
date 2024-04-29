#include "wifi_manager.h"

#include <cstdlib>

WifiManager::WifiManager(const char* address)
    : address(address), mask("255.255.255.0"), gateway("192.168.11.1"), ssid("CLab"), password("TeamCollaboration") {
    wlan = std::make_unique<GR_PEACH_WlanBP3595>();
    wlan.init(address, mask, gateway);
}

void WifiManager::connect() {
    if (wlan.connect(ssid, password) == -1) {
        std::exit(EXIT_FAILURE);
    }  // pc.printf("Connected with WiFi\r\n");
}
