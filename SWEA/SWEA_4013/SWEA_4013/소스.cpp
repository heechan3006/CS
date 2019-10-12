#include <iostream>
#include <vector>

using namespace std;


int K;
int map[4][8];
int ans;
void rotate(int now, int dir) {
	// 시계방향
	if (dir == 1) {
		int tmp = map[now][7];
		for (int i = 6; i >= 0; i--) {
			map[now][i + 1] = map[now][i];
		}
		map[now][0] = tmp;
	}
	// 반시계방향
	else if (dir == -1) {
		int tmp = map[now][0];
		for (int i = 1; i < 8; i++) {
			map[now][i - 1] = map[now][i];
		}
		map[now][7] = tmp;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		cin >>  K;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> map[i][j];
		
			}
		}
		while (K--) {
			int dirs[4] = { 0, };
			int idx, dir;
			cin >> idx >> dir;
			idx--;
			dirs[idx] = dir;
			if (idx != 3){
			
				for (int i = idx; i < 3; i++) {
					if (map[i][2] == map[i + 1][6]) break;
					dirs[i + 1] = -dirs[i];
				}
			}
			if (idx != 0) {
				for (int i = idx; i >= 1; i--) {
					if (map[i][6] == map[i - 1][2]) break;
					dirs[i - 1] = -dirs[i];
				}
			}
			for (int i = 0; i < 4; i++) {
				if (dirs[i] != 0) {
					rotate(i, dirs[i]);
				}
			}
		}
		ans = 0;
		for (int i = 0; i < 4; i++) {
			ans += (map[i][0] << i);
		}
		cout << "#"<<test_case<<" "<<ans << "\n";
	}
	return 0;
}