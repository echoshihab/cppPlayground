#include <iostream>
#include <vector>
#include <string>
#include "VectorStack.h";


	void VectorStack::push(int val) {
		std::cout << "Pushing " << std::to_string(val) << " into stack" << '\n';
		if (totalElements <= sizeOfArray + 1)
		{
			dynamicArr.push_back(val);
			totalElements += 1;
		}
		peek();
	}


	void VectorStack::pop() {

		if (totalElements > 0)
		{
			int indexOfItemToBeRemoved = totalElements - 1;
			totalElements -= 1;
			std::cout << "Item being Popped: " << dynamicArr[indexOfItemToBeRemoved] << '\n';
			peek();
			dynamicArr.pop_back();

		}
		else
		{
			std::cout << "Can't pop any more elements from stack" << '\n';
		}

	}

	void VectorStack::peek() {
		int indexOfTopItem = totalElements - 1;
		std::cout << "top item is " << std::to_string(dynamicArr[indexOfTopItem]) << '\n';
	}

	void VectorStack::printStack() {
		std::cout << "Current Stack: " << '\n';
		for (int i = 0; i < totalElements; i++) {
			std::cout << dynamicArr[i] << '\n';
		}
	}
