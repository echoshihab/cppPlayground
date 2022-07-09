
#include <iostream>
#include <string>
#include "VectorStack.h";
#include "DynamicArrayStack.h";

int main()
{
	DynamicArrayStack d;
	VectorStack v;

	std::cout << "Dynamic array stack result:" << '\n';
	d.push(5);
	d.push(4);
	d.push(3);
	d.push(2);
	d.push(1);
	d.push(0);
	d.pop();
	d.printStack();

	std::cout << "Vector array stack result: " << '\n';

	v.push(5);
	v.push(4);
	v.push(3);
	v.push(2);
	v.push(1);
	v.push(0);
	v.pop();
	v.printStack();

	return 0;
}
 
