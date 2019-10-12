#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1001];
int D[1001];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= i ; j++){
			if (A[i] > A[j]) {
				sum = max(sum, D[j]);
			}
		}
		D[i] = sum + 1;
		ans = max(ans, D[i]);
	}
	printf("%d\n", ans);
	return 0;
}