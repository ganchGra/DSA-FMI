#include<iostream>
#include"ForwardList.h"

void Test_Create_Empty_List()
{
	std::cout << "Create empty forward list array...";

	Forward_List<int> test;
	std::cout << "OK!\n";
}
void Test_Copy_Two_List()
{
	std::cout << "Copy two list...";

	Forward_List<int> test1;
	Forward_List<int> test2 = test1;
	std::cout << "OK!\n";
}
void Test_Asign_Array_From_Other()
{
	std::cout << "Asign list from other list...";
	Forward_List<int> test1;
	Forward_List<int> test2;

	test1 = test2;
	std::cout << "OK!\n";
}
void Test_Clear_List()
{
	std::cout << "Clear array...";
	Forward_List<int> test;
	test.clear();
	std::cout << "OK!\n";
}
void Test_Get_Size_Empty_List()
{
	std::cout << "Get size of empty list...";
	Forward_List<int> test;
	std::cout << "Size: " << test.size() << std::endl;
}
void Test_Is_Empty()
{
	std::cout << "Is empty list without value...";
	Forward_List<int> test;
	std::cout << ((test.empty()) ? "True\n" : "False\n");


}
void Test_Element_Access()
{
	std::cout << "Element access...\n";
	Forward_List<int> test;
	for (size_t i = 0; i < 5; i++)
		test.push_back(i);
	std::cout << "List content: ";

	Forward_List<int>::Iterator it = test.begin();
	Forward_List<int>::Iterator itEnd = test.end();
	while (it != itEnd)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::cout << "First element: " << test.front() << std::endl;
	std::cout << "Last element: " << test.back() << std::endl;
	test.clear();
	try
	{
		std::cout << "Get first element from empty list...";
		std::cout << test.front() << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
void Test_Push_Back_Element()
{
	std::cout << "Push back element 5 elements...\n";
	Forward_List<int> test;
	for (size_t i = 0; i < 5; i++)
	{
		test.push_back(i);
		std::cout << "[Added: " << i << " | New size: " << test.size() << "]\n";
	}
}
void Test_Pop_Back_Element()
{
	std::cout << "Pop back element 5 elements...\n";
	Forward_List<int> test;
	for (size_t i = 0; i < 10; i++)
		test.push_back(i);

	for (size_t i = 0; i <= 5; i++)
	{
		std::cout << "List content: ";

		Forward_List<int>::Iterator it = test.begin();
		Forward_List<int>::Iterator itEnd = test.end();
		while (it != itEnd)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << "\nSize: " << test.size() << std::endl;
		test.pop_back();
	}
}
void Test_ForwardList()
{
	Test_Create_Empty_List();
	Test_Copy_Two_List();
	Test_Asign_Array_From_Other();
	Test_Clear_List();
	Test_Get_Size_Empty_List();
	Test_Is_Empty();
	Test_Element_Access();
	Test_Push_Back_Element();
	Test_Pop_Back_Element();
}

int main()
{
	Test_ForwardList();

	system("pause");
	return 0;
}