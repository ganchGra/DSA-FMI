#pragma once

template<class T>
class Queue
{
private:
	struct Node
	{
		T m_data;
		Node * m_pNext;

		Node(const T& data, Node * pNext = NULL)
			:m_data(data), m_pNext(pNext) {}
	};

	Node * m_pFront;
	Node * m_pBack;
	size_t m_size;

public:
	Queue();
	Queue(const Queue<T>& rhs);
	Queue<T>& operator=(const Queue<T>& rhs);
	~Queue();
private:
	void copyFrom(const Queue<T>& rhs);

public:
	/// Access next element
	T & front();
	const T& front() const;

	/// Access last element
	T& back();
	const T& back() const;

	/// Insert element
	void push(const T& data);

	/// Remove next element
	void pop();

	/// Test whether container is empty
	bool empty() const;

	/// Return size
	size_t size() const;

	/// Clear content
	void clear();
};

#include"Queue.hpp"