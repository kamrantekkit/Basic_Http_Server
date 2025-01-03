#include <iostream>
#include <TCPServer.h>
#include <UDPServer.h>

#include "HttpMessage.h"


#define MYPORT "10001"
#define BACKLOG 10
#define MAXBUFLEN 100


int main(int argc, char *argv[]) {

    HttpMessage httpMessage;
    httpMessage.setHttpVersion(HttpVersion::HTTP_1_1);
    httpMessage.setHttpStatusCode(HttpStatusCode::Ok);
    httpMessage.setBody("Test");

    TCPServer tcpServer;
    tcpServer.startServer(MYPORT, httpMessage.createPayload());

    return 0;
}





