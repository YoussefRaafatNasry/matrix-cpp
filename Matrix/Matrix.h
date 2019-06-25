#include <iostream>
using namespace std;

template <class T>
class Matrix
{

private:

	int rows, cols;
	T** values;

public:

	/* CONSTRUCTORS & DESTRUCTORS */
	Matrix();
	Matrix(int, int, int = 0);
	~Matrix();

	/* GETTERS */
	int get_rows();
	int get_cols();

};
