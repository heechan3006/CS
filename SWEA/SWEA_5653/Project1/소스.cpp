#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 700
#define OFFSET 300
using namespace std;
int map[MAXN][MAXN];
struct node {
	int x;
	int y;
	int remain_life;
};
queue<node> q[11];
int N, M, K;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		cin >> N >> M >> K;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int tmp;
				cin >> tmp;
				map[i + OFFSET][j + OFFSET] = tmp;
				if (tmp != 0) {
					q[tmp].push({ i + OFFSET,j + OFFSET,2 * tmp });
				}
			}
		}
		ans = 0;
		while (K--) {
			for (int p = 10; p >= 1; p--) {
				int q_size = q[p].size();
				while (q_size--) {
					int x = q[p].front().x;
					int y = q[p].front().y;
					int remain = q[p].front().remain_life;
					remain--;
					q[p].pop();
					if (remain < 0) continue;
					if (remain < p){
						if (remain>0) q[p].push({ x,y,remain });
						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (map[nx][ny] ==0){
								map[nx][ny] = p;
								q[p].push({ nx,ny,2 * p });
							}
						}

					}
					else {
						q[p].push({ x,y,remain});
					}
				}
			}
		}
		for (int i = 1; i <= 10; i++) {
			while (!q[i].empty()) {
				q[i].pop();
				ans++;
			}
		}
		cout << "#"<<test_case<<" "<<ans << "\n";
	}
	return 0;
}