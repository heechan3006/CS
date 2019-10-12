#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#define MAXN 102
using namespace std;

int A,B,N, M;
int map[MAXN][MAXN];
int dy[] = {0,0,-1,0,1 };
int dx[] = {0,1,0,-1,0 };
struct Node {
	int x;
	int y;
	int dir;
};
int turn(int dir, int flag) {
	//왼쪽
	if (flag == 1) {
		return (dir == 1) ? 4 : dir - 1;
	}
	//오른쪽
	else {
		return (dir == 4) ? 1 : dir + 1;
	}
}
int main() {
	// A 세로 B 가로
	cin >> A >> B;
	cin >> N >> M;
	vector<Node> robot(N+1);
	char tmp_dir;
	for (int i = 1; i <= N; i++) {
		cin >> robot[i].x >> robot[i].y >> tmp_dir;
		if (tmp_dir == 'N') robot[i].dir = 4;
		else if (tmp_dir == 'E') robot[i].dir = 1;
		else if (tmp_dir == 'S') robot[i].dir = 2;
		else robot[i].dir = 3;
		
		map[robot[i].x][robot[i].y] = i;
	}
	while (M--){
		int x, count;
		char c;
		cin >> x  >> c >> count;
		if (c == 'F') {
			for (int i = 0; i < count; i++) {
				int nx = robot[x].x + dx[robot[x].dir];
				int ny = robot[x].y + dy[robot[x].dir];
				if (nx < 1 || nx > A || ny < 1 || ny > B) {
					printf("Robot %d crashes into the wall\n", x);
					return 0;
				}
				else if (map[nx][ny] != 0) {
					printf("Robot %d crashes into robot %d\n", x, map[nx][ny]);
					return 0;
				}
				map[robot[x].x][robot[x].y] = 0;
				robot[x].x = nx;
				robot[x].y = ny;
				map[nx][ny] = x;
			}
		}
		else {
			if (count % 4 == 0) continue;
			count %= 4;
			while (count--) {
				if (c == 'L') {
					robot[x].dir = turn(robot[x].dir, 1);
				}
				else {
					robot[x].dir = turn(robot[x].dir, 0);
				}
			}
		}
	}
		
	printf("OK\n");
}
