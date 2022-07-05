
#include <iostream>
#include <string>

class DynamicArrayStack
{

private:
	int sizeOfArray{ 4 };
	int totalElements{ 0 };
	int* dynamicArr = new int[4];

public:
	void increaseArrayCapacity() {
		//double the size of array when no more space left
		int* tempArray = new int[sizeOfArray*2];
		//copy all elements of current array to new temp array
		std::copy(dynamicArr, dynamicArr+sizeOfArray, tempArray);

		delete[] dynamicArr;
		// set existing array to the temp array
		dynamicArr = tempArray;
		
		delete[] tempArray;

	}
	void push(int val) {
		std::cout << "Pushing " << std::to_string(val) << " into stack" << '\n';
		if (totalElements <= sizeOfArray + 1)
		{
			dynamicArr[totalElements] = val;
			totalElements += 1;
		}
		else
		{
			increaseArrayCapacity();
			dynamicArr[totalElements] = val;
			totalElements += 1;
		}
		peek();
	}


	int pop() {
		//this doesn't remove the element from array completely, but it creates the illusion by decreasing number of 
		//total elements
		if (totalElements > 0)
		{
			int indexOfItemToBeRemoved = totalElements-1;
			totalElements -= 1;
			std::cout << "Item being Popped: " << dynamicArr[indexOfItemToBeRemoved] << '\n';
			peek();
			return dynamicArr[indexOfItemToBeRemoved];


		}
		else
		{
			std::cout << "Can't pop any more elements from stack" << '\n';
		}

	}

	void peek() {
		int indexOfTopItem = totalElements - 1;
		std::cout << "top item is " << std::to_string(dynamicArr[indexOfTopItem])  << '\n';
	}

	void printStack() {
		std::cout << "Current Stack: " << '\n';
		for (int i = 0; i <= totalElements; i++) {
			std::cout << dynamicArr[i] << '\n';
		}
	}

};


int main()
{

	DynamicArrayStack d;

	d.push(5);
	d.push(4);
	d.push(3);
	d.push(2);
	d.push(1);
	d.push(0);
	d.pop();
	d.printStack();

	return 0;
}
 
