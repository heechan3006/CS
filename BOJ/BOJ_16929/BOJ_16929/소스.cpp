#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>


using namespace std;

char Map[55][55];
bool visit[55][55] = { false, };
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int N = 0, M = 0;
int sx = 0, sy = 0;
bool stop = false;
void DFS(int r, int c, int cnt) {
	if (stop) return;
	visit[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int y = r + dy[i];
		int x = c + dx[i];
		if (y < 0 || x < 0 || y >= N || x >= M || Map[r][c] != Map[y][x]) continue;
		
		if (!visit[y][x]) {
			visit[y][x] = true;
			DFS(y, x, cnt + 1);
		}
		else {
			if (sy == y && sx == x && cnt >= 4) {
				stop = true;
				return;
			}
		}
	}
}
int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> Map[i][j];

	for (int i = 0; i < N && !stop; i++)
	{
		for (int j = 0; j < M && !stop; j++)
		{
			memset(visit, false, sizeof(visit));

			sy = i; sx = j;

			DFS(i, j, 1);
		}
	}

	if (stop) printf("Yes\n");
	else printf("No\n");

	return 0;
}