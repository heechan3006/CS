#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#define MAXN 10

using namespace std;

int arr[MAXN][MAXN];
int nut[MAXN][MAXN];
deque<int> map[MAXN][MAXN];

int N, M, K;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for(int j=0;j<N;j++){
			cin >> nut[i][j];
			arr[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		map[x-1][y-1].push_back(z);
	}
	while (K--) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!map[i][j].size()) continue;
				int k;
				
				for (k = 0; k < map[i][j].size(); k++) {
					if (arr[i][j] - map[i][j][k] >= 0) {
						arr[i][j] -= map[i][j][k];
						map[i][j][k]++;
					}
					else {
						break;
					}
				}
				while (k < map[i][j].size()) {
					arr[i][j] += map[i][j].back() / 2;
					map[i][j].pop_back();
				}
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j].size()) {
					for (int k = 0; k < map[i][j].size(); k++) {
						if (map[i][j][k] % 5 == 0) {
							for (int kk = 0; kk < 8; kk++) {
								int nx = i + dx[kk];
								int ny = j + dy[kk];
								if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
								map[nx][ny].push_front(1);
							}
						}
					}
				}
				arr[i][j] += nut[i][j];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += (int)map[i][j].size();
		}
	}
	cout << ans << "\n";
	return 0;
}