#pragma once
#include<iostream>

template <class T>
class Nod
{
	T data; //Stores a value in the node
	Nod* next; //Points toward the next node from the list
public:
	Nod(T val);
	~Nod();
	Nod<T>* getNext() const;
	T getData() const;
	void setNext(Nod<T>* p );
	void setData(T val);
};

template<class T>
Nod<T>::Nod(T val)
{
	data = val;
	next = NULL;
}

template<class T>
Nod<T>::~Nod()
{
}

template<class T>
Nod<T>* Nod<T>::getNext() const
{
	return next;
}

template<class T>
T Nod<T>::getData() const
{
	return data;
}

template<class T>
void Nod<T>::setNext(Nod<T>* p)
{
	next = p;
}

template<class T>
void Nod<T>::setData(T val)
{
	data = val;
}
