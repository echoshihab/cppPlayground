
#include <iostream>

class DynamicArrayStack
{

private:
	int sizeOfArray{ 4 };
	int totalElements{ 0 };
	int* dynamicArr = new int[4]{};

public:
	void increaseArrayCapacity() {
		int* tempArray = new int[sizeOfArray*2] {};
		//copy all elements of current array to new temp array
		std::copy(dynamicArr, dynamicArr+sizeOfArray, tempArray);
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
			totalElements += 1;
		}
		else
		{
			std::cout << "Can't push any more elements to stack" << '\n';
		}
	}

	int pop() {
		if (totalElements > 0)
		{
			int currentNumOfElements = totalElements;
			totalElements -= 1;
			return dynamicArr[currentNumOfElements];

		}
		else
		{
			std::cout << "Can't pop any more elements from stack";
		}
	}

	void printStack() {
		std::cout << "Current Stack: ";
		for (int i = 0; i < totalElements; i++) {
			std::cout << dynamicArr[i] << '\n';
		}
	}

};


int main()
{
	std::cout << "Hello";

	DynamicArrayStack d;

	d.push(5);
	d.push(4);
	d.push(1);

	std::cout << "Item Popped: " << d.pop() << '\n';
	std::cout << "Item Popped: " << d.pop() << '\n';
	std::cout << "Item Popped: " << d.pop() << '\n';
	d.printStack();
	return 0;
}
 
