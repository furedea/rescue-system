#include "message_manager.h"

#include <cstdlib>
#include <string>

MessageManager::MessageManager()
    : server(), socket(), port(5000), timeout_ms(5000000), server_address("192.168.11.11") {}

void MessageManager::waitForConnecting() {
    server.bind(port);
    server.listen();
    server.accept(socket);  // socketへの副作用。これによるエラーが怖いためにスマートポインタを用いていない。
}

bool MessageManager::isReceivedMessage() {
    socket.set_blocking(false, timeout_ms);  // TODO: 詳細な動作不明
    char received_message[256];
    if (socket.receive(received_message, 5) <= 0) {  // received_messageへの副作用
        std::exit(EXIT_FAILURE);
    }
    return true;
}

void MessageManager::connectWithServer() {
    if (!socket.connect(server_address, port)) {
        std::exit(EXIT_FAILURE);
    }
}

void MessageManager::sendMessage() {
    char* message = "a";
    if (socket.send(message, strlen(message) <= 0) {
        std::exit(EXIT_FAILURE);
    }
}
