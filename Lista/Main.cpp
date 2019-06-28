#include<iostream>
#include"Lista.h"

using namespace std;

#define LOGFUNCTION() cout << "Running: " << __FUNCTION__ << "\n";
#define LOGSPACE()    cout << "------------------------------------------------"; cout << endl; cout << endl;

void DebugPrintList(const List<int>& list);

void TestPushBack()
{
    LOGFUNCTION();

    List<int> list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.PushBack(4);
    list.PushBack(5);

    cout << "1 2 3 4 5" << endl;
    DebugPrintList(list);

    LOGSPACE();
}

void TestPushFront()
{
    LOGFUNCTION();

    List<int> list;
    list.PushFront(1);
    list.PushFront(2);
    list.PushFront(3);
    list.PushFront(4);
    list.PushFront(5);

    cout << "5 4 3 2 1" << endl;
    DebugPrintList(list);

    LOGSPACE();
}

void TestPopFront()
{
    LOGFUNCTION();

    List<int> list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.PushBack(4);
    list.PushBack(5);

    list.PopFront();
    list.PopFront();

    cout << "3 4 5" << endl;
    DebugPrintList(list);

    LOGSPACE();
}

void TestPopBack()
{
    LOGFUNCTION();

    List<int> list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.PushBack(4);
    list.PushBack(5);

    list.PopBack();
    list.PopBack();

    cout << "1 2 3" << endl;
    DebugPrintList(list);

    LOGSPACE();
}

void TestEqualsOperator()
{
    LOGFUNCTION();

    List<int> list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.PushBack(4);
    list.PushBack(5);

    List<int> copy = list;

    DebugPrintList(list);
    DebugPrintList(copy);

    LOGSPACE();
}

void TestCopyConstructor()
{
    LOGFUNCTION();

    List<int> list;
    list.PushBack(3);
    list.PushBack(4);
    list.PushBack(5);
    list.PushBack(6);
    list.PushBack(7);

    List<int> copy(list);

    DebugPrintList(list);
    DebugPrintList(copy);

    cout << endl;

    cout << "Removing elements from the copied list.";
    
    copy.PopFront();
    copy.PopBack();
    
    cout << "Initial List still contains: ";
    DebugPrintList(list);

    DebugPrintList(copy);
    cout << "4 5 6" << endl;

    LOGSPACE();
}

void TestDoubleEqualOperator()
{
    LOGFUNCTION();

    List<int> listA;
    listA.PushBack(3);
    listA.PushBack(4);
    listA.PushBack(5);
    listA.PushBack(6);
    listA.PushBack(7);

    List<int> listB;
    listB.PushBack(3);
    listB.PushBack(4);
    listB.PushBack(5);
    listB.PushBack(6);
    listB.PushBack(7);

    DebugPrintList(listA);
    DebugPrintList(listB);

    cout << "Are equal: " << (listA == listB) << endl;

    LOGSPACE();
}

void TestNotEqualOperator()
{
    LOGFUNCTION();

    List<int> listA;
    listA.PushBack(3);
    listA.PushBack(4);
    listA.PushBack(5);
    listA.PushBack(6);
    listA.PushBack(7);

    List<int> listB;
    listB.PushBack(1);
    listB.PushBack(2);
    listB.PushBack(3);
    listB.PushBack(4);
    listB.PushBack(5);

    DebugPrintList(listA);
    DebugPrintList(listB);

    cout << "Not equal: " << (listA != listB) << endl;

    LOGSPACE();
}

void TestSmallerOperator()
{
    LOGFUNCTION();

    List<int> listA;
    listA.PushBack(1);
    listA.PushBack(2);
    listA.PushBack(3);

    List<int> listB;
    listB.PushBack(1);
    listB.PushBack(2);
    listB.PushBack(3);
    listB.PushBack(4);
    listB.PushBack(5);

    DebugPrintList(listA);
    DebugPrintList(listB);

    cout << "A < B: " << (listA < listB) << endl << endl;

    List<int> listC;
    listC.PushBack(1);
    listC.PushBack(2);
    listC.PushBack(3);

    List<int> listD;
    listD.PushBack(0);
    listD.PushBack(2);
    listD.PushBack(3);
    listD.PushBack(4);
    listD.PushBack(5);

    DebugPrintList(listC);
    DebugPrintList(listD);

    cout << "C < D: " << (listC < listD) << endl << endl;

    List<int> listE;
    listE.PushBack(1);
    listE.PushBack(2);
    listE.PushBack(3);

    List<int> listF;
    listF.PushBack(1);
    listF.PushBack(0);
    listF.PushBack(2);
    listF.PushBack(0);
    listF.PushBack(3);

    DebugPrintList(listE);
    DebugPrintList(listF);

    cout << "E < F: " << (listE < listF) << endl << endl;

    LOGSPACE();
}

void TestSmallerOrEqualOperator()
{
    LOGFUNCTION();

    List<int> listA;
    listA.PushBack(1);
    listA.PushBack(2);
    listA.PushBack(3);

    List<int> listB;
    listB.PushBack(1);
    listB.PushBack(2);
    listB.PushBack(3);
    listB.PushBack(4);
    listB.PushBack(5);

    DebugPrintList(listA);
    DebugPrintList(listB);

    cout << "A < B: " << (listA <= listB) << endl << endl;

    List<int> listC;
    listC.PushBack(1);
    listC.PushBack(2);
    listC.PushBack(3);

    List<int> listD;
    listD.PushBack(0);
    listD.PushBack(2);
    listD.PushBack(3);
    listD.PushBack(4);
    listD.PushBack(5);

    DebugPrintList(listC);
    DebugPrintList(listD);

    cout << "C < D: " << (listC <= listD) << endl << endl;

    List<int> listE;
    listE.PushBack(1);
    listE.PushBack(2);
    listE.PushBack(3);

    List<int> listF;
    listF.PushBack(1);
    listF.PushBack(0);
    listF.PushBack(2);
    listF.PushBack(0);
    listF.PushBack(3);

    DebugPrintList(listE);
    DebugPrintList(listF);

    cout << "E < F: " << (listE <= listF) << endl << endl;

    LOGSPACE();
}

void TestHigherOperator()
{
    LOGFUNCTION();

    List<int> listA;
    listA.PushFront(1);
    listA.PushFront(2);
    listA.PushFront(3);

    List<int> listB;
    listB.PushFront(1);
    listB.PushFront(2);
    listB.PushFront(3);
    listB.PushFront(4);
    listB.PushFront(5);

    DebugPrintList(listA);
    DebugPrintList(listB);

    cout << "A > B: " << (listA > listB) << endl << endl;

    List<int> listC;
    listC.PushFront(1);
    listC.PushFront(2);
    listC.PushFront(3);

    List<int> listD;
    listD.PushFront(0);
    listD.PushFront(2);
    listD.PushFront(3);
    listD.PushFront(4);
    listD.PushFront(5);

    DebugPrintList(listC);
    DebugPrintList(listD);

    cout << "C > D: " << (listC > listD) << endl << endl;

    List<int> listE;
    listE.PushFront(1);
    listE.PushFront(2);
    listE.PushFront(3);

    List<int> listF;
    listF.PushFront(1);
    listF.PushFront(0);
    listF.PushFront(2);
    listF.PushFront(0);
    listF.PushFront(3);

    DebugPrintList(listE);
    DebugPrintList(listF);

    cout << "E > F: " << (listE > listF) << endl << endl;

    LOGSPACE();
}

void TestHigherOrEqualOperator()
{
    LOGFUNCTION();

    List<int> listA;
    listA.PushFront(1);
    listA.PushFront(2);
    listA.PushFront(3);

    List<int> listB;
    listB.PushFront(1);
    listB.PushFront(2);
    listB.PushFront(3);
    listB.PushFront(4);
    listB.PushFront(5);

    DebugPrintList(listA);
    DebugPrintList(listB);

    cout << "A >= B: " << (listA >= listB) << endl << endl;

    List<int> listC;
    listC.PushFront(1);
    listC.PushFront(2);
    listC.PushFront(3);

    List<int> listD;
    listD.PushFront(0);
    listD.PushFront(2);
    listD.PushFront(3);
    listD.PushFront(4);
    listD.PushFront(5);

    DebugPrintList(listC);
    DebugPrintList(listD);

    cout << "C >= D: " << (listC >= listD) << endl << endl;

    List<int> listE;
    listE.PushFront(1);
    listE.PushFront(2);
    listE.PushFront(3);

    List<int> listF;
    listF.PushFront(1);
    listF.PushFront(0);
    listF.PushFront(2);
    listF.PushFront(0);
    listF.PushFront(3);

    DebugPrintList(listE);
    DebugPrintList(listF);

    cout << "E >= F: " << (listE >= listF) << endl << endl;

    LOGSPACE();
}

void TestPlusOperator()
{
    LOGFUNCTION();

    List<int> listA;
    listA.PushBack(1);
    listA.PushBack(2);
    listA.PushBack(3);

    List<int> listB;
    listB.PushBack(2);
    listB.PushBack(4);
    listB.PushBack(6);

    DebugPrintList(listA);
    DebugPrintList(listB);

    cout << "Concateneted: " << endl;
    DebugPrintList(listA + listB);
    cout << "1 2 3 2 4 6" << endl;

    LOGSPACE();
}

int main()
{
    TestPushBack();
    TestPushFront();
    TestPopFront();
    TestPopBack();
    TestEqualsOperator();
    TestCopyConstructor();
	
    TestDoubleEqualOperator();
    TestNotEqualOperator();

    TestSmallerOperator();
    TestSmallerOrEqualOperator();
    TestHigherOperator();
    TestHigherOrEqualOperator();

    TestPlusOperator();

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
