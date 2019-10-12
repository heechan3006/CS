#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

int N;
int T[20];
int P[20];
int cache[20];
int ans;
int dp(int now) {
	
	if (now == N+1) {
		return 0;
	}
	if (now > N + 1) {
		return -INF;
	}
	int& ret = cache[now];
	if (cache[now] != -1) return ret;
	ret = 0;
	ret += max(dp(now + T[now])+ P[now],dp(now+1));
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
	ans = 0;
	memset(cache, -1, sizeof(cache));
	
	cout << dp(1) << "\n";
	return 0;
}