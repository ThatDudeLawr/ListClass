#pragma once
#include "Nod.h"

template <class T>
class Lista
{
	Nod<T>* start;
	Nod<T>* privEnd;
	Nod<T>* cautare(int poz) const;
	void empty();

public:
	Lista();
	Lista(Lista<T>& list);
	~Lista();
	void pushBack(T val);
	void pushFront(T val);
	T popBack();
	T popFront();
	int size() const;

	T operator [] (int i) const;
	Lista<T>& operator =(const Lista<T>& list);

	class iterator
	{
		Nod<T>* itr;
	public:

		//Constructor
		iterator(Nod<T>* current)
		{
			itr = current;
		};

		//Increment function
		void increment()
		{
			itr = itr->getNext();
		}

		//operators

		//Increment 
		iterator& operator++()
		{
			if (itr != NULL)
				itr = itr->getNext();
			return *this;
		}
		iterator& operator++(int)
		{
			if (itr != NULL)
				itr = itr->getNext();

			return *this;
		}

		//Boolean operators
		bool operator== (const iterator & cmp) const
		{
			return itr == cmp.itr;

		}
		bool operator!= (const iterator & cmp) const
		{
			return itr != cmp.itr;

		}

		T operator*() const
		{
			return itr->getData();
		}

		Nod<T>* operator->() const
		{
			return itr;
		}
	};

	iterator begin()
	{
		return iterator(start);
	};
	iterator end()
	{
		return iterator(NULL);
	};

};

template<class T>
Nod<T>* Lista<T>::cautare(int poz) const
{
	if (poz < 0)
	{
		return NULL;
	}
	Nod<T>* i = start;
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

template<class T>
void Lista<T>::empty()
{
	if (start == NULL)
	{
		return;
	}

	Nod<T>* i;
	while (start)
	{
		i = start->getNext();
		delete start;
		start = i;
	}
	privEnd = NULL;

}

template<class T>
Lista<T>::Lista()
{
	start = privEnd = NULL;
}

template<class T>
Lista<T>::Lista(Lista<T>& list)
{
	
	start = privEnd = NULL;
	*this = list;

}

template<class T>
Lista<T>::~Lista()
{
	empty();
}

template<class T>
void Lista<T>::pushBack(T val)
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
	
	if (start == NULL)
	{
		start = nod;
		privEnd = nod;
	}
	else
	{
		privEnd->setNext(nod);
		privEnd = nod;
	}
}

template<class T>
void Lista<T>::pushFront(T val)
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

	if (!start)
	{
		start = privEnd = nod;
	}
	else
	{
		nod->setNext(start);
		start = nod;
	}
}

template<class T>
T Lista<T>::popBack()
{
	if (!privEnd)
	{
		return NULL;
	}

	T val = privEnd->getData();

	if (privEnd == start)
	{
		delete privEnd;
		privEnd = start = NULL;
		return val;
	}

	Nod<T>* i = start;
	while (i->getNext()!=privEnd)
	{
		i = i->getNext();
	}
	
	i->setNext(NULL);
	delete privEnd;
	privEnd = i;
	return val;
}

template<class T>
T Lista<T>::popFront()
{
	if (!start)
	{
		return NULL;
	}

	T val = start->getData();

	if (start == privEnd)
	{
		delete privEnd;
		privEnd = start = NULL;
		return val;
	}

	Nod<T>* i = start->getNext();
	delete start;
	start = i;
	return val;
}

template<class T>
int Lista<T>::size() const
{
	if (start == NULL)
	{
		return NULL;
	}

	Nod<T>* i = start;
	int count=1;

	while (i->getNext())
	{
		count++;
		i = i->getNext();
	}

	return count;
}

template<class T>
T Lista<T>::operator [] (int i) const
{
	Nod<T>* nod = cautare(i);
	if (!nod)
	{
		return NULL;
	}
	else
	{
		return nod->getData();
	}
}

template<class T>
Lista<T>& Lista<T>::operator=(const Lista<T>& list)
{
	empty();
	const int & n = list.size();
	for (int i = 0; i < n; i++)
	{
		pushBack(list[i]);
	}
	return *this;
}
