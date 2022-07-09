#include <iostream>
#include <vector>
#pragma once

class VectorStack {
private:
	int sizeOfArray;
	int totalElements;
	std::vector<int> dynamicArr;

public:
	void push(int val);

	void pop();

	void peek();

	void printStack();
};
