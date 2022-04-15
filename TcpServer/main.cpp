#include <iostream>
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

//reference - https://www.youtube.com/watch?v=WDn-htpBlnU

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

	// Bind the ip address and port to a socket
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(5400);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listeningSocket, (sockaddr*)&hint, sizeof(hint));

	//Tell winsock the socket is for listening
	listen(listeningSocket, SOMAXCONN);


	// Wait for a connection
	sockaddr_in client;
	int clientSize = sizeof(client);

	SOCKET clientSocket = accept(listeningSocket, (sockaddr*)&client, &clientSize);
	if (clientSocket == INVALID_SOCKET) {
		std::cerr << "Can't accept a socket connection, Quitting \n";
		return;
	}

	char host[NI_MAXHOST]; //client's remote name
	char service[NI_MAXHOST]; // service (i.e. port_ the client is connecting on)

	ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXHOST);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
	{
		std::cout << host << " connected on port " << service << '\n';	
	}
	else
	{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		std::cout << host << " connected on port " <<
			ntohs(client.sin_port) << '\n';
	}
	

	// Close listening socket
	closesocket(listeningSocket);

	// loop through accept and echo message back to client
	char buf[4096];

	while(true)
	{
		ZeroMemory(buf, 4096);

		//wait for client to send data
		int bytesReceived = recv(clientSocket, buf, 4096, 0);
		if(bytesReceived == SOCKET_ERROR)
		{
			std::cerr << "Error in recv(). Quitting \n";
			break;
		}
		if (bytesReceived == 0)
		{
			std::cout << "Client disconnected \n";
			break;
		}

		// Echo message back to client
		send(clientSocket, buf, bytesReceived + 1, 0);
		//echo message back to client
	}
	
	// Close the socket
	closesocket(clientSocket);

	// cleanup winsock
	WSACleanup();


}