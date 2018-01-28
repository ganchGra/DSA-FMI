
template<class T>
Forward_List<T>::Forward_List()
	:m_pHead(NULL), m_pTail(NULL), m_size(0)
{}

template<class T>
Forward_List<T>::Forward_List(const Forward_List<T>& rhs)
	: m_pHead(NULL), m_pTail(NULL), m_size(0)
{
	copyFrom(rhs);
}

template<class T>
Forward_List<T>& Forward_List<T>::operator=(const Forward_List<T>& rhs)
{
	if (this != &rhs)
	{
		copyFrom(rhs);
	}
	return *this;
}

template<class T>
Forward_List<T>::~Forward_List()
{
	clear();
}

template<class T>
void Forward_List<T>::copyFrom(const Forward_List<T>& rhs)
{
	if (rhs.empty())
	{
		return;
	}

	try
	{
		m_pHead = new Node(rhs.m_pHead->data);
		Node * ours = m_pHead;
		Node * theirs = rhs.m_pHead->pNext;
		while (theirs)
		{
			ours->pNext = new Node(theirs->data);
			ours = ours->pNext;
			theirs = theirs->pNext;
		}
		m_pTail = ours;
		m_size = rhs.m_size;
	}
	catch (const std::bad_alloc&)
	{
		clear();
		throw;
	}
}

template<class T>
void Forward_List<T>::clear()
{
	while (m_pHead)
	{
		Node * toClean = m_pHead;
		m_pHead = m_pHead->pNext;
		delete toClean;
		toClean = m_pHead;
	}
	m_pHead = m_pTail = NULL;
	m_size = 0;
}

template<class T>
void Forward_List<T>::push_back(const T& data)
{
	if (empty())
	{
		m_pHead = new Node(data);
		m_pTail = m_pHead;
	}
	else
	{
		m_pTail->pNext = new Node(data);
		m_pTail = m_pTail->pNext;
	}
	++m_size;
}

template<class T>
void Forward_List<T>::push_front(const T& data)
{
	if (empty())
	{
		m_pHead = new Node(data);
		m_pTail = m_pHead;
	}
	else
	{
		Node * temp = new Node(data, m_pHead);
		m_pHead = temp;
	}
	++m_size;
}

template<class T>
void Forward_List<T>::pop_back()
{
	if (empty())
	{
		std::cout << "The list is empty.\n";
		return;
	}

	Node * temp = m_pHead;
	while (temp->pNext != m_pTail)
	{
		temp = temp->pNext;
	}
	temp->pNext = NULL;
	delete m_pTail;
	m_pTail = temp;
	--m_size;
}

template<class T>
void Forward_List<T>::pop_front()
{
	if (empty())
	{
		std::cout << "The list is empty.\n";
		return;
	}

	Node * toClean = m_pHead;
	m_pHead = m_pHead->pNext;
	delete toClean;
	--m_size;
}

template<class T>
T& Forward_List<T>::back()
{
	if (empty())
	{
		throw std::logic_error("The list is empty!");
	}
	return m_pTail->data;
}

template<class T>
const T& Forward_List<T>::back() const
{
	if (empty())
	{
		throw std::logic_error("The list is empty!");
	}
	return m_pTail->data;
}


template<class T>
T& Forward_List<T>::front()
{
	if (empty())
	{
		throw std::logic_error("The list is empty!");
	}
	return m_pHead->data;
}

template<class T>
const T& Forward_List<T>::front() const
{
	if (empty())
	{
		throw std::logic_error("The list is empty!");
	}
	return m_pHead->data;
}

template<class T>
void Forward_List<T>::reverse()
{
	if (!m_pHead || !m_pHead->pNext)
		return;

	Node * first = m_pHead;
	Node * second = m_pHead->pNext;
	while (second)
	{
		Node * third = second->pNext;
		second->pNext = first;
		first = second;
		second = third;
	}
	m_pHead->pNext = NULL;
	m_pHead = first;
}

template<class T>
bool Forward_List<T>::empty() const
{
	return m_size == 0;
}

template<class T>
size_t Forward_List<T>::size() const
{
	return m_size;
}

/// Sort ForwarList with merge sort
template<class T>
void Forward_List<T>::sort()
{
	m_pHead = mergeSort(m_pHead,m_size);
	Node * start = m_pHead;
	while (start->pNext != NULL)
	{
		start = start->pNext;
	}
	m_pTail = start;
}

template<class T>
typename Forward_List<T>::Node * Forward_List<T>::mergeSort(Node * source, size_t size)
{
	if (size == 1)
		return source;

	Node * left = source;
	Node * right = source;

	size_t sizeLeft = 0;
	size_t sizeRight = size;
	for (size_t i = 0; i < size/2; i++)
	{
		if (i+1 == size/2)
		{
			Node * temp = right;
			right = right->pNext;
			--sizeRight;
			++sizeLeft;
			temp->pNext = NULL;
			continue;
		}

		right = right->pNext;
		--sizeRight;
		++sizeLeft;
		
	}

	left = mergeSort(left, sizeLeft);
	right = mergeSort(right, sizeRight);
	Node * result = merge(left, right);

	return result;
}
template<class T>
typename Forward_List<T>::Node * Forward_List<T>::merge(Node * left, Node * right)
{
	if (left == NULL) return right;
	if (right == NULL) return left;

	Node * head = NULL;
	if (left->data < right->data)
	{
		head = left;
		left = left->pNext;
	}
	else
	{
		head = right;
		right = right->pNext;
	}
	Node * nextNode = head;

	while (left && right)
	{
		
		if (left->data < right->data)
		{
			nextNode->pNext = left;
			left = left->pNext;
			nextNode = nextNode->pNext;
		}
		else
		{
			nextNode->pNext = right;
			right = right->pNext;
			nextNode = nextNode->pNext;
		}
		
	}
	

	while (left)
	{
		nextNode->pNext = left;
		left = left->pNext;
		nextNode = nextNode->pNext;
	}
	while (right)
	{
		nextNode->pNext = right;
		right = right->pNext;
		nextNode = nextNode->pNext;
	}

	return head;
}