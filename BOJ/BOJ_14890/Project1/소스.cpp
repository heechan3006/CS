#include <iostream>
#include <algorithm>
using namespace std;

int map[100][100];
bool visited[100];
int copy_map[100][100];
int N, L;
int ans;
void  slope(int i, bool c) {
	int cnt = 1;
	for (int j = 0; j < N - 1; j++) {
		int d;
		if (c == 0) {
			d = map[i][j + 1] - map[i][j];
		}
		else {
			d = map[j + 1][i] - map[j][i];
		}
		if (d == 0) cnt++;
		else if (d == 1 && cnt >= L) cnt = 1;
		else if (d == -1 && cnt >= 0) cnt = -L + 1;
		else return;
	}
	if (cnt >= 0) ans++;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	ans = 0;
	for (int i = 0; i < N; i++) {
		slope(i, 0);
		slope(i, 1);
	}
	cout << ans << "\n";
	return 0;
}