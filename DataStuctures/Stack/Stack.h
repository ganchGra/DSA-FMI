#include<iostream>
#pragma once

template <class T>
class Stack
{
private:
	struct Node
	{
		T m_data;
		Node * m_pNext;

		Node(T data, Node * next = NULL)
		{
			m_data = data;
			m_pNext = next;
		}
	};

	Node * m_pTop;
	size_t m_size;

public:
	Stack();
	Stack(const Stack<T>& rhs);
	Stack<T>& operator=(const Stack<T>& rhs);
	~Stack();

private:
	void copyFrom(const Stack<T>& rhs);

public:
	/// Clear content
	void clear();

	/// Return size
	size_t size() const;

	/// Access next element
	T& top();
	const T& top() const;

	/// Insert element
	void push(const T&);

	/// Remove top element
	void pop();

	/// Test whether container is empty
	bool empty() const;
};

#include"Stack.hpp"