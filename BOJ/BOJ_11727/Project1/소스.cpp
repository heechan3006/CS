#include <iostream>

using namespace std;

int N;
int D[1001];

int main() {
	cin >> N;
	D[1] = 1;
	D[2] = 3;
	for (int i = 3; i <= N; i++) {
		D[i] = (D[i - 1] + 2 * D[i - 2]) % 10007;
	}
	printf("%d\n", D[N]);
	return 0;
}