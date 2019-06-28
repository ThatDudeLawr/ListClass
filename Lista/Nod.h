#pragma once
#include<iostream>

template <class T>
class Node
{
public:
	Node(T val);
	~Node();

    Node<T>* getNext() const;
    void setNext(Node<T>* p );
	
    T getData() const;
	void setData(T val);

protected:
    T data; //Stores a value in the node
    Node* next; //Points toward the next node from the list
};

#include "Nod.impl"