#include <iostream>

using namespace std;

int N;
int D[11];

int go(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else if (n == 3) {
		return 4;
	}
	if (D[n] != 0) {
		return D[n];
	}
	else{
		D[n] = go(n - 1) + go(n - 2) + go(n - 3);
		return D[n];
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> N;
		printf("%d\n", go(N));
	}
	return 0;
}