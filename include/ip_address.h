enum class IPAddress {
    ServerAddress,
    MyAddress
};

const char* getIPAddress(IPAddress address) {
    switch (address) {
        case IPAddress::ServerAddress:
            return "192.168.11.12";
        case IPAddress::MyAddress:
            return "192.168.11.11";
    }
}
