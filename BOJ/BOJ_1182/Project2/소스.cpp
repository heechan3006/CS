#include <iostream>
#define MAXN 20

using namespace std;

int N, S;

int map[MAXN];
int ans = 0;
void dfs(int now,int cnt, int sum) {
	if (now == N) {
		if (cnt == 0) return;
		if (sum == S) {
			ans++;
		}
		return;
	}
	
	dfs(now + 1, cnt+1,sum+map[now]);
	dfs(now + 1, cnt,sum);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	dfs(0, 0, 0);
	cout << ans << "\n";
	return 0;
}
