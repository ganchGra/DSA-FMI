#include<iostream>
#include"DynamicArray.h"
void Test_Create_Empty_Array()
{
	std::cout << "Create empty dynamic array...";

	DynamicArray<int> test;
	std::cout << "OK!\n";
}
void Test_Create_With_Capacity()
{
	std::cout << "Create dynamic array with capacity 10000...";

	DynamicArray<int> test(10000);
	std::cout << "OK!\n";
}
void Test_Copy_Two_Arrays()
{
	std::cout << "Copy two dynamic arrays...";

	DynamicArray<int> test1(5);
	DynamicArray<int> test2 = test1;
	std::cout << "OK!\n";
}
void Test_Asign_Array_From_Other()
{
	std::cout << "Asign array from other array...";
	DynamicArray<int> test1(5);
	DynamicArray<int> test2(10);

	test1 = test2;
	std::cout << "OK!\n";
}
void Test_Clear_Array()
{
	std::cout << "Clear array...";
	DynamicArray<int> test(5);
	test.clear();
	std::cout << "OK!\n";
}
void Test_Get_Size_Empty_Array()
{
	std::cout << "Get size of empty array...";
	DynamicArray<int> test;
	std::cout << "Size: " << test.size() << std::endl;
}
void Test_Get_Capacity_New_Array()
{
	std::cout << "Get capacity of new array...";
	DynamicArray<int> test;
	std::cout << "Capacity: " << test.capacity() << std::endl;
}
void Test_Resize_Array_With_No_Capacity()
{
	std::cout << "Resize array with no capacity...";
	DynamicArray<int> test;
	std::cout << "[ Capacity before resize: " << test.capacity();
	test.resize(5);
	std::cout << " | Capacity after resize: " << test.capacity() <<" ]\n";

}
void Test_Is_Empty()
{
	std::cout << "Is empty array without value...";
	DynamicArray<int> test;
	std::cout << ((test.empty())?"True\n":"False\n");
	

}
void Test_Element_Access()
{
	std::cout << "Element access...\n";
	DynamicArray<int> test(5);
	for (size_t i = 0; i < 5; i++)
		test.push_back(i);
	std::cout << "Array content: ";
	
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test[i] <<" ";
	std::cout << std::endl;
	std::cout << "First element: " << test.front() << std::endl;
	std::cout << "Last element: "<<test.front() << std::endl;
	try
	{
		std::cout << "Get element out of range...";
		std::cout<< test[6] << std::endl;
		
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
void Test_Push_Back_Element()
{
	std::cout << "Push back element 5 elements...\n";
	DynamicArray<int> test(5);
	for (size_t i = 0; i < 5; i++)
	{
		test.push_back(i);
		std::cout << "[Added: " << i <<" | New size: "<< test.size()<<"]\n";
	}
}

void Test_Pop_Back_Element()
{
	std::cout << "Pop back element 5 elements...\n";
	DynamicArray<int> test(5);
	for (size_t i = 0; i < 10; i++)
		test.push_back(i);
	
	for (size_t i = 0; i <= 5; i++)
	{
		std::cout << "Array content: ";

		for (size_t i = 0; i < test.size(); i++)
			std::cout << test[i] << " ";
		std::cout << "\nSize: " << test.size() << std::endl;
		test.pop_back();
	}
}
void Test_DynamicArray()
{
	Test_Create_Empty_Array();
	Test_Create_With_Capacity();
	Test_Copy_Two_Arrays();
	Test_Asign_Array_From_Other();
	Test_Clear_Array();
	Test_Get_Size_Empty_Array();
	Test_Get_Capacity_New_Array();
	Test_Resize_Array_With_No_Capacity();
	Test_Is_Empty();
	Test_Element_Access();
	Test_Push_Back_Element();
	Test_Pop_Back_Element();
}
int main()
{
	Test_DynamicArray();

	system("pause");
	return 0;
}