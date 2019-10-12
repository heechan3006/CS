#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 501
#define INF 987654321
using namespace std;


int D[MAXN][MAXN];
int partial[MAXN];
int K;
int dp(int s, int e) {
	if (s == e) return 0;
	int& ret = D[s][e];
	if (ret != -1) return ret;
	ret = INF;
	int part = partial[e] - partial[s - 1];
	for (int i = s; i < e; i++) {
		ret = min(ret, part+dp(s, i) + dp(i + 1, e));
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> K;
		memset(D, -1, sizeof(D));
		memset(partial, 0, sizeof(partial));
		for (int i = 1; i <= K; i++) {
			int tmp;
			cin >> tmp;
			partial[i] = partial[i - 1] + tmp;
		}
		
		cout << dp(1, K) <<"\n";
	}
}
