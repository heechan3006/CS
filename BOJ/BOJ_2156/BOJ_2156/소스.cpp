#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 10001
using namespace std;

int D[MAXN];
int A[MAXN];

int N;
int go(int n) {
	if (n < 0) return 0;
	if (n == 0) return D[n] = A[0];
	if (D[n] != -1) return D[n];
	D[n] = max(go(n-1),max(go(n - 3) + A[n - 1] + A[n], go(n - 2)+A[n]));
	return D[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	memset(D, -1, sizeof(D));
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cout << go(N-1) << "\n";
}