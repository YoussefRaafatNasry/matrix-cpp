#include "Matrix.cpp"

int main() 
{
	Matrix<int> m1, m2, m3;
	cin >> m1 >> m2;
	m3 = m1 * m2;
	cout << m3;
	return 0;
}