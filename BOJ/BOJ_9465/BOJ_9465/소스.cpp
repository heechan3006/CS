#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 100000

using namespace std;

int D[MAXN][3];
int map[2][MAXN];
int N;
int dp(int now, int idx) {
	if (now == N) return 0;
	int& ret = D[now][idx];
	if (ret != -1) return ret;
	ret = dp(now + 1, 0);
	if (idx != 1) ret = max(ret, dp(now + 1, 1) + map[0][now]);
	if (idx != 2) ret = max(ret, dp(now + 1, 2) + map[1][now]);
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> N;
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		memset(D, -1, sizeof(D));
		cout << dp(0, 0) << "\n";
		
	}
	return 0;
}
