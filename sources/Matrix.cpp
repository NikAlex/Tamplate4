// lab3.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "Matrix.hpp"
#include <iostream>
#include <fstream>

using namespace std;





/*
int _tmain(int argc, _TCHAR* argv[])
{
	int kolstr, kolstl, kolstr3, kolstl3, time;;
	char sogl[2],path[256];
	cout << "enter 'y' to create matrix automatically or 'n' to create manually" << endl;
	cin >> sogl;
	if (strcmp("n", sogl) == 0)
	{
	cout << "enter number of lines" << endl;
	cin >> kolstr;
	cout << "enter number of columns" << endl;
	cin >> kolstl;
	Matrix mat(kolstr,kolstl);
	cout << "enter path to the source of numbers" << endl;
	_flushall();
	cin.getline(path, 255);
	mat.Zapoln(path);
	mat.Show(kolstr,kolstl);
	cout << "enter 'p' to add new matrix to current" << endl;
		cin >> sogl;
		if (strcmp("p", sogl) == 0)
		{
			
			cout << "new matrix" << endl;
			cin >> time;
			Matrix mat2(kolstr, kolstl, time);
			mat2.Show(kolstr,kolstl);
			Matrix res(kolstr, kolstl);
			res = mat2 + mat;
			cout << "result";
			res.Show(kolstr, kolstl);
		}
		cout << "enter 'u' to multiply new matrix to current" << endl;
		cin >> sogl;
		if (strcmp("u", sogl) == 0)
		{
			cout << "enter number to create ne values" << endl;
			cin >> time;
			Matrix mat3(kolstr, kolstl,time);
			mat3.Show(kolstr,kolstl);
			Matrix res3(kolstr, kolstl);
			res3 = mat * mat3;
			cout << "result";
			res3.Show(kolstr, kolstl);
			
		}
		cout << "enter number to take a raw from the matrix" << endl;
		cin >> sogl;
		int ch = atoi(sogl)-1;
		if (ch>=0)
		{
			int *res4;
			res4 = mat[ch];
			int r = mat.kolstolb();
			for (int i = 0; i < r; i++)
			{
				cout << res4[i] << " ";
			}
		}
		cout << "enter 'r' to take a number of rows from the matrix" << endl;
		cin >> sogl;
		if (strcmp("r", sogl) == 0)
		{
			int r = mat.kolstrok();
			cout << r << endl;
		}
		cout << "enter 's' to take a number of columns from the matrix" << endl;
		cin >> sogl;
		if (strcmp("s", sogl) == 0)
		{
			int r = mat.kolstolb();
			cout << r << endl;
		}
	}

	system("pause");
	return 0;
}*/

