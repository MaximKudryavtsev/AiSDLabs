#include "stdafx.h"
#include "Queue.h"

using namespace std;

CStringStack::CStringStack()
{
}

CStringStack::~CStringStack() noexcept
{
	Node *curr = m_top;

	while (curr != nullptr)
	{
		Node *next = curr->next;
		delete curr;
		curr = next;
	}
	m_top = nullptr;
}

void CStringStack::Push(const string &str)
{
	Node *node = new Node;
	node->str = str;

	if (m_top != nullptr)
	{
		node->next = m_top;
	}
	else
	{
		node->next = nullptr;
	}
	m_top = node;
	++m_size;
}

void CStringStack::Pop()
{
	if (IsEmpty())
	{
		throw domain_error("Can't pop last element from empty queue");
	}

	Node *node = m_top;
	m_top = m_top->next;
	delete node;
	--m_size;
}

size_t CStringStack::GetSize() const
{
	return m_size;
}

std::string CStringStack::GetLastElement() const
{
	if (IsEmpty())
	{
		throw domain_error("Can't get last element from empty queue");
	}
	return m_top->str;
}

bool CStringStack::IsEmpty() const
{
	return (m_size == 0);
}

void CStringStack::Print() const
{
	if (IsEmpty())
	{
		throw domain_error("Can't print from empty queue");
	}
	Node *node = new Node;
	cout << m_top->str << endl;
}