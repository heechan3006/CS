#include <iostream>

using namespace std;

int N;
int D[1001];

int go(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 3;
	}
	if (D[n] != 0) {
		return D[n];
	}
	else{
		D[n] = (go(n - 1) + 2 * go(n - 2)) % 10007;
		return D[n];
	}
}
int main() {
	cin >> N;
	printf("%d\n", go(N));
	return 0;
}