#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 987654321
#define MAXN 10

using namespace std;

int info[MAXN];
int N;
vector<int> v[MAXN];
bool used[MAXN];
bool visited[MAXN];
int ans = INF;
bool flag ;
int tmp_cnt;
vector<int> A, B;
void is_possible(int now, int target,bool visited[]) {
	if (tmp_cnt == target) {
		flag = true;
		return;
	}

	visited[now] = true;
	for (int i = 0; i < v[now].size(); i++) {
		if (visited[v[now][i]]) continue;
		tmp_cnt++;
		is_possible(v[now][i], target,visited);
	}
}
int compute_min(vector<int> a, vector<int> b) {
	int sum_a = 0;
	int sum_b = 0;
	for (int i = 0; i < a.size(); i++) {
		sum_a += info[a[i]];
	}
	for (int i = 0; i < b.size(); i++) {
		sum_b += info[b[i]];
	}
	return abs(sum_b - sum_a);
}
bool check(vector<int> a,vector<int> b) {
	flag = false;
	tmp_cnt = 1;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < b.size(); i++) {
		visited[b[i]] = true;
	}
	is_possible(a[0], a.size(), visited);
	return flag;
}
void dfs(int now) {
	if (now == N) {
		if (A.size() == 0 || B.size() == 0) return;
		
		if (check(A,B) && check(B,A)) {
			int sum = compute_min(A, B);
			if (ans > sum) ans = sum;
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
		int M;
		cin >> M;
		while (M--){
			int tmp;
			cin >> tmp;
			tmp--;
			v[i].push_back(tmp);
		}
	}
	memset(used, false, sizeof(used));
	dfs(0);
	
	if (ans == INF) cout << "-1\n";
	else {
		cout << ans << "\n";
	}
	return 0;
}