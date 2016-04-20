
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;




template <typename T>
class Matrix
{
private:
	T **m;
	int columns, rows;
	friend istream& operator>>(istream& os, Matrix& object)
	{
		for (int i = 0; i < object.rows; i++)
		{
			for (int j = 0; j < object.columns; j++)
			{
				os >> object.m[i][j];
			}
		}
		return os;
	}
	friend ostream& operator<<(ostream& os, Matrix& object)
	{
		for (int i = 0; i < object.rows; i++)
		{
			for (int j = 0; j < object.columns; j++)
			{
				os << object.m[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}
public:

	
	class Badindex //класс исключений
	{
	public:
		int badindex;
		Badindex(int i) : badindex(i) {}
		void Report() 
		{
			cout << "This value can not be negative" << badindex << endl;
			return ;
		}
	        void Reportrow() 
		{
			cout << "This row does not exist" << endl;
			return ;
		}
	};	
	Matrix() :rows(0), columns(0), m(nullptr)
	{}
	Matrix(int kolstr, int kolstl) throw(Badindex &):
		columns(kolstl), rows(kolstr) 
	{
		
		
			if ((kolstr < 0) || (kolstl < 0))
			{
				if (kolstl < 0)
					throw Badindex(kolstl);
				else
					throw Badindex(kolstr);
			}

			m = new T *[rows];
			for (int i = 0; i < rows; i++)
			{
				m[i] = new T[columns];
				for (int j = 0; j < columns; j++)
				{
					m[i][j] = 0;
				}
			}

	}

	Matrix(int _rows, int _columns, int time) throw (Badindex &);
        void Zapoln(string name)
	{
		//char fulpath[256] = "path";
		string full_name;
		full_name = name;
		int  i,j;
		T a;
		fstream fin;
		//strcat_s(fulpath, path);
		fin.open(full_name, ios::in);//îòêðûòèå ôàéëà
		if (fin.is_open())
		{
			for (int j = 0; j<rows; j++)
			{
				for (int i = 0; i < columns; i++)
				{
					fin >> a;
					m[j][i] = a;
				}

			}
		}
		else
		 {
		    cout << "Îøèáêà, ïîïðîáóéòå åùå ðàç";
	            exit(100);
	}
		fin.close();
	}
	
	bool Show(int kolstr, int kolstl) const throw(Badindex &)
	{
	
		bool mark;
		
		if ((kolstr < 0) || (kolstl < 0))
		{
			if (kolstl < 0)
				throw Badindex(kolstl);
			else
				throw Badindex(kolstr);
		}
		for (int i = 0; i < kolstr; i++)
		{
			cout << endl;
			for (int j = 0; j < kolstl; j++)
			{
                                mark=true;
				cout << " " << m[i][j];
			}
		}
		cout << endl;
		
		return mark;
	}



	Matrix & operator=(const Matrix & matrix) {
		if (this != &matrix) { //перегруженный оператор присваивания
			for (int i = 0; i < rows; i++)
				delete[] m[i];
			delete[] m;
			columns = matrix.columns;
			rows = matrix.rows;
			m = new T *[rows];
			for (int j = 0; j<rows; j++)
			{
				m[j] = new T[columns];
				for (int i = 0; i < columns; i++)
				{
					m[j][i] = matrix.m[j][i];
				}

			}
		}
		return *this;
	}


        bool operator==(const Matrix &right) const// оператор сравнения
       {
          	if (rows != right.rows || columns != right.columns)
    		return false; // матрицы с разным количеством элементов

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (m[i][j] != right.m[i][j])
				return false; // матрицы не равны

	return true; // матрицы равны
        }




	~Matrix()
	{
		if (m != nullptr)
		{
			for (int i = 0; i < rows; i++)
			{
				delete[] m[i];
			}
			delete[] m;
		}
	}



	Matrix operator+ (const Matrix&) const;
	Matrix operator*(const Matrix&) const;
    T* operator[](int a) throw(Badindex &);
	int kolstrok() const;
	int kolstolb() const;
};

template <> class Matrix<char>
{
	private:
	char **m;
	int columns, rows;
	friend istream& operator>>(istream& os, Matrix& object)
	{
		for (int i = 0; i < object.rows; i++)
		{
			for (int j = 0; j < object.columns; j++)
			{
				os >> object.m[i][j];
			}
		}
		return os;
	}
	friend ostream& operator<<(ostream& os, Matrix& object)
	{
		for (int i = 0; i < object.rows; i++)
		{
			for (int j = 0; j < object.columns; j++)
			{
				os << object.m[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}
public:

	
	class Badindex //класс исключений
	{
	public:
		int badindex;
		Badindex(int i) : badindex(i) {}
		void Report() 
		{
			cout << "This value can not be negative" << badindex << endl;
			return ;
		}
	        void Reportrow() 
		{
			cout << "This row does not exist" << endl;
			return ;
		}
	};	
	Matrix() :rows(0), columns(0), m(nullptr)
	{}
	Matrix(int kolstr, int kolstl) throw(Badindex &):
		columns(kolstl), rows(kolstr) 
	{
		
		
			if ((kolstr < 0) || (kolstl < 0))
			{
				if (kolstl < 0)
					throw Badindex(kolstl);
				else
					throw Badindex(kolstr);
			}

			m = new char *[rows];
			for (int i = 0; i < rows; i++)
			{
				m[i] = new char[columns];
				for (int j = 0; j < columns; j++)
				{
					m[i][j] = 0;
				}
			}

	}

	Matrix(int _rows, int _columns, int time) throw (Badindex &);
        void Zapoln(string name)
	{
		//char fulpath[256] = "path";
		string full_name;
		full_name = name;
		int  i,j;
		char a;
		fstream fin;
		//strcat_s(fulpath, path);
		fin.open(full_name, ios::in);//îòêðûòèå ôàéëà
		if (fin.is_open())
		{
			for (int j = 0; j<rows; j++)
			{
				for (int i = 0; i < columns; i++)
				{
					fin >> a;
					m[j][i] = a;
				}

			}
		}
		else
		 {
		    cout << "Îøèáêà, ïîïðîáóéòå åùå ðàç";
	            exit(100);
	}
		fin.close();
	}
	
	bool Show(int kolstr, int kolstl) const throw(Badindex &)
	{
	
		bool mark;
		
		if ((kolstr < 0) || (kolstl < 0))
		{
			if (kolstl < 0)
				throw Badindex(kolstl);
			else
				throw Badindex(kolstr);
		}
		for (int i = 0; i < kolstr; i++)
		{
			cout << endl;
			for (int j = 0; j < kolstl; j++)
			{
                                mark=true;
				cout << " " << m[i][j];
			}
		}
		cout << endl;
		
		return mark;
	}



	Matrix & operator=(const Matrix & matrix) {
		if (this != &matrix) { //перегруженный оператор присваивания
			for (int i = 0; i < rows; i++)
				delete[] m[i];
			delete[] m;
			columns = matrix.columns;
			rows = matrix.rows;
			m = new char *[rows];
			for (int j = 0; j<rows; j++)
			{
				m[j] = new char[columns];
				for (int i = 0; i < columns; i++)
				{
					m[j][i] = matrix.m[j][i];
				}

			}
		}
		return *this;
	}


        bool operator==(const Matrix &right) const// оператор сравнения
       {
          	if (rows != right.rows || columns != right.columns)
    		return false; // матрицы с разным количеством элементов

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (m[i][j] != right.m[i][j])
				return false; // матрицы не равны

	return true; // матрицы равны
        }




	~Matrix()
	{
		if (m != nullptr)
		{
			for (int i = 0; i < rows; i++)
			{
				delete[] m[i];
			}
			delete[] m;
		}
	}



	Matrix operator+ (const Matrix& mat) const
	{
	int a,b,r;
	char rchar;
	Matrix res(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			a=m[i][j]-'0';
			b=mat.m[i][j]-'0';
			r=a+b;
			//itoa(r,rchar,10);
			rchar=r+'0';
			res.m[i][j] = rchar;
		}
	}
	return res;
	}
	Matrix operator*(const Matrix&) const;
        char* operator[](int a) throw(Badindex &);
	int kolstrok() const;
	int kolstolb() const;
	
};



//конструктор случайной матрицы
template <typename T>
Matrix<T>::Matrix(int _rows, int _columns, int time) throw (Badindex &)
{

	
	if ((_rows < 0) || (_columns < 0))
	{
		if (_rows < 0)
			throw Badindex(_rows);
		else
			throw Badindex(_columns);
	}
	rows = _rows;
	columns = _columns;
	m = new T *[rows];
	for (int i = 0; i < rows; i++)
	{
		m[i] = new T[columns];
	}
	srand(time);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			m[i][j] = rand() % 10;
		}
	}
};

template <typename T>
int Matrix<T>::kolstrok() const
{
	return rows;
}

template <typename T>
int Matrix<T>::kolstolb() const
{
	return columns;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &a) const
{

	Matrix res(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			res.m[i][j] = m[i][j] + a.m[i][j];
		}
	}
	return res;
}


template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &a) const
{
	int value=0;
	Matrix res(rows, a.columns);
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < a.columns; col++)
		{
			for (int inner = 0; inner < a.rows; inner++)
			{
				value += m[row][inner] * a.m[inner][col];
			}
			res.m[row][col] = value;
			value = 0;
		}
	}

	return res;
}


template <typename T>
T* Matrix<T>::operator[](int a) throw(Badindex &)
{
	T *newrow;
	newrow = new T[columns];
	if ((a > rows) || (a < 0))
	{
		throw Badindex(a);
	}
	for (int i = 0; i < columns; i++)
	{
		newrow[i] = m[a][i];
	}
	return newrow;
}
