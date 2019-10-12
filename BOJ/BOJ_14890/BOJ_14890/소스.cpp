#include <iostream>
#include <math.h>
#define MAXN 100
using namespace std;

int N, L;
int map[MAXN][MAXN], map_2[MAXN][MAXN];

bool check(int map[][MAXN],int x, int y) {
	int height = map[x][y+1];
	for (int i = y+1; i < y + L+1; i++) {
		if (map[x][i] != height) return false;
	}
	return true;
}
int solve(int map[][MAXN]) {
	int load_count = 0;
	for (int i = 0; i < N; i++) {
		int before_load = 1;
		bool flag = false;
		for (int j = 0; j < N-1; j++) {
			if (map[i][j] == map[i][j + 1]) before_load++;
			else if (map[i][j] == map[i][j + 1] + 1) {
				if (check(map,i, j)) {
					before_load = 0;
					j = j + L-1;
				}
				else {
					flag = true;
					break;
				}
			}
			else if (map[i][j] + 1 == map[i][j + 1]) {
				if (before_load >= L) before_load = 1;
				else {
					flag = true;
					break;
				}
			}
			else if (abs(map[i][j] - map[i][j + 1]) >= 2) {
				flag = true;
				break;
			}
		}
		if (!flag) load_count++;
	}
	return load_count;
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			map_2[j][i] = map[i][j];
		}
	}
	int a = solve(map);
	int b = solve(map_2);
	printf("%d\n", a + b);
}