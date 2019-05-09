#include"Lista.h"
#include<iostream>
using namespace std;
int main()
{
	Lista<int> list;
	list.pushBack(1);
	list.pushBack(2);
	list.pushBack(3);
	list.pushBack(4);
	list.pushBack(5);
	list.pushFront(9);
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i]<<" ";
	}
	cout << endl;
	
	Lista<int> c;
	
	c = list;

	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;

	c.popBack();
	c.popFront();

	Lista<int> a = c;

	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << a.popBack() << " ";
	}

	cout << endl;

	return 0;
}