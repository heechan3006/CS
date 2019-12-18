#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 10
#define INF 987654321
using namespace std;

vector<int> adj[MAXN];
vector<int> A;
vector<int> B;
int info[MAXN];
int N;
int ans = INF;
bool check(vector<int> v) {
	queue<int> q;
	vector<bool> used(N, false);
	vector<bool> visited(N, false);
	for (int i = 0; i < v.size(); i++) {
		if (q.empty()) {
			q.push(v[i]);
			visited[v[i]] = true;
		}
		used[v[i]] = true;
	}
	int cnt = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			if (used[adj[now][i]] && !visited[adj[now][i]]) {
				visited[adj[now][i]] = true;
				q.push(adj[now][i]);
				cnt++;
			}
		}
	}
	return cnt == v.size();
}
void dfs(int now, int left, int right) {
	if (ans == 0) return;
	if (now == N) {
		if (!A.size() || !B.size()) return;
		if (check(A) && check(B)) {
			if (ans > abs(left - right)) ans = abs(left - right);
		}
		return;
	}
	A.push_back(now);
	dfs(now + 1, left + info[now], right);
	A.pop_back();
	B.push_back(now);
	dfs(now + 1, left, right + info[now]);
	B.pop_back();
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
			adj[i].push_back(tmp);
		}
	}
	dfs(0, 0, 0);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}

