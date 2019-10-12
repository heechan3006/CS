#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 987654321
#define MAXN 1500000+1
using namespace std;

int cache[MAXN];
int T[MAXN];
int P[MAXN];
int N;
int ans;
int dp(int now) {
	if (now == N + 1) return 0;
	if (now > N + 1) return -INF;
	int& ret = cache[now];
	if (ret != -1) return ret;
	ret = 0;
	ret += max(dp(now + T[now]) + P[now], dp(now + 1));
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	memset(cache, -1, sizeof(cache));
	ans = 0;
	cout <<dp(1)<<"\n";
	return 0;
}
