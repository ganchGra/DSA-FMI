#pragma once
#include<iostream>

template<class T>
class Forward_List
{
private:
	struct Node
	{
		T data;
		Node * pNext;

		Node(const T& data, Node * next = NULL)
			:data(data), pNext(next) {}
	};

	Node * m_pHead;
	Node * m_pTail;
	size_t m_size;

public:
	class Iterator
	{
	private:
		Node * pNode;

	public:
		Iterator(Node * node)
			:pNode(node)
		{}
		Iterator(const Iterator& other)
			:pNode(other.pNode)
		{}

	public:
		const T& operator*() const
		{
			return pNode->data;
		}
		T& operator*()
		{
			return pNode->data;
		}

		const T* operator->() const
		{
			return pNode->*data;;
		}
		T* operator->()
		{
			return pNode->*data;
		}

		Iterator&  operator++()
		{
			pNode = pNode->pNext;
			
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator res(*this);
			++(*this);
			return res;
		}

		bool operator==(const Iterator& other) const
		{
			return pNode == other.pNode;
		}

		bool operator!=(const Iterator& other) const
		{
			return !(*this == other);
		}
	};
public:
	Forward_List();
	Forward_List(const Forward_List<T>& rhs);
	Forward_List<T>& operator=(const Forward_List<T>& rhs);
	~Forward_List();

private:
	void copyFrom(const Forward_List<T>& rhs);

public:
	/// Clear content
	void clear();

	/// Insert element at the end
	void push_back(const T& data);

	/// Insert element at beginning
	void push_front(const T& data);

	/// Delete last element
	void pop_back();

	/// Delete first element
	void pop_front();

	/// Access Last element
	T& back();
	const T& back() const;

	/// Access first element
	T& front();
	const T& front() const;

	/// Reverse the order of elements
	void reverse();

	/// Test whether container is empty
	bool empty() const;

	/// Return size
	size_t size() const;

	Iterator begin()
	{
		return Iterator(m_pHead);
	}
	Iterator end()
	{
		return Iterator(m_pTail->pNext);
	}

	/// Sort with merge sort
	void sort();

private:
	Node * merge(Node * left, Node * right);
	Node * mergeSort(Node * source, size_t size);
};

#include"ForwardList.hpp"