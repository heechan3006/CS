#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

bool visited[4][12];

int map[15][12];
int copy_map[15][12];
int N, W, H;
int ans;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


void bomb(int x, int y) {
	int p = copy_map[x][y];
	copy_map[x][y] = 0;
	for (int k =0; k < 4; k++){
		for (int i = 1; i < p; i++) {
			int nx = x + dx[k] * i;
			int ny = y + dy[k] * i;
			if (0 <= nx && nx < H && 0 <= ny && ny < W && copy_map[nx][ny]) {
				bomb(nx, ny);
			}
		}
	}
}
void move() {
	for (int j = 0; j < W; j++) {
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
int simulate(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < H; j++){
			if (copy_map[j][v[i]]){
				bomb(j,v[i]);
				move();
				break;
			}
			
		}
	}
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (copy_map[i][j]) cnt++;
		}
	}
	return cnt;
}
void dfs(int now, int cnt) {
	if (ans == 0) {
		return;
	}
	if (cnt == N) {
		vector<int> v;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < W; k++) {
				if (visited[j][k]) {
					v.push_back(k);
				}
			}
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				copy_map[i][j] = map[i][j];
			}
		}
		int sum = simulate(v);
		if (ans > sum) ans = sum;
		return;
		
	}
	
	for (int i = 0; i < W; i++) {
		if (!visited[cnt][i]){
			visited[cnt][i] = true;
			dfs(i, cnt + 1);
			visited[cnt][i] = false;
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case=1; test_case<=t; test_case++){
		scanf("%d%d%d", &N, &W, &H);

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &map[i][j]);
			
			}
		}
		memset(visited, false, sizeof(visited));
		ans = INF;
		dfs(0, 0);
		printf("#%d %d\n", test_case,ans);
	}
	return 0;
}
