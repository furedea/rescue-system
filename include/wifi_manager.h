#pragma once

#include <memory>

#include "GR_PEACH_WlanBP3595.h"

class WifiManager {
    public:
        WifiManager(const char* address);
        void connect();

    private:
        std::unique_ptr<GR_PEACH_WlanBP3595> wlan;
        const char* address;
        const char* mask;
        const char* gateway;
        const char* ssid;
        const char* password;
};
