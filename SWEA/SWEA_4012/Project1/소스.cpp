#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 16
#define INF 987654321
using namespace std;

int map[MAXN][MAXN];
int N;
vector<int> A, B;
int ans;
void dfs(int now) {
	if (ans == 0) return;
	if (now == N) {
		if (A.size() != B.size()) return;
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < A.size(); i++) {
			for (int j = i+1; j < A.size(); j++) {
				if (i == j) continue;
				sum1 += map[A[i]][A[j]];
				sum1 += map[A[j]][A[i]];
				sum2 += map[B[i]][B[j]];
				sum2 += map[B[j]][B[i]];
			}
		}
		if (ans > abs(sum1 - sum2)) ans = abs(sum1 - sum2);
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
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		ans = INF;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		dfs(0);
		cout << "#"<<test_case<<" "<<ans << "\n";
	}
	
	return 0;
}
