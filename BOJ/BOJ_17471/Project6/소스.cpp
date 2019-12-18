#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 10
#define INF 987654321
using namespace std;

int N;
int info[MAXN];
vector<int> adj[MAXN];
vector<int> A, B;
int ans = INF;
bool check(vector<int> v) {
	vector<bool> used(N, false);
	vector<bool> num_possible(N, false);
	queue<int> q;
	int cnt = v.size()-1;
	for (int i = 0; i < v.size(); i++) {
		num_possible[v[i]] = true;
	}
	q.push(v[0]);
	used[v[0]] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
			if (num_possible[next] && !used[next]) {
				used[next] = true;
				cnt--;
				q.push(next);
			}
		}
	}
	return cnt == 0;
}
void dfs(int now) {
	if (ans == 0) return;
	if (now == N) {
		if (!A.size() || !B.size()) return;
		if (check(A) && check(B)) {
			int sum1 = 0;
			int sum2 = 0;
			for (int i = 0; i < A.size(); i++) {
				sum1 += info[A[i]];
			}
			for (int i = 0; i < B.size(); i++) {
				sum2 += info[B[i]];
			}
			if (ans > abs(sum1 - sum2)) ans = abs(sum1 - sum2);
		}
		return;
	}
	A.push_back(now);
	dfs(now + 1);
	A.pop_back();
	B.push_back(now);
	dfs(now + 1);
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
	dfs(0);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}