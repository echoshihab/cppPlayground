// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	std::cout << "Hello World!\n";
}

class DynamicArrayStack {
private:
	int sizeOfArray{ 4 };
	int totalElements{ 0 };
	int* dynamicArr = new int[4]{};

public:
	void increaseArrayCapacity() {
		sizeOfArray *= 2;
		int* tempArray = new int[sizeOfArray] {};
		//copy all elements of current array to new temp array
		std::copy(dynamicArr[0], dynamicArr[sizeOfArray], tempArray);
		// delete existing array
		delete[] dynamicArr;
		// set existing array to the temp array
		dynamicArr = tempArray;
		//delete the temp array
		delete[] tempArray;
	}
	void push(int val) {
		if (totalElements < sizeOfArray) 
		{
			dynamicArr[totalElements + 1] = val;
		}
		else 
		{
			std::cout << "Can't push any more elements to stack";
		}

	}
	int pop() {
		if (totalElements > 0) {
			return dynamicArr[totalElements];
		}
	}
	void printStack() {
		for (int i = 0; i++; i < sizeOfArray) {
			cout << dynamicArr[i];
		}
	}
	


	//create an array
	// 
	//implement push
	// implement pop
	//implment isEmpty
	// implment Peek

	//double the array size

	//check when to double the array size

};


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
