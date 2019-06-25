#include "Matrix.h"

/******************************/
/* CONSTRUCTORS & DESTRUCTORS */
/******************************/

template <class T>
Matrix<T>::Matrix()
{
	rows = 0;
	cols = 0;
}

template <class T>
Matrix<T>::Matrix(int rows, int cols, int value) : rows(rows), cols(cols)
{
	values = new T*[rows];
	for (int i = 0; i < rows; i++)
	{
		values[i] = new T[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			values[i][j] = value;
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

template<class T>
int Matrix<T>::get_rows()
{
	return rows;
}

template<class T>
int Matrix<T>::get_cols()
{
	return cols;
}
