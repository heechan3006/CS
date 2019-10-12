#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 10
#define INF 987654321
using namespace std;

int info[MAXN];
int N;
int used[MAXN];
vector<int> v[MAXN];
int ans = INF;
bool bfs(int mode) {
	queue<int> q;
	vector<bool> visited(N,false);
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
		if (cnt == 0) return true;
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (!visited[next] && used[next] == mode) {
				visited[next] = true;
				cnt--;
				q.push(next);
			}
		}
	}
	return false;
}
void dfs(int now,int left ,int right) {
	if (ans == 0) return;
	if (now == N) {
		if (left == 0 || right == 0) return;
		if (bfs(1) && bfs(2)) {
			if (ans > abs(left - right)) ans = abs(left - right);
		}
		return;
	}
	used[now] = 1;
	dfs(now + 1,left+info[now],right);
	used[now] = 2;
	dfs(now + 1,left,right+info[now]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> info[i];
	}
	for (int i = 0; i < N; i++) {
		int M;
		cin >> M;
		for (int j = 0; j < M; j++) {
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