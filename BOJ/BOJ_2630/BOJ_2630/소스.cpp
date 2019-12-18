#include <iostream>
using namespace std;
const int MAXN = 128;

int map[MAXN][MAXN];
int N;
int ans[2] = { 0, };
int check(int x1, int y1, int x2, int y2) {
	int sum = 0;
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			sum += map[i][j];
		}
	}
	return sum;
}
void go(int x1, int y1, int x2, int y2) {
	int sum = check(x1, y1, x2, y2);
	if (sum == 0) {
		ans[0]++;
		return;
	}
	if (sum == (x2 - x1 + 1) * (x2 - x1 + 1)) {
		ans[1]++;
		return;
	}
	int x = (x2 + x1 + 1) / 2;
	int y = (y2 + y1 + 1) / 2;
	// upper left
	go(x1, y1, x-1, y-1);
	// upper right
	go(x1, y, x - 1, y2);
	// lower left
	go(x, y1, x2, y - 1);
	// lower right
	go(x, y, x2, y2);
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
	go(0,0,N-1, N-1);
	cout << ans[0] << "\n";
	cout << ans[1] << "\n";
	return 0;
}