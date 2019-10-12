#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define INF 987654321
using namespace std;

int map[4][4];
int correct[8];
int res[8][3];
int tmp[8][3];
int tmp_map[5];
int num = 0;
int ans = 9;
// 현재 index, 가로 shift 횟수, 세로 shift 횟수, 움직인 횟수
void shift(int x, int y, int t) {
	
	// 가로
	int i;
	if (x < 4){;
		for (int i = 0; i < 4; i++) tmp_map[(i + t) % 4] = map[x][i];
		for (int i = 0; i < 4; i++) map[x][i] = tmp_map[i];
		
	}
	// 세로
	else {
		for (int i = 0; i < 4; i++) tmp_map[(i + t) % t] = map[i][x % 4];
		for (int i = 0; i < 4; i++) map[i][x % 4] = tmp_map[i];
		
	}
	
}
int check() {
	int sum = 0;
	for (int i = 0; i < 16; i++) {
		if (map[i / 4][i % 4] == i + 1) sum++;
	}
	return sum;
}
void dfs(int cnt) {
	if (cnt >= ans || cnt == 8) return;
	int tmp_sum = check();
	if (tmp_sum == 16) {
		memcpy(res, tmp, sizeof(res));
		ans = cnt;
		return;
	}
	if (cnt + 2 >= ans && tmp_sum < 12) return;
	if (cnt + 3 >= ans && tmp_sum < 9) return;
	if (cnt + 4 >= ans && tmp_sum < 6) return;
	/*
	if (correct[cnt - 1] <= tmp_sum) {
		correct[cnt] = min(correct[cnt], tmp_sum);
	}
	else {
		return;
	}*/

	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			if (i < 4) tmp[cnt][0] = 1, tmp[cnt][1] = i + 1, tmp[cnt][2] = j + 1;
			else tmp[cnt][0] = 2, tmp[cnt][1] = (i%4) + 1, tmp[cnt][2] = j + 1;
			shift(i, j,j+1);
			
			dfs(cnt + 1);
			shift(i, j, 4-(j+1));
		}
			
	
	}
}
int main() {
	
	for (int i = 0; i < 16; i++) {
		scanf("%d", &map[i / 4][i % 4]);	
	}
	
	dfs(0);
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++) {
		printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
	}
	return 0;
}