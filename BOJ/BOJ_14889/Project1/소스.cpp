#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

int A[20][20];
int N;
bool used[20];
int ans;
void dfs(int now, int cnt) {
	if (cnt == N / 2) {
		vector<int> start;
		vector<int> link;
		for (int i = 0; i < N; i++) {
			if (used[i]) {
				start.push_back(i);
			}
			else {
				link.push_back(i);
			}
		}
		int start_sum = 0;
		int link_sum = 0;
		for (int i = 0; i < start.size(); i++) {
			for (int j = i+1; j < start.size(); j++) {
				
				start_sum += A[start[i]][start[j]] + A[start[j]][start[i]];
			}
		}
		for (int i = 0; i < link.size(); i++) {
			for (int j = i+1; j < link.size(); j++) {
				
				link_sum += A[link[i]][link[j]]+A[link[j]][link[i]];
			}
		}
		if (ans > abs(start_sum - link_sum)) ans = abs(start_sum - link_sum);
		return;
	}
	for (int i = now; i < N; i++) {
		if (!used[i]) {
			used[i] = true;
			dfs(i + 1, cnt + 1);
			used[i] = false;
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	ans = INF;
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}
