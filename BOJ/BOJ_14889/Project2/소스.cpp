#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 20
using namespace std;
int map[MAXN][MAXN];
int N;
int used[MAXN];
vector<int>A, B;
int ans = 987654321;
void dfs(int now) {
	if (ans == 0) return;
	if (now == N) {
		if (A.size() == B.size()) {
			int sum_a = 0;
			int sum_b = 0;
			for (int i = 0; i < A.size(); i++) {
				for (int j = 0; j < A.size(); j++) {
					if (i == j) continue;
					sum_a += map[A[i]][A[j]];
				}
			}
			for (int i = 0; i < B.size(); i++) {
				for (int j = 0; j < B.size(); j++) {
					if (i == j) continue;
					sum_b += map[B[i]][B[j]];
				}
			}
			if (ans > abs(sum_a - sum_b)) ans = abs(sum_a - sum_b);
		}
		
		return;
	}
	if (A.size() < N / 2) {
		A.push_back(now);
		dfs(now + 1);
		A.pop_back();
	}
	if (B.size() < N / 2) {
		B.push_back(now);
		dfs(now + 1);
		B.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0);
	cout << ans << "\n";
	return 0;
}