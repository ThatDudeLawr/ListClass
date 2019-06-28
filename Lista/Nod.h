#pragma once
#include<iostream>

template <class T>
class Node
{
	T data; //Stores a value in the node
	Node* next; //Points toward the next node from the list
public:
	Node(T val);
	~Node();
	Node<T>* getNext() const;
	T getData() const;
	void setNext(Node<T>* p );
	void setData(T val);
};

#include "Nod.impl"