#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAXN 1001
using namespace std;


int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int M, K;
int main() {
	scanf("%d%d", &M, &K);
	int dir = 0;
	int x = M;
	int y = 0;
	while (K--) {
		string s;
		int num;
		cin >> s >> num;
		if (s == "MOVE") {
			int nx = x;
			int ny = y;
			bool flag = false;
			for (int i = 0;  i< num; i++){
				nx += dx[dir];
				ny += dy[dir];
				if (nx < 0 || ny < 0 || nx > M || ny >M) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				x = nx;
				y = ny;
			}
			else {
				printf("-1");
				return 0;
			}
		}
		else if (s == "TURN") {
			if (num == 0) {
				dir--;
				if (dir < 0) dir = 3;
			}
			else {
				dir++;
				if (dir > 3) dir = 0;
			}
		}
	}
	printf("%d %d", y,M-x);
}
