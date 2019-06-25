#include "Matrix.h"

/******************************/
/* CONSTRUCTORS & DESTRUCTORS */
/******************************/

template <class T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
	values = new T*[rows];
	for (int i = 0; i < rows; i++)
	{
		values[i] = new T[cols];
	}
}

template <class T>
Matrix<T>::Matrix(int rows, int cols, int value) : Matrix(rows, cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			values[i][j] = value;
		}
	}
}

template <class T>
Matrix<T>::Matrix(int rows, int cols, T* arr) : Matrix(rows, cols)
{
	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			values[i][j] = arr[k++];
		}
	}
}

template <class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < rows; i++) {
		delete[] values[i];
	}
	delete[] values;
}


/***********/
/* GETTERS */
/***********/

template <class T>
int Matrix<T>::get_rows()
{
	return rows;
}

template <class T>
int Matrix<T>::get_cols()
{
	return cols;
}


/****************/
/* IO OPERATORS */
/****************/

template <typename U>
istream& operator>>(istream& in, Matrix<U>& m)
{
	cout << "Rows: ";
	in >> m.rows;
	cout << "Columns: ";
	in >> m.cols;

	m.values = new U*[m.rows];
	for (int i = 0; i < m.rows; i++)
	{
		m.values[i] = new U[m.cols];
	}

	cout << "Values: " << endl;
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			in >> m.values[i][j];
		}
	}

	return in;
}

template <typename U>
ostream& operator<<(ostream& out, Matrix<U>& m)
{
	int* spacing = new int[m.rows];

	for (int j = 0; j < m.cols; j++)
	{
		int max = 0;
		for (int i = 0; i < m.rows; i++)
		{
			int length = to_string(m.values[i][j]).length();
			if (max < length) max = length;
		}
		spacing[j] = max + (j != 0);
	}

	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			out << setw(spacing[j]) << right << m.values[i][j];
		}
		out << endl;
	}

	return out;
}