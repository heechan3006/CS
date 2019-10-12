#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N, M;
char map[101][101];
bool check[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
struct node {
	int x;
	int y;
	int d;

};
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	vector<node> v;
	for (int i = 2; i < N; i++) {
		for (int j = 2; j < M; j++) {
			if (map[i][j] == '*') {
				int order = 0;
				while (1){
					int x = i;
					int y = j;
					order++;
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int nx = x+ order*dx[k];
						int ny = y+ order*dy[k];
						if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
						if (map[nx][ny] == '*') {
							cnt++;
						}
					}
					if (cnt == 4) {
						v.push_back({ i,j,order });
						for (int k = 0; k < 4; k++) {
							int nx = x + order * dx[k];
							int ny = y + order * dy[k];
							check[nx][ny] = true;
						}
						check[x][y] = true;
					}
					else {
						break;
					}
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == '*' && !check[i][j]) {
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d %d %d\n", v[i].x, v[i].y, v[i].d);
	}
	return 0;
}