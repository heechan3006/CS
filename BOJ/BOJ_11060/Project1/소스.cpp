#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 1000
#define INF 987654321
using namespace std;

int map[MAXN];
int cache[MAXN];
int N;
int dp(int now) {
	if (now >= N) return INF;
	if (now == N - 1) return 0;
	int& ret = cache[now];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 1; i <= map[now]; i++) {
		ret = min(ret,dp(now+i) + 1);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	memset(cache, -1, sizeof(cache));
	int ans = dp(0);
	if (ans == INF) cout << -1 << "\n";
	else cout << ans << "\n";
	
	return 0;
}