#include <iostream>
#include <string>

#pragma once

class DynamicArrayStack
{

private:
	int sizeOfArray{ 4 };
	int totalElements{ 0 };
	int* dynamicArr = new int[4];

public:
	void increaseArrayCapacity();

	void push(int val);

	int pop();

	void peek();

	void printStack();
};