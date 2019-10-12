#include <iostream>
#define MAX_N 1000000000
using namespace std;

int N;
long long D[101][10];

int main() {
	cin >> N;
	for (int i = 1; i <= 9; i++) {
		D[1][i] = 1;
	}
	for (int i = 2; i <= N; i++){
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				D[i][j] = D[i - 1][j + 1]%MAX_N;
			}
			else if (j == 9) {
				D[i][j] = D[i - 1][j - 1]%MAX_N;
			}
			else {
				D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1])%MAX_N;
			}
		}
	}
	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += D[N][i];
	}
	printf("%lld\n", sum%MAX_N);
	
}