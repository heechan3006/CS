#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int map[10][10];
bool visited[10][10];
int used[6] = { 0,5,5,5,5,5 };
int cnt = 0;
int ans;
bool is_possible(int x, int y, int size) {
	if (x + size > 10 || y + size > 10) return false;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			
			if (map[i][j] == 0 || visited[i][j]) return false;
		}
	}
	return true;
}
void check_visit(int x, int y, int size, bool flag) {

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			
			if (flag) visited[i][j] = true;
			else{
				visited[i][j] = false;
			}
		}
	}
}
void dfs(int x,int y, int sum) {
	if (sum > cnt) return;
	if (sum == cnt) {
		int res = 0;
		for (int i = 1; i <= 5; i++) {
			res += 5 - used[i];
		}
		if (ans > res) ans = res;
		return;
	}
	bool possible = false;
	for (int i = x; i < 10; i++) {
		for (int j = y; j < 10; j++) {
			if (map[i][j] && !visited[i][j]) {
				possible = true;
				for (int k = 5; k >= 1; k--) {
					if (used[k] == 0) continue;
					if (used[k] == 0 && k == 1) return;
					if (!is_possible(i, j, k)) {
						continue;
					}
					check_visit(i, j, k, true);
					used[k]--;
					dfs(i, j, sum + k * k);
					
					used[k]++;
					check_visit(i, j, k, false);
				}
				
			}
			if (possible) break;
		}
		if (possible) break;
		y = 0;
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j]) cnt++;
		}
	}
	ans = 100;
	dfs(0,0,0);
	if (ans == 100) printf("-1\n");
	else{
		printf("%d", ans);
	}
	return 0;
}