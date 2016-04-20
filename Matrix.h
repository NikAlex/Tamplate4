#include <iostream>
#include <fstream>


using namespace std;

class Matrix
{
private:
	int **m;
	int columns, rows;
public:
	Matrix() :rows(0), columns(0), m(nullptr)
	{}
	Matrix(int kolstr, int kolstl):
		columns(kolstl), rows(kolstr)
	{
		m = new int *[rows];
		for (int i = 0; i<rows; i++)
		{
			m[i] = new int[columns];
			for (int j = 0; j < columns; j++)
			{
				m[i][j] = 0;
			}

		}

	}

	Matrix(int _rows, int _columns, int time);
	void Zapoln(char path[256])
	{
		char fulpath[256] = "D:\\labiu8\\2 ñåì\\lab3\\Debug\\";
		int a, i, j;
		fstream fin;
		strcat_s(fulpath, path);
		fin.open(fulpath, ios::in);//îòêðûòèå ôàéëà
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
		fin.close();
	}
	void Show(int kolstr, int kolstl) const
	{
		for (int i = 0; i < kolstr; i++)
		{
			cout << endl;
			for (int j = 0; j < kolstl; j++)
			{

				cout << " " << m[i][j];
			}
		}
		cout << endl;
	}
	Matrix(const Matrix &M) :
		columns(M.columns),
		rows(M.rows)
	{
		m = new int*[rows];
	    for (int i = 0; i < rows; i++)
		{
			m[i] = new int[columns];
			for (int j = 0; j < columns; j++)
			{

				m[i][j] = M.m[i][j];
			}
		}
	}



	Matrix & operator=(const Matrix & matrix) {
		if (this != &matrix) { //ïåðåãðóæåííûé îïåðàòîð ïðèñâàèâàíèÿ
			for (int i = 0; i < rows; i++)
				delete[] m[i];
			delete[] m;
			columns = matrix.columns;
			rows = matrix.rows;
			m = new int *[rows];
			for (int j = 0; j<rows; j++)
			{
				m[j] = new int[columns];
				for (int i = 0; i < columns; i++)
				{
					m[j][i] = matrix.m[j][i];
				}

			}
		}
		return *this;
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
    int* operator[](int a) const;
	int kolstrok() const;
	int kolstolb() const;
};


//êîíñòðóêòîð ñëó÷àéíîé ìàòðèöû
Matrix::Matrix(int _rows, int _columns, int time)
{
	rows = _rows;
	columns = _columns;
	m = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		m[i] = new int[columns];
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

int Matrix::kolstrok() const
{
	return rows;
}


int Matrix::kolstolb() const
{
	return columns;
}

Matrix Matrix::operator+(const Matrix &a) const
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

Matrix Matrix::operator*(const Matrix &a) const
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

int* Matrix::operator[](int a) const
{
	int *newrow;
	newrow = new int[columns];
	for (int i = 0; i < columns; i++)
	{
		newrow[i] = m[a][i];
	}
	
	return newrow;
}
