#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 100
using namespace std;

struct node {
	int num;
	int max_num;
	int d;
};
struct info {
	int x;
	int y;
	int num;
	int d;
};
node map[MAXN][MAXN];

int N, M, K;
int t;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		memset(map, 0, sizeof(map));
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			int x, y, num, d;
			cin >> x >> y >> num >> d;
			d--;
			map[x][y] = { num,num,d };
		}
		while (M--) {
			if (K == 0) break;
			queue<info> q;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j].num) {
						q.push({ i,j,map[i][j].num,map[i][j].d });
						map[i][j] = { 0,0 };
					}
				}
			}

			while (!q.empty()) {
				int x = q.front().x;
				int y = q.front().y;
				int num = q.front().num;
				int d = q.front().d;
				q.pop();
				x += dx[d];
				y += dy[d];
				if (x == 0 || y == 0 || x == N - 1 || y == N - 1) {
					d = (5 - d) % 4;
					num /= 2;
				}
				if (num == 0) {
					K--;
					continue;
				}
				if (map[x][y].num) {
					if (map[x][y].max_num < num) {
						map[x][y] = { num + map[x][y].num,num,d };

					}
					else {
						map[x][y].num += num;
					}
					K--;
				}
				else {
					map[x][y] = { num,num,d };
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans += map[i][j].num;
			}
		}
		cout << "#"<<test_case<<" "<< ans << "\n";
	}
	
	
	return 0;
}