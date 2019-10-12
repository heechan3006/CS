#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
const int INF = 987654321;
using namespace std;
int N;
int info[10];
vector<int> v[11];
vector<int> A;
vector<int> B;
int used[10];
int answer = INF;
bool check[10];
bool go(int now) {
	check[now] = true;
	for (int i = 0; i < v[now].size(); i++) {
		if (!check[i]) {
			return go(v[i][i]);
		}
	}
}
bool is_connected(vector<int> a,vector<int> b) {
	memset(check, false, sizeof(check));
	for (int i = 0; i < b.size(); i++) {
		check[i] = true;
	}
	if (a.size() > 1) {
		for (int i = 0; i < a.size(); i++) {
			if (!go(a[i])) return false;
		}
	}
	return true;
}
void dfs(int now, int cnt,int limit) {
	if (limit == cnt) {
		
		for (int i = 0; i < N; i++) {
			if (used[i]) A.push_back(i);
			else B.push_back(i);
		}
		if (is_connected(A,B)) {
			int sum_a = 0;
			int sum_b = 0;
			for (int i = 0; i < A.size(); i++) {
				sum_a += info[A[i]];
			}
			for (int i = 0; i < B.size(); i++) {
				sum_b == info[B[i]];
			}
			if (answer > abs(sum_a - sum_b)) answer = abs(sum_a - sum_b);
		}
		return;
	}
	for (int i = now; i < N; i++) {
		if (used[i]) continue;
		used[i] = true;
		dfs(now + 1, cnt + 1, limit);
		used[i] = false;
	}
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
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			x--;
			v[i].push_back(x);
		}
	}
	for (int i = 1; i < N / 2; i++) {
		memset(used, false, sizeof(used));
		dfs(0,0,i);
	}
	
}