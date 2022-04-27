#include <iostream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

void main()
{
	//ip address of server
	std::string ipAddress = "127.0.0.1";
	int port = 5400;

	//Initialize Winsock
	WSAData data;
	WORD version = MAKEWORD(2, 2);

	INT wsResult = WSAStartup(version, &data);

	if (wsResult != 0)
	{
	std::cerr << "Can't start Winsock, Error#" << wsResult << '\n';
		return;
	}

	//Create Socket
	SOCKET sock = socket(AF_INET,SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		std::cerr << "Can't create socket, Error#" << WSAGetLastError() << '\n';
	}

	//fill in hint structure
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr)

	 
	// connect to server
	// loop to send receive data
	// gracefully shutdown
}