#include <iostream>

using namespace std;

int D[1001];
int A[1001];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		D[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (A[j] < A[i] && D[i] < D[j] + 1) {
				D[i] = D[j] + 1;
			}
		}
		if (ans < D[i]) ans = D[i];
	}
	cout << ans << "\n";
}