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
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);


	// connect to server
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		std::cerr << "Can't connect to server, Err#" << WSAGetLastError() << '\n';
		closesocket(sock);
		WSACleanup();
		return;
	}


	// loop to send receive data.
	char buffer[4096];
	std::string userInput;

	do {
		// Prompt the user for some text
		std::cout << "> ";
		std::getline(std::cin, userInput);
		
		if (userInput.size() > 0) //to ensure something was typed
		{
			// Send the text
			int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
			if (sendResult != SOCKET_ERROR)
			{
				//wait for response
				ZeroMemory(buffer, 4096);
				int bytesReceived = recv(sock, buffer, 4096, 0);

				if (bytesReceived > 0)
				{
					// Echo response to console
					std::cout << "SERVER " << std::string(buffer, 0, bytesReceived) << '\n';
				}
			}
			//wait for response
			//echo response to console
		}

	} while (userInput.size() > 0);
		
	
	// gracefully shutdown
	closesocket(sock);
	WSACleanup();
}