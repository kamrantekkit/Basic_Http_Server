//
// Created by mdkam on 30/12/2024.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <signal.h>

#include "TCPServer.h"

#include <iostream>


int TCPServer::startServer(const char *port, const std::string &responseMessage) {
  const int socketServer = socket(AF_INET, SOCK_STREAM, 0);

  if (socketServer == -1) {
    perror("socket");
    return 1;
  }

  sockaddr_in serverAddress{};

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(atoi(port));
  serverAddress.sin_addr.s_addr = INADDR_ANY;

  if (bind(socketServer, (sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
    perror("bind");
    return 2;
  }

  if (listen(socketServer, 10) == -1) {
    perror("listen");
    return 3;
  }

  printf("server: waiting for connections...\n");

  int clientSocket = accept(socketServer, NULL, NULL);

  // Read from client
  char buffer[1024];
  const int numBytes = recv(clientSocket, buffer, sizeof(buffer), 0);

  buffer[numBytes] = '\0';

  // Print message
  printf("server: got message: %s\n", buffer);

  //sending following response
  std::cout << "server: sending response: " << responseMessage << std::endl;

  // use class variable for response
  send(clientSocket, responseMessage.c_str(), responseMessage.size(), 0);

  close(clientSocket);
  close(socketServer);

  return 0;
}
