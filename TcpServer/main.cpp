#include <iostream>
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

void main()
{
	// Initialize winsock
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOK = WSAStartup(ver, &wsData);

	if (wsOK != 0)
	{
		std::cerr << "Can't Initialize winsock. Quitting \n";
		return;
	}

	// Create a socket
	SOCKET listeningSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (listeningSocket == INVALID_SOCKET)
	{
		std::cerr << "Can't create a socket! Quitting \n";
		return;
	}
	
	// Bind the socket to an ip address and port
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(5400);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;
	
	bind(listeningSocket, (sockaddr*)&hint, sizeof(hint));

	//Tell winsock the socket is for listening
	
	// Wait for a connection

	// Close listening socket

	// loop through accept and echo message back to client
	
	// Close the socket
	
	// Shutdown winsock



}