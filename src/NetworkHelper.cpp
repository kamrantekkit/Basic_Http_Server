//
// Created by mdkam on 31/12/2024.
//

#include <NetworkHelper.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void *get_in_addr(sockaddr *sa) {
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in *) sa)->sin_addr);
    }
    return &(((struct sockaddr_in6 *) sa)->sin6_addr);
}
