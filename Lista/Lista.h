#pragma once
#include "Nod.h"

template <class T>
class List
{
public:
	List();
    List(const T& val);
	List(const List<T>& list);

	~List();

	void PushBack(T val);
	void PushFront(T val);

	T PopBack();
	T PopFront();

	int Size() const;

    operator T() const;
	T operator [] (int i) const;
	List<T>& operator =(const List<T>& list);

	bool operator ==(const List<T>& other);
	bool operator !=(const List<T>& other);

    bool operator <(const List<T>& other);
    bool operator >(const List<T>& other);

    bool operator <=(const List<T>& other);
    bool operator >=(const List<T>& other);

	List<T>& operator+(const List<T>& other);

	List<T>& operator*(const List<T>& other);

	List<T>& operator>>(int pos);

	List<T>& operator<<(int pos);


protected:
	Node<T>* GetAtIndex(int poz) const;
	void Empty();

protected:
	Node<T>* m_start;
	Node<T>* m_privEnd;
};

#include "Lista.impl"