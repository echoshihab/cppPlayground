// Do Listt
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "sqlite3.h"

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

	// print out item and write to external file
	// also write to db.
	cout << "Todo list for today:" << endl;
	
	
	ofstream todoFile;
	sqlite3 *sdb;
	sqlite3_stmt *stmtTbl;
	sqlite3_stmt *stmtInsert;

	string createTableStatement = "CREATE TABLE IF NOT EXISTS todos (id INTEGER PRIMARY KEY, todo TEXT);";
	

	//initialize 
	if(SQLITE_OK != (sqlite3_initialize()))
	{
	  cout	<< "Failed to initialize sqlite3 \n";	
	}

	//open connection to db
	if (SQLITE_OK !=( sqlite3_open("cppTest.db", &sdb))) 
	{
 	  cout << "Failed to open connection \n";
	}

	//create table if not exists
	if(SQLITE_OK != (sqlite3_prepare(sdb, createTableStatement.c_str(), createTableStatement.size(), &stmtTbl, NULL)))
	{
		cout << "Failed to prepare create table statement " << sqlite3_errmsg(sdb);
	}

	
	if(SQLITE_DONE != (sqlite3_step(stmtTbl)))
	{
		cout << "Failed to create table" << sqlite3_errmsg(sdb);
	}


	todoFile.open("todo.txt");	

	for (string item : todoList) {
		cout << item << endl;

		if(todoFile.is_open())
		{
			todoFile << item ;
			todoFile << "\n";	
		}	
		
		string insertStatement = "INSERT INTO todos (todo) VALUES ('"+item+"');";
		//INSERT TO DB AS WELL
		if(SQLITE_OK != (sqlite3_prepare(sdb, insertStatement.c_str(), insertStatement.size(), &stmtInsert, NULL)))
		{
			cout << "Failed to prepare insert " << sqlite3_errmsg(sdb);  
		}

		if(SQLITE_DONE != (sqlite3_step(stmtInsert)))
		{
			cout << "Failed to insert " << sqlite3_errmsg(sdb) << '\n'; 
		}


	}

	//cleanup
	todoFile.close();
	if(stmtTbl != NULL) {
		sqlite3_finalize(stmtTbl);
	}
	if(stmtInsert != NULL){
		sqlite3_finalize(stmtInsert);
	}
	if(sdb != NULL) {
		sqlite3_close(sdb);
	}
	sqlite3_shutdown();

	return 0;

}
