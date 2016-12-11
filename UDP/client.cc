/************* UDP CLIENT CODE *******************/
// Compile : gcc client.cc UDP-IP.cc -o client

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>  // for sockaddr_in and inet_ntoa()
#include <string.h>
#include "UDP-IP.h"

int main(int argc, char *argv[]) {
  int nBytes;
  char buffer[BUFFSIZE];
  struct sockaddr_in serv_addr;
  char *servIP;
  if (argc < 2)
  {
      servIP = (char *)"127.0.0.1";   // localhost
  }else{
      servIP = argv[1];
  }

  int clntSock = CreateUDPClientSocket(serv_addr, servIP, PORT);
  printf("servIP:%s\n",servIP);
  while(1){

    printf("Type a sentence to send to server:\n");
    fgets(buffer,BUFFSIZE,stdin);
    printf("You typed: %s",buffer);

    nBytes = strlen(buffer) + 1;
    
    /*Send message to server*/
    sendto(clntSock,buffer,nBytes,0,(struct sockaddr *)&serv_addr, sizeof(serv_addr));

    /*Receive message from server*/
    nBytes = recvfrom(clntSock, buffer, BUFFSIZE, 0,NULL, NULL);

    printf("Received from server: %s\n",buffer);
    bzero(buffer,strlen(buffer));

  }

  return 0;
}