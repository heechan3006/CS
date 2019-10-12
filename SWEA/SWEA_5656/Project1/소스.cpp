#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, W, H;
int map[15][12];
int copy_map[15][12];
vector<int> v;
int ans=INF;
void bomb(int x, int y, int power) {
	copy_map[x][y] = 0;
	
	for (int i = y + 1; i < min(y + power,W); i++) {
		if (copy_map[x][i] == 1) copy_map[x][i] = 0;
		else if (copy_map[x][i] > 1) bomb(x, i, copy_map[x][i]);
	}
	for (int i = y - 1; i >= max(0, y - power + 1); i--) {
		if (copy_map[x][i] == 1) copy_map[x][i] = 0;
		else if (copy_map[x][i] > 1) bomb(x, i, copy_map[x][i]);
	}
	for (int i = x - 1; i >= max(0, x - power + 1); i--) {
		if (copy_map[i][y] == 1) copy_map[i][y] = 0;
		else if (copy_map[i][y] > 1) bomb(i, y, copy_map[i][y]);
	}
	for (int i = x + 1; i < min(x + power,H); i++) {
		if (copy_map[i][y] == 1) copy_map[i][y] = 0;
		else if (copy_map[i][y] > 1) bomb(i, y, copy_map[i][y]);
	}
}
void go(int y) {
	// Æø¹ß
	for (int i = 0; i < H; i++) {
		if (copy_map[i][y]) {
			bomb(i, y, copy_map[i][y]);
			break;
		}
	}
	// Á¤·Ä
	for (int j = 0; j < W ; j++){
		for (int i = H - 1; i >= 0; i--) {
			for (int k = i - 1; k >= 0; k--) {
				if (copy_map[i][j] != 0) break;
				if (copy_map[k][j] != 0) {
					copy_map[i][j] = copy_map[k][j];
					copy_map[k][j] = 0;
					break;
				}
			}
		}
	}
}
void dfs(int now,int cnt) {
	if (ans == 0) return;
	if (cnt == N) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				copy_map[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < v.size(); i++) {
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
		dfs(i,cnt+1);
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		cin >> N >> W >> H;
		ans = INF;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
				
			}
		}
		dfs(0,0);
		cout << "#"<<test_case<<" "<<ans << "\n";
	}
	return 0;
}