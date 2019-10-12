#include <iostream>
#include <algorithm>

using namespace std;

int N;
int D[301];
int A[301];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	D[1] = A[1];
	D[2] = A[1] + A[2];
	for (int i = 3; i <= N; i++) {
		D[i] = max(D[i - 3] + A[i - 1] + A[i], D[i - 2] + A[i]);
	}
	printf("%d\n", D[N]);
	return 0;
}