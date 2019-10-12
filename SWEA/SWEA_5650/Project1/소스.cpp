#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int map[100][100];
bool visited[100][100][4];
int N;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
struct hole {
	int pos;
	int xy[2][2];
} arr[6];
vector<pair<int, int>> v[11];

int change_dir(int idx, int dir) {
	if (idx == 1) {
		if (dir == 0) return 2;
		else if (dir == 1) return 0;
		else if (dir == 2) return 3;
		else return 1;
	}
	else if (idx == 2) {
		if (dir == 0) return 2;
		else if (dir == 1) return 3;
		else if (dir == 2) return 1;
		else return 0;
	}
	else if (idx == 3) {
		if (dir == 0) return 1;
		else if (dir == 1) return 3;
		else if (dir == 2) return 0;
		else return 2;
	}
	else if (idx == 4) {
		if (dir == 0) return 3;
		else if (dir == 1) return 2;
		else if (dir == 2) return 0;
		else return 1;
	}
	else if (idx == 5) {
		if (dir == 0) return 2;
		else if (dir == 1) return 3;
		else if (dir == 2) return 0;
		else return 1;
	}
}
int go(int x, int y, int dir) {
	int score = 0;
	int tmp_x, tmp_y;
	int sx = x;
	int sy = y;
	while (1) {

		x += dx[dir];
		y += dy[dir];
		
		// 벽에 부딪힐 경우 종료 : score*2
		if (x < 0 || y < 0 || x >= N || y >= N) {
			score++;
			if (dir == 0) dir = 2;
			else if (dir == 2) dir = 0;
			else if (dir == 1) dir = 3;
			else dir = 1;

		}
		//시작위치에 도달할 경우 종료.
		else if (sx == x && sy == y) {
			return score;
		}
		// 블랙홀 : score
		else if (map[x][y] == -1) {
			return score;
		}
		else if (x == sx && y == sy) return score;
		// 블록에 부딪힐 경우 : 반대방향으로 향할경우 자신의 블록 제외하고 2배
		else if (1 <= map[x][y] && map[x][y] <= 5) {
			score++;
			int tmp_dir = change_dir(map[x][y], dir);

			dir = tmp_dir;
		}
		else if (map[x][y] >= 6) {
			int a = map[x][y];
			if (arr[map[x][y] - 6].xy[0][0] == x && arr[map[x][y] - 6].xy[0][1] == y) {

				x = arr[a - 6].xy[1][0];
				y = arr[a - 6].xy[1][1];
			}
			else {

				x = arr[a - 6].xy[0][0];
				y = arr[a - 6].xy[0][1];
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		memset(arr, 0, sizeof(arr));


		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] > 5) {
					arr[map[i][j] - 6].xy[arr[map[i][j] - 6].pos][0] = i;
					arr[map[i][j] - 6].xy[arr[map[i][j] - 6].pos][1] = j;
					arr[map[i][j] - 6].pos++;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] != 0) continue;
				for (int k = 0; k < 4; k++) {

					int sum = go(i, j, k);
					if (ans < sum) ans = sum;
				}
			}
		}
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}