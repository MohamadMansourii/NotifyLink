#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <vector>

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <message1> <message2> ... <IP1> [<IP2> ... <IPN>]" << std::endl;
        return 1;
    }

    // Separating messages from IPs
    std::vector<std::string> messages;
    std::vector<std::string> ipAddresses;

    // Assuming that the IPs are correctly formatted at the end of the arguments
    int i = 1;
    while (i < argc && strchr(argv[i], '.') == nullptr) {
        messages.push_back(argv[i]);
        ++i;
    }

    while (i < argc) {
        ipAddresses.push_back(argv[i]);
        ++i;
    }

    // Combining all messages into a single string
    std::string message;
    for (const auto& msg : messages) {
        message += msg + " ";
    }
    message = message.substr(0, message.size() - 1); // Remove trailing whitespace

    WSADATA wsaData;
    int result;

    result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        std::cerr << "WSAStartup failed: " << result << std::endl;
        return 1;
    }
    std::cout << "WSAStartup successful." << std::endl;

    for (const std::string& ipAddressStr : ipAddresses) {
        SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "Socket creation failed: " << WSAGetLastError() << std::endl;
            WSACleanup();
            return 1;
        }
        std::cout << "Socket creation successful for IP: " << ipAddressStr << std::endl;

        sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(9090);

        wchar_t ipAddressW[256];
        size_t convertedChars = 0;
        mbstowcs_s(&convertedChars, ipAddressW, ipAddressStr.c_str(), ipAddressStr.size() + 1);

        result = InetPtonW(AF_INET, ipAddressW, &serverAddr.sin_addr);
        if (result <= 0) {
            std::cerr << "Invalid address or address not supported: " << WSAGetLastError() << std::endl;
            closesocket(clientSocket);
            WSACleanup();
            continue;
        }
        std::cout << "IP address conversion successful for IP: " << ipAddressStr << std::endl;

        if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
            std::cerr << "Connect failed for IP: " << ipAddressStr << ". Error: " << WSAGetLastError() << std::endl;
            closesocket(clientSocket);
            WSACleanup();
            continue;
        }
        std::cout << "Connected to server at IP: " << ipAddressStr << std::endl;

        int sendSize = send(clientSocket, message.c_str(), static_cast<int>(message.size()), 0);
        if (sendSize == SOCKET_ERROR) {
            std::cerr << "Send failed for IP: " << ipAddressStr << ". Error: " << WSAGetLastError() << std::endl;
            closesocket(clientSocket);
            WSACleanup();
            continue;
        }
        std::cout << "Message sent to server at IP: " << ipAddressStr << std::endl;

        closesocket(clientSocket);
    }

    WSACleanup();
    return 0;
}
