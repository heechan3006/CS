#include <iostream>
#include <algorithm>

using namespace std;

int N;
int D[2][1001];
int A[1001];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= i; j++) {
			if (A[i] > A[j]) {
				sum = max(sum, D[0][j]);
			}		
		}
		D[0][i] = sum + 1;
	}
	
	for (int i = N; i >= 1; i--) {
		int sum = 0;
		for (int j = N; j > i; j--) {
			if (A[i] > A[j]) {
				sum = max(sum, D[1][j]);
			}
		}
		if (D[1][i] < sum+1){
			D[1][i] = sum + 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (ans < D[0][i] + D[1][i]) {
			ans = D[0][i] + D[1][i];
		}
	}
	printf("%d\n", ans-1);
	return 0;
}
