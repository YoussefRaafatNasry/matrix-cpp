#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Matrix
{

private:

	int rows, cols;
	T** values;

public:

	/* CONSTRUCTORS & DESTRUCTORS */
	Matrix(int = 0, int = 0);
	Matrix(int, int, int);
	Matrix(int, int, T*);
	~Matrix();


	/* GETTERS */
	int get_rows();
	int get_cols();


	/* ARITHMETIC OPERATORS */
	void operator=(Matrix<T>&);
	Matrix<T> operator+(Matrix<T>&);
	Matrix<T> operator-(Matrix<T>&);
	Matrix<T> operator*(Matrix<T>&);

	void operator=(T);
	Matrix<T> operator+(T);
	Matrix<T> operator-(T);
	Matrix<T> operator*(T);


	/* IO OPERATORS */
	template <typename U>
	friend istream& operator>>(istream&, Matrix<U>&);
	template <typename U>
	friend ostream& operator<<(ostream&, Matrix<U>&);

};
