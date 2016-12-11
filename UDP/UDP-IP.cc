// Nguyen Hai Duong
// Dec 10 2016
// UDP-IP.cc

#include "UDP-IP.h"

int CreateUDPClientSocket(struct sockaddr_in &serv_addr, const char *servIP, unsigned short port) {

	int clntSock;

	/*Create UDP socket*/
	clntSock = socket(PF_INET, SOCK_DGRAM, 0);

	// Construct local address structure
    memset(&serv_addr, 0, sizeof(serv_addr));        /* Zero out structure */
    serv_addr.sin_family = AF_INET;                 /* Internet address family */
    serv_addr.sin_addr.s_addr = inet_addr(servIP);  /* Any incoming interface */
    serv_addr.sin_port = htons(port);               /* Local port */

	return clntSock;
}

int CreateUDPServerSocket(unsigned short port) {

	int servSock;
	struct sockaddr_in serv_addr;

	/*Create UDP socket*/
	servSock = socket(PF_INET, SOCK_DGRAM, 0);

	// Construct local address structure
    memset(&serv_addr, 0, sizeof(serv_addr));        /* Zero out structure */
    serv_addr.sin_family = AF_INET;                 /* Internet address family */
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  /* Any incoming interface */
    serv_addr.sin_port = htons(port);               /* Local port */

	/*Bind socket with address struct*/
	bind(servSock, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
	
	return servSock;
}