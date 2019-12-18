#include <iostream>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;

int N, W, H;

int map[15][12];
int copy_map[15][12];
vector<int> v;
int ans ;
void bomb(int x, int y) {
	
	if (x < 0 || y < 0 || x >= H || y >= W) return;
	int tmp = copy_map[x][y];
	copy_map[x][y] = 0;
	for (int i = 1; i < tmp; i++) {
		bomb(x + i, y);
		bomb(x - i, y);
		bomb(x, y + i);
		bomb(x, y - i);
	}
}
void go(int y) {
	for (int i = 0; i < H; i++) {
		if (copy_map[i][y]) {
			bomb(i, y);
			break;
		}
	}
	for (int j = 0; j < W; j++) {
		for (int i = H - 1; i >= 0; i--) {
			if (!copy_map[i][j]){
				int k;
				for (k = i - 1; k >= 0; k--) {
					if (copy_map[k][j]) {
						copy_map[i][j] = copy_map[k][j];
						copy_map[k][j] = 0;
						break;
					}
				}
				if (k < 0) break;
			}
		}
	}
}
void dfs(int cnt) {
	if (ans == 0) return;
	if (cnt == N) {
		memcpy(copy_map, map, sizeof(copy_map));
		for (int i = 0; i < N; i++) {
			go(v[i]);
		}
		int sum = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (copy_map[i][j]) sum++;
			}
		}
		if (ans > sum) ans = sum;
		return;
	}
	for (int i = 0; i < W; i++) {
		v.push_back(i);
		dfs(cnt + 1);
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		ans = INF;
		cin >> N >> W >> H;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}
		dfs(0);
		cout << "#"<<test_case<<" "<<ans << "\n";
	}
	
	return 0;
}