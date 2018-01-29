

template<class T>
Stack<T>::Stack()
	:m_pTop(NULL), m_size(0)
{}

template<class T>
Stack<T>::Stack(const Stack<T>& rhs)
	: m_pTop(NULL), m_size(0)
{
	copyFrom(rhs);
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs)
{
	if (this != &rhs)
	{
		clear();
		copyFrom(rhs);
	}
	return *this;
}

template<class T>
Stack<T>::~Stack()
{
	clear();
}

template<class T>
void Stack<T>::copyFrom(const Stack<T>& rhs)
{
	if (rhs.empty())
	{
		return;
	}
	try
	{
		m_pTop = new Node(rhs.m_pTop->m_data);

		Node * myStack = m_pTop;
		Node * rhsStack = rhs.m_pTop->m_pNext;
		while (rhsStack)
		{
			myStack->m_pNext = new Node(rhsStack->m_data);
			myStack = myStack->m_pNext;
			rhsStack = rhsStack->m_pNext;
		}
		m_size = rhs.m_size;
	}
	catch (const std::bad_alloc&)
	{
		clean();
		throw;
	}
}

template<class T>
void Stack<T>::clear()
{
	Node * toClean = m_pTop;
	while (m_pTop)
	{
		m_pTop = m_pTop->m_pNext;
		delete toClean;
		toClean = m_pTop;
	}
	m_pTop = NULL;
	m_size = 0;
}

template<class T>
inline size_t Stack<T>::size() const
{
	return m_size;
}

template<class T>
T& Stack<T>::top()
{
	if (empty())
	{
		throw std::exception("The stack is empty!");
	}
	return m_pTop->m_data;
}

template<class T>
const T& Stack<T>::top() const
{
	if (empty())
	{
		throw std::exception("The stack is empty!");
	}
	return m_pTop->m_data;
}

template<class T>
void Stack<T>::push(const T& data)
{
	Node * newEl = new Node(data, m_pTop);
	m_pTop = newEl;
	++m_size;
}
template<class T>
void Stack<T>::pop()
{
	if (!empty())
	{
		Node * toDel = m_pTop;
		m_pTop = m_pTop->m_pNext;
		delete toDel;
		--m_size;
	}
}

template<class T>
inline bool Stack<T>::empty() const
{
	return m_size == 0;
}