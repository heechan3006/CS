#include <iostream>

using namespace std;

int main() {
	int n = (1 << 5);
	int a = (1 << 4);
	int mod = (1 << 6);
	cout << (n << 2) % mod << "\n";
	return 0;
}