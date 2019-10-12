#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 987654321
#define MAXN 1001
using namespace std;

int D[MAXN];
int N;
int A[MAXN];
int dp(int now) {
	if (now == N-1) return 0;
	if (now >= N) return INF;
	if (D[now] != -1) return D[now];
	D[now] = INF;
	for (int i = 1; i <= A[now]; i++) {
		D[now] = min(D[now], dp(now + i) + 1);
	}
	return D[now];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	memset(D, -1, sizeof(D));
	int ans =dp(0);
	if (ans == INF) {
		cout << -1 << "\n";
	}
	else{
		cout << ans << "\n";
	}
	return 0;
}