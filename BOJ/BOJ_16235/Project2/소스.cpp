#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
#define MAXN 10

using namespace std;

deque<pair<int,int> > map[MAXN][MAXN];
int info[MAXN][MAXN];
int arr[MAXN][MAXN];
int N, M, K;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
void go() {
	while (K--) {
		int tmp_map[MAXN][MAXN] = { 0, };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j].size() > 0) {
					
					int tmp = 0;
					
					for (int k = 0; k < map[i][j].size(); k++) {
						int remain = min(arr[i][j] / map[i][j][k].first, map[i][j][k].second);
						arr[i][j] -= remain * map[i][j][k].first;
						tmp += (map[i][j][k].first / 2) * (map[i][j][k].second - remain);
						map[i][j][k].first++;
						map[i][j][k].second = remain;
						if (map[i][j][k].first % 5 == 0) {
							tmp_map[i][j] += map[i][j][k].second;
						}
					}
					arr[i][j] += tmp;
					while (!map[i][j].empty() && map[i][j].back().second==0) {
						map[i][j].pop_back();
					}
					
				}
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int cnt = 0;
				
				for (int kk = 0; kk < 8; kk++) {
					int nx = i + dx[kk];
					int ny = j + dy[kk];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					cnt += tmp_map[nx][ny];
				}
				if (cnt > 0) {
					map[i][j].push_front({ 1,cnt });
				}
				arr[i][j] += info[i][j];
			}
		}
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> info[i][j];
			arr[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, old;
		cin >> x >> y >> old;
		x--, y--;
		map[x][y].push_back({ old,1 });
	}
	go();
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < map[i][j].size(); k++) {
				ans += map[i][j][k].second;
			}
			
		}
	}
	cout << ans << "\n";
	return 0;
}