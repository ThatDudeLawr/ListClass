#pragma once
#include<iostream>

template <class T>
class Node
{
public:
	Node(T val);
	~Node();

    Node<T>* GetNext() const;
    void SetNext(Node<T>* p );
	
    T GetData() const;
	void SetData(T val);

protected:
    T m_data; //Stores a value in the node
    Node* m_next; //Points toward the next node from the list
};

#include "Nod.impl"