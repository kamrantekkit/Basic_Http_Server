//
// Created by mdkam on 09/12/2024.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <netdb.h>
#include <NetworkHelper.h>
#include <string>
#include <UDPServer.h>
#include <wiringPi.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>


int MAXBUFLEN = 100;


int handleMessage(const std::string &input) {
    if (input == "red") {
        std::cout << "Turning on red led" << std::endl;
        wiringPiSetup();
        pinMode(13, OUTPUT);
        digitalWrite(13, HIGH);
        delay(5000);
        digitalWrite(13, LOW);
        pinMode(13, PM_OFF);

        return 1;
    } else if (input == "green") {
        std::cout << "Turning on green led" << std::endl;
        wiringPiSetup();
        pinMode(21, OUTPUT);
        digitalWrite(21, HIGH);
        delay(5000);
        digitalWrite(21, LOW);
        pinMode(21, PM_OFF);

        return 1;
    } else if (input == "exit") {
        return 0;
    }
    return 1;
}



int UDPServer::startServer(const char *port) {
    int sockfd; // listen on sock_fd, new connection on new_fd
    struct addrinfo hints, *servinfo, *p; // server info
    int addressInfo; // return value
    int numbytes; // number of bytes received
    struct sockaddr_storage their_addr; // connector's address information
    char buf[MAXBUFLEN]; // buffer for client data
    socklen_t addr_len; // address length
    char s[INET6_ADDRSTRLEN]; // address length

    // set up hints
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET6; // set to AF_INET to use IPv4
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE; // use my IP

    if ((addressInfo = getaddrinfo(NULL, port, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(addressInfo));
        return 1;
    }

    // loop through all the results and bind to the first we can
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                             p->ai_protocol)) == -1) {
            perror("listener: socket");
            continue;
        }

        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("listener: bind");
            continue;
        }

        break;
    }

    // socket not avaliable
    if (p == NULL) {
        fprintf(stderr, "listener: failed to bind socket\n");
        return 2;
    }

    freeaddrinfo(servinfo);

    printf("listener: waiting to recvfrom...\n");

    while (true) {
        addr_len = sizeof their_addr;
        if ((numbytes = recvfrom(sockfd, buf, MAXBUFLEN - 1, 0,
                                 (struct sockaddr *) &their_addr, &addr_len)) == -1) {
            perror("recvfrom");
            exit(1);
        }


        printf("listener: got packet from %s\n",
               inet_ntop(their_addr.ss_family,
                         get_in_addr((struct sockaddr *) &their_addr),
                         s, sizeof s));
        printf("listener: packet is %d bytes long\n", numbytes);
        buf[numbytes] = '\0';

        if (!handleMessage(buf)) {
            break;
        }
    }


    close(sockfd);
    return 1;
}
