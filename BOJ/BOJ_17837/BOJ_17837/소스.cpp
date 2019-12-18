#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

pair<int, int> coord[10];
vector<pair<int, int> > map[12][12];
int arr[12][12];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int N, K;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int x, y, dir;
		cin >> x >> y >> dir;
		coord[i] = { x - 1,y - 1 };
		map[x - 1][y - 1].push_back({ i,dir - 1 });
	}
	int time = 1;
	while (time <= 1000) {
		for (int i = 0; i < K; i++) {
			int j;
			int x = coord[i].first;
			int y = coord[i].second;
			for (j = 0; j < map[x][y].size(); j++) {
				if (map[x][y][j].first == i) break;
			}
			int dir = map[x][y][j].second;
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
				dir = (5 - dir) % 4;
				map[x][y][j].second = dir;
				nx = x + dx[dir];
				ny = y + dy[dir];
			}
			else {
				if (arr[nx][ny] == 2) {
					dir = (5 - dir) % 4;
					map[x][y][j].second = dir;
					nx = x + dx[dir];
					ny = y + dy[dir];
				}
			}
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
				continue;
			}
			else {
				//Èò»ö
				if (arr[nx][ny] == 0) {
					int num = map[x][y].size() - j;
					for (int jj = j; jj < map[x][y].size(); jj++) {

						map[nx][ny].push_back(map[x][y][jj]);
						
						coord[map[x][y][jj].first] = { nx,ny };
					}
					if (map[nx][ny].size() >= 4) {
						cout << time << "\n";
						return 0;
					}
					while (num--) map[x][y].pop_back();
				}
				//»¡°£»ö
				else if (arr[nx][ny] == 1) {
					int num = map[x][y].size() - j;
					for (int jj = map[x][y].size() - 1; jj >= j; jj--) {
						map[nx][ny].push_back(map[x][y][jj]);
						
						coord[map[x][y][jj].first] = { nx,ny };
					}
					if (map[nx][ny].size() >= 4) {
						cout << time << "\n";
						return 0;
					}
					while (num--) map[x][y].pop_back();
				}
			}
		}
		time++;
	}
	cout << "-1\n";

	return 0;

}