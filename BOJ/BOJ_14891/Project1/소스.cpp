#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

string cycle[4];
string tmp[4];
int N;
void go(int idx, int dir) {
	string tmp_s = "";
	if (dir == 1) {
		tmp_s += tmp[idx][7];
		for (int i = 0; i < 7; i++) {
			tmp_s += tmp[idx][i];
		}
	}
	else {
		for (int i = 1; i < 8; i++) {
			tmp_s += tmp[idx][i];
		}
		tmp_s += tmp[idx][0];
	}
	tmp[idx] = tmp_s;
}
void rotate_cycle(int idx, int dir) {
	int tmp_dir = dir;
	go(idx, tmp_dir);
	for (int i = idx; i > 0; i--) {
		if (cycle[i][6] != cycle[i - 1][2]) {
			tmp_dir = -tmp_dir;
			go(i - 1, tmp_dir);
			continue;
		}
		break;
	}
	tmp_dir = dir;
	for (int i = idx; i < 3; i++) {
		if (cycle[i][2] != cycle[i + 1][6]) {
			tmp_dir = -tmp_dir;
			go(i + 1, tmp_dir);
			continue;
		}
		break;
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 4; i++) {
		cin >> cycle[i];
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			tmp[j] = cycle[j];
		}
		int idx, dir;
		cin >> idx >> dir;
		idx--;
		rotate_cycle(idx, dir);
		for (int j = 0; j < 4; j++) {
			cycle[j] = tmp[j];
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (cycle[i][0] == '1') ans += (1 << i);
	}
	cout << ans << "\n";
	return 0;
}