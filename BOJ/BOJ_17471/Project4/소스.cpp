#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 10
#define INF 987654321
using namespace std;

int N;
vector<int> v[MAXN];
bool used[MAXN];
int info[MAXN];
int ans = INF;
bool check(bool mode) {
	
	queue<int> q;
	bool visited[MAXN] = { false, };
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (used[i] == mode) {
			if (q.empty()) {
				q.push(i);
				visited[i] = true;
			}
			cnt++;
		}
	}
	cnt--;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			if (!visited[v[now][i]] && used[v[now][i]] == mode) {
				visited[v[now][i]] = true;
				q.push(v[now][i]);
				cnt--;
			}
		}
	}
	return cnt == 0;
}
void dfs(int now,int left_sum, int right_sum) {
	if (ans == 0) return;
	if (now == N) {
		if (!left_sum || !right_sum) return;
		if (check(true) && check(false)) {
			ans = min(ans, abs(left_sum - right_sum));
		}
		return;
	}
	used[now] = true;
	dfs(now + 1,left_sum+info[now],right_sum);
	used[now] = false;
	dfs(now + 1,left_sum,right_sum+info[now]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> info[i];
	}
	for (int i = 0; i < N; i++) {
		int m;
		cin >> m;
		while (m--) {
			int tmp;
			cin >> tmp;
			tmp--;
			v[i].push_back(tmp);
		}
	}
	dfs(0,0,0);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
	return 0;

}