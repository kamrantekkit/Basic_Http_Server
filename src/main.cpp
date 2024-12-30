#include <UDPServer.h>


#define MYPORT "10001"
#define BACKLOG 10
#define MAXBUFLEN 100


int main(int argc, char *argv[]) {
    UDPServer server;
    server.startServer(MYPORT);

    return 0;
}


// void *get_in_addr(struct sockaddr *sa) {
//     if (sa->sa_family == AF_INET) {
//         return &(((struct sockaddr_in *) sa)->sin_addr);
//     }
//     return &(((struct sockaddr_in6 *) sa)->sin6_addr);
// }
//
// int listenForTCP() {
//         // Create a socket
//     int socket_fd, new_fd;
//     struct addrinfo hints, *servinfo, *p;
//
//     int rv;
//     struct sockaddr_storage their_addr;
//     char buf[MAXBUFLEN];
//     socklen_t sin_size;
//     struct sigaction sa;
//     char s[INET6_ADDRSTRLEN];
//     int yes = 1;
//
//     memset(&hints, 0, sizeof hints);
//     hints.ai_family = AF_INET;
//     hints.ai_socktype = SOCK_STREAM;
//     hints.ai_flags = AI_PASSIVE; // use my IP
//
//
//     if ((rv = getaddrinfo(NULL, MYPORT, &hints, &servinfo)) != 0) {
//         fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
//         return 1;
//     }
//
//     for (p = servinfo; p != NULL; p = p->ai_next) {
//         if ((socket_fd = socket(p->ai_family, p->ai_socktype,
//                                 p->ai_protocol)) == -1) {
//             perror("listener: socket");
//             continue;
//         }
//
//         if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &yes,
//                        sizeof(int)) == -1) {
//             perror("setsockopt");
//             exit(1);
//         }
//
//         if (bind(socket_fd, p->ai_addr, p->ai_addrlen) == -1) {
//             close(socket_fd);
//             perror("listener: bind");
//             continue;
//         }
//         break;
//     }
//
//     freeaddrinfo(servinfo);
//
//     if (p == NULL) {
//         fprintf(stderr, "listener: failed to bind socket\n");
//         return 2;
//     }
//
//     if (listen(socket_fd, BACKLOG) ==-1) {
//         perror("listen message");
//         exit(1);
//     }
//
//
//
//     sin_size = sizeof their_addr;
//     new_fd = accept(socket_fd, reinterpret_cast<struct sockaddr *>(&their_addr), &sin_size);
//     if (new_fd == -1) {
//         perror("accept");
//         return 1;
//     }
//
//     inet_ntop(their_addr.ss_family,
//               get_in_addr((struct sockaddr *) &their_addr),
//               s, sizeof s);
//
//     if (send(new_fd, "Hello, world!", 13, 0) == -1)
//         perror("send");
//
//     close(new_fd);
//
//     close(socket_fd);
//
//     return 0;
// }



