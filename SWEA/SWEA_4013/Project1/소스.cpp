#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int map[4][8];
int tmp_map[4][8];

int K;
pair<int, int> order[20];

void shift(int map[],int mode) {
	// 시계방향
	if (mode == 1) {
		int tmp = map[7];
		for (int i = 7; i >= 1; i--) {
			map[i] = map[i - 1];
		}
		map[0] = tmp;
	}
	else {
		int tmp = map[0];
		for (int i = 0; i < 7; i++) {
			map[i] = map[i + 1];
		}
		map[7] = tmp;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		cin >> K;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> map[i][j];
				tmp_map[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < K; i++) {
			int idx, dir;
			cin >> idx >> dir;
			idx--;
			order[i] = { idx,dir };
		}
		
		for (int i = 0; i < K; i++) {
			memcpy(tmp_map, map, sizeof(map));
			int idx = order[i].first;
			int dir = order[i].second;
			// idx기준 왼쪽으로
			int tmp_dir = dir;
			shift(tmp_map[idx], tmp_dir);
			for (int j = idx; j >= 1; j--) {
				if (map[j][6] == map[j - 1][2]) break;
				if (tmp_dir == 1) {
					tmp_dir = -1;
				}
				else {
					tmp_dir = 1;
				}
				shift(tmp_map[j - 1], tmp_dir);
			}
			// idx기준 오른쪽으로
			tmp_dir = dir;
			for (int j = idx; j < 3; j++) {
				if (map[j][2] == map[j + 1][6]) break;
				if (tmp_dir == 1) {
					tmp_dir = -1;
				}
				else {
					tmp_dir = 1;
				}
				shift(tmp_map[j + 1], tmp_dir);
			}
			memcpy(map, tmp_map, sizeof(tmp_map));
		}
		int ans = 0;
		for (int i = 0; i < 4; i++) {
			ans += (map[i][0] << i);
		}
		cout << "#"<< test_case<<" "<<ans << "\n";
	}
	
	return 0;
}