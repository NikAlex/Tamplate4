// lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <iostream>

using namespace std;
class Vector
{
public:
	int size;
	int *elements;
	Vector()
	{
		size = 3;
		elements = new int[3];
		elements[0] = 0;
		elements[1] = 0;
		elements[2] = 0;
	}
	Vector(int marker)
	{
		int el;
		printf("enter size\n");
		scanf_s("%d", &size);
		elements = new int[size];
		for (int i = 0; i < size; i++)
		{
			printf("enter element\n");
			scanf_s("%d", &el);
			elements[i] = el;
		}

	}

	Vector(const Vector & qw);
	void add(int addel)
	{
		int *newelements = new int[size + 1];
		for (int i = 0; i < size; i++)
			newelements[i] = elements[i];
		newelements[size] = addel;
		size = size + 1;
		for (int i = 0; i < size; i++)
			elements[i] = newelements[i];
		delete[] newelements;
	}
	void del(int num)
	{
		int *newelements = new int[size - 1];
		for (int i = 0; i < size - 1; i++)
		{
			if (i < num - 1)
				newelements[i] = elements[i];
			else
				newelements[i] = elements[i + 1];
		}
		size = size - 1;
		for (int i = 0; i < size; i++)
			elements[i] = newelements[i];
		delete[] newelements;
	}
	
	Vector & operator=(const Vector &vec)
	{
		if (this != &vec)
		{
			cout << "peregruzhen operator prysv" << endl;
			delete[] elements;
			size = vec.size;
			elements = new int[size];
			for (int i = 0; i < size; i++)
				elements[i] = vec.elements[i];
		}
		else
		{
			cout << "Samoprisvivanie" << endl;
		}
		return *this;
	}
	
	~Vector()
	{
		cout << 
			"destructor" << endl;
		delete[] elements;
	//	delete[] newelements;
	}
};


Vector::Vector(const Vector &obj)
{
	cout << "copy-constructor" << endl;
	elements = new int[obj.size];
	for (int i = 0; i < obj.size; i++)
		elements[i] = obj.elements[i];
	size = obj.size;
}







int _tmain(int argc, _TCHAR* argv[])
{
	int marker;
	int adel;
	int num;
	printf("enter number to create an array manually, enter 0 to create automatically\n");
	scanf_s("%d", &marker);
	//if (marker)
	Vector V(marker);
//	else
//	Vector Vec;
	/*for (int i = 0; i < V.size; i++)
		printf("el=%d\n", V.elements[i]);*/
	if (marker)
	{
		printf("enter one int to add into vector or eneter 0 to skip\n");
		scanf_s("%d", &adel);
		if (adel) V.add(adel);
		printf("result\n");
		for (int i = 0; i < V.size; i++)
			printf("el=%d\n", V.elements[i]);
		printf("enter position to delete element or 0 to skip\n");
		scanf_s("%d", &num);
		if (num)
		V.del(num);
		printf("result\n");
		for (int i = 0; i < V.size; i++)
			printf("el=%d\n", V.elements[i]);
		int pos;
		printf("enter position of element to extract\n");
		scanf_s("%d", &pos);
		printf("element=%d", V.elements[pos-1]);
	}
	system("pause");
	return 0;
}

