// Do Listt
#include <iostream>
#include <vector>
#include <string>
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

	// print out item
	cout << "Todo list for today:" << endl;

	for (string item : todoList) {
		cout << item << endl;
	}
	return 0;
}
