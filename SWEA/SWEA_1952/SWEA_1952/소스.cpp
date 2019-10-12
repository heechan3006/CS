#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

int cache[15];
int cost[4];
int month[15];
int dp(int now) {
	if (now >= 12) return 0;
	int& ret = cache[now];
	if (ret != -1) return ret;
	ret = INF;
	ret = min(ret, month[now] * cost[0] + dp(now + 1));
	if (month[now]!=0){
		ret = min(ret, cost[1] + dp(now + 1));
		ret = min(ret, cost[2] + dp(now + 3));
	}
	return ret;
}
int main() {
	int t;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int test_case=1 ; test_case<= t; test_case++){
		for (int i = 0; i < 4; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < 12; i++) {
			cin >> month[i];
		}
		memset(cache, -1, sizeof(cache));
		int ans = dp(0);
		ans = min(ans, cost[3]);
		cout << "#"<<test_case<<" "<< ans << "\n";
	}
	return 0;
}