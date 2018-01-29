#include"Stack.h"
#include<iostream>

void Test_Stack()
{
	Stack<int> stack;
	for (size_t i = 1; i <= 10; i++)
	{
		stack.push(i);
		std::cout << "Added: " << i << std::endl;
	}
	std::cout << "Stack size: " << stack.size() << "\n\n";

	for (size_t i = 1; i <= 10; i++)
	{
		std::cout << "See and pop top element: " << stack.top() << std::endl;
		stack.pop();
	}
	std::cout << "Stack size: " << stack.size() << "\n\n";

	for (size_t i = 1; i <= 5; i++)
	{
		stack.push(i);
		std::cout << "Added: " << i << std::endl;
	}
	std::cout << "Stack size: " << stack.size() << "\n\n";

	std::cout << "Before changed the top element: " << stack.top() << "\n\n";
	stack.top() = 2017;
	std::cout << "After changed the top element: " << stack.top() << "\n\n";
	while (stack.size())
	{
		std::cout << stack.top() << std::endl;
		stack.pop();
	}
}
int main() 
{

	Test_Stack();

	system("pause");

	return 0;
}