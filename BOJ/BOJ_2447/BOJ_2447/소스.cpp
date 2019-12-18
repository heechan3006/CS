#include <iostream>
using namespace std;
const int MAXN = 2187;
int N;
int map[MAXN][MAXN];
void go(int x, int y, int num) {
	if (num == 1) {
		map[x][y] = 1;
		return;
	}
	int div = num / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			go(x + i * div, y + j * div, div);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	go(0, 0, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}