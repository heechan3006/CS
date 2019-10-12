#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 98765432
using namespace std;

int map[16][16];
bool visited[16];
int N;
int ans;
void dfs(int now, int cnt) {
	visited[now] = true;
	
	if (cnt == N / 2) {
		int sum_A = 0;
		int sum_B = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (visited[i] && visited[j]) {
					sum_A += map[i][j];
				}
				else if (!visited[i] && !visited[j]) {
					sum_B += map[i][j];
				}
			}
		}
		int diff = abs(sum_A - sum_B);
		if (ans > diff) ans = diff;
	}
	else{
		for (int i = now+1; i<N; i++){
			dfs(i, cnt + 1);
		}
	}
	visited[now] = false;
	
	
}
int main() {
	ios::sync_with_stdio(false);
	
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		memset(visited, false, sizeof(visited));
		cin >> N;
	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		ans = INF;
	
		dfs(0,1);
		cout << "#"<<test_case<<" "<<ans << "\n";
	}
	return 0;
	
}