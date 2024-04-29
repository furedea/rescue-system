#pragma once

#include "EthernetInterface.h"
#include "mbed.h"

class MessageManager {
    public:
        MessageManager();
        void waitForConnecting();
        bool isReceivedMessage();

        void connectWithServer();
        void sendMessage();

    private:
        TCPSocketServer server;
        TCPSocketConnection socket;
        const int port;
        const int timeout_ms;

        const char* server_address;
};
