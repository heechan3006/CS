#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int MAXN = 64;
char map[MAXN][MAXN];
int N;
int check(int x1, int y1, int x2, int y2) {
	int sum = 0;
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			sum += map[i][j]-'0';
		}
	}
	if (sum == 0) return 0;
	if (sum == (x2 - x1 + 1) * (x2 - x1 + 1)) return 1;
	return -1;
	
}
void go(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) return;
	// 나누기 가능하면 리턴
	int flag = check(x1, y1, x2, y2);
	if (flag != -1) {
		printf("%d", flag);
		return;
	}
	printf("(");
	int midx = (x1 + x2) / 2;
	int midy = (y1 + y2) / 2;
	go(x1, y1, midx, midy);
	go(x1, midy+1, midx, y2);
	go(midx+1, y1, x2, midy);
	go(midx+1, midy+1, x2, y2);
	printf(")");
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
	go(0, 0, N - 1, N - 1);
	return 0;
}