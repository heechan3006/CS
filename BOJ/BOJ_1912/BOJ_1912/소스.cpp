#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 100001
#define INF 100000000
using namespace std;

int A[MAXN];
int D[MAXN];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		D[i] = -INF;
	}
	D[0] = A[0];
	int ans = A[0];
	for (int i = 1; i < N; i++) {
		D[i] = max(A[i], A[i] + D[i-1]);
		ans = max(ans, D[i]);
	}
	cout << ans << "\n";
}
