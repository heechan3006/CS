#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[101][101];
int N, K, L;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int Time[10000];
struct info {
	int x;
	int y;
	int dir;
};
int main() {
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		//»ç°ú
		map[x][y] = 2;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		int now;
		char dir;
		scanf("%d %1c", &now, &dir);
		if (dir == 'L') {
			Time[now] = -1;
		}
		else if (dir == 'D') {
			Time[now] = 1;
		}
	}
	deque<info> q;
	q.push_back({ 1,1,0 });
	map[1][1] = 1;
	int time = 0;
	bool flag = false;
	while (!q.empty()&&!flag) {
		
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
			
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx <= 0 || ny <= 0 || nx > N || ny > N) {
			flag = true;
			break;
		}
			
		//»ç°úÀÖ´Â°æ¿ì ²¿¸® ±×´ë·Î ³ÀµÒ.
		if (map[nx][ny] == 2) {
			q.push_front({ nx,ny,dir });
			map[nx][ny] = 1;
		}
		// ¾ø´Â °æ¿ì ²¿¸® ¾ø¾Ú.
		else if (map[nx][ny] == 0) {
			q.push_front({ nx,ny,dir });
			map[nx][ny] = 1;
			int last_x = q.back().x;
			int last_y = q.back().y;
			map[last_x][last_y] = 0;
			q.pop_back();
		}
		//ÀÚ±âÀÚ½ÅÀÇ ¸ö¿¡ ºÎµúÈ÷´Â °æ¿ì
		else if (map[nx][ny] == 1) {
			flag = true;
			break;
		}
		
		time++;
		if (Time[time] != 0) {
			int x = q.front().x;
			int y = q.front().y;
			int dir = q.front().dir;
			if (Time[time] == 1) {
				dir++;
				if (dir > 3) dir = 0;
				
			}
			else if (Time[time] == -1) {
				dir--;
				if (dir < 0) dir = 3;
			}
			q.pop_front();
			q.push_front({ x,y,dir });
		}
	}
	printf("%d\n", time+1);
	return 0;
}