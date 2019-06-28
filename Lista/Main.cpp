#include<iostream>
#include"Lista.h"

using namespace std;

void DebugPrintList(const List<int>& list);

void TestPushBack()
{

}

int main()
{
	List<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	list.PushFront(9);

	DebugPrintList(list);

	List<int> c;
	
	c = list;

	cout << "List: ";
	DebugPrintList(c);

	cout << "L == C " << (list == c) << endl;

	c.PopBack();
	c.PopFront();

	List<int> a = c;

	cout << "A: ";
	DebugPrintList(a);

    cout << "List+C: ";
	DebugPrintList(list + c);

	for (int i = 0; i < 10; i++)
	{
		cout << a.PopBack() << " ";
	}

	cout << endl;

	cout << "L == C " << (list == c) << endl;
	cout << "C == A " << (list == c) << endl;

	return 0;
}

void DebugPrintList(const List<int>& list)
{
	for (int i = 0; i < list.Size(); i++)
	{
		cout << list[i] << " ";
	}

	cout << endl;
}
