#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 15

using namespace std;

int map[MAXN][MAXN];
int copy_map[MAXN][MAXN];
bool archer[MAXN];
int N, M, D;
int total_cnt = 0;
int ans = 0;
struct node {
	int x;
	int y;
	int d;
	bool operator < (const node& a) const {
		if (d <= a.d) {
			if (d == a.d) {
				if (y < a.y) return true;
				return false;
			}
			return true;
		}
		return false;
	}
};
int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
int go() {
	int tmp_cnt = total_cnt;

	int sum = 0;
	while (tmp_cnt > 0) {
		vector<pair<int, int> > remove;
		for (int k = 0; k < M; k++) {
			if (!archer[k]) continue;
			vector<node> v;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (copy_map[i][j]) {
						int d = dist(i, j, N, k);
						if (d <= D) v.push_back({ i,j,d });
					}
				}
			}
			if (v.size() == 0) continue;
			sort(v.begin(), v.end());
			remove.push_back({ v[0].x,v[0].y });
		}
		for (int i = 0; i < remove.size(); i++) {
			if (copy_map[remove[i].first][remove[i].second]) {
				tmp_cnt--;
				sum++;
			}
			copy_map[remove[i].first][remove[i].second] = 0;
		}
		
		for (int j = 0; j < M; j++) {
			for (int i = N - 1; i >= 1; i--) {
				if (i == N - 1 && copy_map[i][j]) tmp_cnt--;
				copy_map[i][j] = copy_map[i - 1][j];
			}
			copy_map[0][j] = 0;
		}
		
	}
	return sum;
}
void dfs(int now, int cnt) {
	if (cnt == 3) {
		memcpy(copy_map, map, sizeof(map));
		int sum = go();
		if (ans < sum) ans = sum;
		return;
	}
	for (int i = now; i < M; i++) {
		if (archer[i]) continue;
		archer[i] = true;
		dfs(i+1, cnt + 1);
		archer[i] = false;
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j]) total_cnt++;
		}
	}
	dfs(0, 0);
	cout << ans << "\n";
	return 0;
}