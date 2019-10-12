#include <iostream>
#include <cstring>

using namespace std;

bool visited[15];
int map[15];
int res[6];
int K;

void dfs(int idx, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i < K; i++) {
		res[cnt] = map[i];
		dfs(i + 1, cnt + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (1){
		cin >> K;
		if (K == 0) break;
		for (int i = 0; i < K; i++) {
			cin >> map[i];
		}
		dfs(0, 0);
		cout << "\n";
	}
	return 0;
}