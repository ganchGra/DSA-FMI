#include<iostream>
#include"Queue.h"

int main()
{
	Queue<int> test;
	for (size_t i = 1; i <= 5; i++)
	{
		test.push(i);
		std::cout << "Insert in to the queue: " << i << std::endl;
	}
	std::cout << "Queue size: " << test.size() << "\n\n";
	while (test.size())
	{
		std::cout << "Deque from the queue: " << test.front() << std::endl;
		test.pop();
	}
	std::cout << "Queue size: " << test.size() << "\n\n";

	system("pause");
	return 0;
}