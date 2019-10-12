#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 10
#define INF 987654321
using namespace std;

int N;
int info[MAXN];
vector<int> v[MAXN];
bool used[MAXN];
int ans = INF;

int compute_min(vector<int> a, vector<int> b) {
	int sum_a = 0;
	int sum_b = 0;
	for (int i = 0; i < a.size(); i++) {
		sum_a += info[a[i]];
	}
	for (int i = 0; i < b.size(); i++) {
		sum_b += info[b[i]];
	}
	return abs(sum_a - sum_b);
}

bool is_possible(vector<int> a, bool mode) {
	if (a.size() == 1) return true;
	vector<bool> visited(N);
	queue<int> q;
	q.push(a[0]);
	visited[a[0]] = true;
	int cnt = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			if (!visited[v[now][i]] && used[v[now][i]] == mode) {
				visited[v[now][i]] = true;
				q.push(v[now][i]);
				cnt++;
			}
		}
	}
	if (cnt == a.size()) return true;
	return false;
}
void dfs(int now) {
	if (ans == 0) return;
	if (now == N+1) {
		vector<int> A, B;
		for (int i = 0; i < N; i++) {
			if (used[i]) A.push_back(i);
			else B.push_back(i);
		}
		if (A.size() == 0 || B.size() == 0) return;
		if (is_possible(A,true) && is_possible(B,false)) {
			int sum = compute_min(A, B);
			if (ans > sum) ans = sum;
		}
		return;
	}
	used[now] = true;
	dfs(now + 1);
	used[now] = false;
	dfs(now + 1);
	
	
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
	dfs(0);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}