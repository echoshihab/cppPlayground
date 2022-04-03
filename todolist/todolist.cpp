// Do Listt
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	cout << "To Do List in C++" << endl;
	
	string input = "N";
	vector<string> todoList = {};
	
	//loop to ask for todo items
	while (input != "Q" && input != "q" )	
	{
		cout << "Input a todo item, enter q to quit" << endl;
		cin >> input;
	
		if(input != "Q" && input != "q")
		{
			todoList.push_back(input);
		}
	}

	// print out item and write to external file.
	cout << "Todo list for today:" << endl;
	
	
	ofstream todoFile;

	todoFile.open("todo.txt");	

	for (string item : todoList) {
		cout << item << endl;

		if(todoFile.is_open())
		{
			todoFile << item ;
			todoFile << "\n";	
		}	
	}
	todoFile.close();

	return 0;

}
