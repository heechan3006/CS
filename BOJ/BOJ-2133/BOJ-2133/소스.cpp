#include <iostream>

using namespace std;

int N;
int D[31];
int A[31];

int main() {
	cin >> N;
	A[0] = 1;
	A[2] = 3;
	D[0] = 1;
	for (int i = 4; i <= N; i += 2) {
		A[i] = 2;
	}
	for (int i = 2; i <= N; i += 2) {
		for (int j = 2; j <= i; j += 2) {
			D[i] += A[j] * D[i - j];
		}
	}
	printf("%d\n", D[N]);
	return 0;
}