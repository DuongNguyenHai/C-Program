// Nguyen Hai Duong
// Dec 10 2016
// UDP.h

#include <stdio.h>
#include <sys/socket.h> // for socket(), bind(), and connect()
#include <netinet/in.h> // for IP Socket data types
#include <string.h>		// for memset()
#include <arpa/inet.h>  // for sockaddr_in and inet_ntoa()


#define BUFFSIZE 256
#define PORT 8888

// Initial UDP client socket
int CreateUDPClientSocket(struct sockaddr_in &serv_addr, const char *servIP, unsigned short port);

// Initial UDP server socket
int CreateUDPServerSocket(unsigned short port);