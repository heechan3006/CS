#include <iostream>

using namespace std;

int N;
int D[1001][10];

int main() {
	cin >> N;
	for (int i = 0; i <= 9; i++) {
		D[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				D[i][j] += D[i-1][k]%10007;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += D[N][i]%10007;
	}
	printf("%d\n", sum%10007);
}