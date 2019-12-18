#include <iostream>
using namespace std;
const int MAXN = 2187;

int N;
int map[MAXN][MAXN];
int ans[3] = { 0, };
pair<int, int> check(int x1, int y1, int x2, int y2) {
	pair<int, int> sum = { 0,0 };
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (map[i][j] == -1) sum.first++;
			else sum.second+= map[i][j];
		}
	}
	return sum;
}
void go(int x1, int y1, int n) {
	if (n == 1) {
		ans[map[x1][y1] + 1]++;
		return;
	}
	bool flag = false;
	int num = map[x1][y1];
	for (int i = x1; i < x1 + n && !flag; i++) {
		for (int j = y1; j < y1 + n; j++) {
			if (num != map[i][j]) {
				flag = true;
				break;
			}
		}
	}
	if (!flag) {
		ans[num + 1]++;
		return;
	}
	
	int offset = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			go(x1 + offset * i, y1 + offset * j, offset);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	go(0, 0, N);
	for (int i = 0; i < 3; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}