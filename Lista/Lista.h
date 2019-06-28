#pragma once
#include "Nod.h"

template <class T>
class Lista
{
public:
	Lista();
	Lista(const Lista<T>& list);
	~Lista();

	void PushBack(T val);
	void PushFront(T val);

	T PopBack();
	T PopFront();

	int Size() const;

	T operator [] (int i) const;
	Lista<T>& operator =(const Lista<T>& list);

	bool operator ==(const Lista<T>& other);
	bool operator !=(const Lista<T>& other);

	Lista<T>& operator+(const Lista<T>& other);

protected:
	Nod<T>* GetAtIndex(int poz) const;
	void Empty();

protected:
	Nod<T>* m_start;
	Nod<T>* m_privEnd;
};

//Search for a specific position in the list
template<class T>
Nod<T>* Lista<T>::GetAtIndex(int poz) const
{
	if (poz < 0 || poz >= Size())
	{
		return NULL;
	}

	Nod<T>* i = m_start;

	while (poz)
	{
		if (!i)
		{
			return NULL;
		}

		i = i->getNext();
		poz--;
	}
	return i;
}

//Deletes all the nodes from the list
template<class T>
void Lista<T>::Empty()
{
	if (m_start == NULL)
	{
		return;
	}

	Nod<T>* i;
	while (m_start)
	{
		i = m_start->getNext();
		delete m_start;
		m_start = i;
	}

	//TODO: Check if we need m_start = NULL;
	m_privEnd = NULL;
}

template<class T>
Lista<T>::Lista()
{
	m_start = m_privEnd = NULL;
}

template<class T>
Lista<T>::Lista(const Lista<T>& list)
{
	m_start = m_privEnd = NULL;
	*this = list;
}

template<class T>
Lista<T>::~Lista()
{
	Empty();
}

//Add an element to the end of the list
template<class T>
void Lista<T>::PushBack(T val)
{
	Nod<T>* nod;
	try
	{
		nod = new Nod<T>(val);
	}
	catch (const std::bad_alloc&)
	{
		throw;
	}
	
	if (m_start == NULL)
	{
		m_start = nod;
		m_privEnd = nod;
	}
	else
	{
		m_privEnd->setNext(nod);
		m_privEnd = nod;
	}
}

//Add an element to the beginning of the list
template<class T>
void Lista<T>::PushFront(T val)
{
	Nod<T>* nod;
	try
	{
		nod = new Nod<T>(val);
	}
	catch (const std::bad_alloc&)
	{
		throw;
	}

	if (!m_start)
	{
		m_start = m_privEnd = nod;
	}
	else
	{
		nod->setNext(m_start);
		m_start = nod;
	}
}

//Deletes the last element from the list
template<class T>
T Lista<T>::PopBack()
{
	if (!m_privEnd)
	{
		return NULL;
	}

	T val = m_privEnd->getData();

	if (m_privEnd == m_start)
	{
		delete m_privEnd;
		m_privEnd = m_start = NULL;
		return val;
	}
	else
	{
		Nod<T>* i = m_start;
		while (i->getNext() != m_privEnd)
		{
			i = i->getNext();
		}

		i->setNext(NULL);
		delete m_privEnd;
		m_privEnd = i;
		return val;
	}
}

//Deletes the first element of the list
template<class T>
T Lista<T>::PopFront()
{
	if (!m_start)
	{
		return NULL;
	}

	T val = m_start->getData();

	if (m_start == m_privEnd)
	{
		delete m_privEnd;
		m_privEnd = m_start = NULL;
		return val;
	}
	else
	{
		Nod<T>* i = m_start->getNext();
		delete m_start;
		m_start = i;
		return val;
	}
}

//Return the list number of nodes
template<class T>
int Lista<T>::Size() const
{
	if (m_start == NULL)
	{
		return 0;
	}

	Nod<T>* i = m_start;
	int count=1;

	while (i->getNext())
	{
		count++;
		i = i->getNext();
	}

	return count;
}

//Makes the list accessible like an array(a[0], a[1], ...)
template<class T>
T Lista<T>::operator [] (int i) const
{
	Nod<T>* nod = GetAtIndex(i);
	if (!nod)
	{
		return NULL;
	}
	else
	{
		return nod->getData();
	}
}

// Copy constructor on assigment overload.
template<class T>
Lista<T>& Lista<T>::operator=(const Lista<T>& list)
{
	Empty();
	const int & n = list.Size();
	for (int i = 0; i < n; i++)
	{
		PushBack(list[i]);
	}
	return *this;
}

template<class T>
inline bool Lista<T>::operator==(const Lista<T>& other)
{
	int currentSize = Size();
	int otherSize	= other.Size();

	if (currentSize != otherSize) return false;

	for (int i = 0; i < currentSize; i++)
	{
		//TODO: Make this look prettier.
		if (this->operator[](i) != other[i])
		{
			return false;
		}
	}

	return true;
}

template<class T>
inline bool Lista<T>::operator!=(const Lista<T>& other)
{
	return !(this==other);
}

template<class T>
inline Lista<T>& Lista<T>::operator+(const Lista<T>& other)
{
    Lista<T>& result = (*this);

	for (int i = 0; i < other.Size(); i++)
	{
		result.PushBack(other[i]);
	}

	return result;
}