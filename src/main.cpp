#include <TCPServer.h>
#include <UDPServer.h>


#define MYPORT "10001"
#define BACKLOG 10
#define MAXBUFLEN 100


int main(int argc, char *argv[]) {
    TCPServer tcpServer;
    tcpServer.startServer(MYPORT);

    return 0;
}





