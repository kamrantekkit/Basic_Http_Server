//
// Created by mdkam on 30/12/2024.
//

#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <string>

class TCPServer {
    public: std::string responseMessage = "Hello from LTDU unit!";

    int startServer(const char *port, const std::string &responseMessage);
};
#endif //TCPSERVER_H
