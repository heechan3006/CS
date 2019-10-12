#include <iostream>
#include <algorithm>

using namespace std;

int N;
int D[100010];
int A[100010];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	
	
	for (int i = 1; i <= N; i++) {
		if (D[i - 1] + A[i] > A[i]) {
			D[i] = D[i - 1] + A[i];
		}
		else {
			D[i] = A[i];
		}
	}
	int ans = D[1];
	for (int i = 2; i <= N; i++) {
		ans = max(ans, D[i]);
	}
	printf("%d\n", ans);
}