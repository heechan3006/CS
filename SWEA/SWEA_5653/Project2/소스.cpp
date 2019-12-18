#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define MAXN 700
using namespace std;
bool visited[MAXN][MAXN];
struct node {
	int x;
	int y;
	int active_time;
};

int N, M, K;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	freopen("input.txt", "r", stdin);
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		bool check[11] = { false, };
		v.clear();
		memset(visited, false, sizeof(visited));
		queue<node> q[11];
		cin >> N >> M >> K;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int tmp;
				cin >> tmp;
				if (tmp == 0) continue;
				q[tmp].push({ i + 300,j + 300,tmp * 2 });
				visited[i + 300][j + 300] = true;
				if (!check[tmp]) {
					check[tmp] = true;
					v.push_back(tmp);
				}
			}
		}
		sort(v.begin(), v.end());
		while (K--) {
			for (int i = v.size()-1; i >= 0; i--) {
				int q_size = q[v[i]].size();
				while (q_size--) {
					int x = q[v[i]].front().x;
					int y = q[v[i]].front().y;
					int time = q[v[i]].front().active_time;
					q[v[i]].pop();
					time--;

					if (time == v[i] - 1) {
						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (visited[nx][ny]) continue;
							visited[nx][ny] = true;
							q[v[i]].push({ nx,ny,v[i] * 2 });
						}
					}
					if (time > 0) {
						q[v[i]].push({ x,y,time });
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <v.size(); i++) {
			ans += q[v[i]].size();
		}
		cout << "#"<<test_case<<" "<<ans << "\n";
	}
	
	return 0;
}
