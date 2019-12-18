#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 10
#define INF 987654321
using namespace std;

int info[MAXN];
vector<int> A, B;
int N;
vector<int> adj[MAXN];
int ans = INF;
bool check(vector<int> v) {
	if (v.size() == 1) return true;
	vector<int> visited(N, false);
	vector<int> num(N, false);
	for (int i = 0; i < v.size(); i++) {
		visited[v[i]] = true;
	}
	int cnt = v.size() - 1;
	queue<int> q;
	num[v[0]] = true;
	q.push(v[0]);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int k = 0; k < adj[now].size(); k++) {
			int next = adj[now][k];
			if (visited[next] && !num[next]) {
				num[next] = true;
				cnt--;
				q.push(next);
			}
		}
	}
	return cnt == 0;
}
void dfs(int now, int sum_a,  int sum_b) {
	if (ans == 0) return;
	if (now == N) {
		if (A.size() == 0 || B.size() == 0) return;
		if (check(A) && check(B)) {
			if (ans > abs(sum_a - sum_b)) ans = abs(sum_a - sum_b);
		}
		return;
	}
	A.push_back(now);
	dfs(now + 1,sum_a+info[now],sum_b);
	A.pop_back();
	B.push_back(now);
	dfs(now + 1, sum_a, sum_b + info[now]);
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
		int M;
		cin >> M;
		while (M--) {
			int tmp;
			cin >> tmp;
			adj[i].push_back(tmp - 1);
		}
	}
	dfs(0,0,0);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}