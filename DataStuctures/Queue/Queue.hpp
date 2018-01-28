
template<class T>
Queue<T>::Queue()
	:m_pBack(NULL), m_pFront(NULL), m_size(0)
{}

template<class T>
Queue<T>::Queue(const Queue<T>& rhs)
	: m_pBack(NULL), m_pFront(NULL), m_size(0)
{
	copyFrom(rhs);
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
{
	if (this != &rhs)
	{
		clear();
		copyFrom(rhs);
	}
	return *this;
}

template<class T>
Queue<T>::~Queue()
{
	clear();
}

template<class T>
void Queue<T>::copyFrom(const Queue<T>& rhs)
{
	if (rhs.empty())
	{
		return;
	}

	try
	{
		m_pFront = new Node(rhs.m_pFront);
		Node * myQueue = m_pFront;
		Node * rhsQueue = m_pFront->m_pNext;

		while (rhsQueue)
		{
			myQueue->m_pNext = new Node(rhsQueue->m_data);
			myQueue = myQueue->m_pNext;

			rhsQueue = rhsQueue->m_pNext;
		}
		m_pBack = myQueue;
		m_size = rhs.m_size;
	}
	catch (const std::bad_alloc&)
	{
		clear();
		throw;
	}
}

template<class T>
T& Queue<T>::front()
{
	if (empty())
	{
		throw std::logic_error("Queue is empty!");
	}
	return m_pFront->m_data;
}

template<class T>
const T& Queue<T>::front() const
{
	if (empty())
	{
		throw std::logic_error("Queue is empty!");
	}
	return m_pFront->m_data;
}

template<class T>
T& Queue<T>::back()
{
	if (empty())
	{
		throw std::logic_error("Queue is empty!");
	}
	return m_pBack->m_data;
}

template<class T>
const T& Queue<T>::back() const
{
	if (empty())
	{
		throw std::logic_error("Queue is empty!");
	}
	return m_pBack->m_data;
}

template<class T>
void Queue<T>::push(const T& data)
{
	if (empty())
	{
		m_pFront = new Node(data);
		m_pBack = m_pFront;
	}
	else
	{
		Node * temp = new Node(data);
		m_pBack->m_pNext = temp;
		m_pBack = temp;
	}
	++m_size;
}

template<class T>
void Queue<T>::pop()
{
	if (!empty())
	{
		Node * temp = m_pFront;
		m_pFront = m_pFront->m_pNext;
		delete temp;
		--m_size;
	}
}

template<class T>
bool Queue<T>::empty() const
{
	return m_size == 0;
}
template<class T>
inline size_t Queue<T>::size() const
{
	return m_size;
}

template<class T>
void Queue<T>::clear()
{
	Node * temp;
	while (m_pFront)
	{
		temp = m_pFront;
		m_pFront = m_pFront->m_pNext;
		delete temp;
	}
	m_pFront = m_pBack = NULL;
	m_size = 0;
}
