/************* UDP SERVER CODE *******************/
// Compile : gcc server.cc UDP-IP.cc -o server

#include <stdio.h>
#include <ctype.h>  // toupper
#include "UDP-IP.h"

int main() {
  int servSock, nBytes;
  char buffer[BUFFSIZE];

  struct sockaddr_storage serverStorage;
  socklen_t addr_size;

  servSock = CreateUDPServerSocket(PORT);
  /*Initialize size variable to be used later on*/
  addr_size = sizeof serverStorage;

  while(1){
    /* Try to receive any incoming UDP datagram. Address and port of 
      requesting client will be stored on serverStorage variable */
    nBytes = recvfrom(servSock, buffer, BUFFSIZE, 0,(struct sockaddr *)&serverStorage, &addr_size);

    /*Convert message received to uppercase*/
    for(int i=0;i<nBytes-1;i++)
      buffer[i] = toupper(buffer[i]);

    /*Send uppercase message back to client, using serverStorage as the address*/
    sendto(servSock, buffer, nBytes, 0, (struct sockaddr *)&serverStorage,addr_size);
  }

  return 0;
}