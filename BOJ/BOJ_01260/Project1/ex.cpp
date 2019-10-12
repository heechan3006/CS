#include <iostream>

using namespace std;

void SwapFunction(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	int x = 10, y = 3;

	SwapFunction(x, y);

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	return 0;
}