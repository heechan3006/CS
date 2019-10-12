#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int V[101];
int D[101][1001];
int N, M, S;
int dp(int now, int sum) {
	if (sum < 0 || sum > M) return -100;
	if (now == N ) return sum;
	if (D[now][sum] != -1) return D[now][sum];
	D[now][sum] = max(dp(now + 1, sum + V[now + 1]), dp(now + 1, sum - V[now + 1]));
	return D[now][sum];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++) {
		cin >> V[i];
	}
	memset(D, -1, sizeof(D));
	int ans = dp(0, S);
	if (ans == -100) {
		cout << -1 << "\n";
	}
	else {
		cout << ans << "\n";
	}
	return 0;
}