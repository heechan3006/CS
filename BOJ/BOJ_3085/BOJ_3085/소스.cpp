#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char map[50][50];
int N;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void Swap(int x1, int y1, int x2, int y2) {
	char tmp = map[x2][y2];
	map[x2][y2] = map[x1][y1];
	map[x1][y1] = tmp;
}
int check() {
	int res = 1;
	for (int i = 0; i < N; i++) {
		int tmp = 1;
		for (int j = 1; j < N; j++) {
			if (map[i][j - 1] == map[i][j]) {
				tmp++;
			}
			else {
				res = max(res, tmp);
				tmp = 1;
			}
		}
		res = max(res, tmp);
	}
	for (int j = 0; j < N; j++) {
		int tmp = 1;
		for (int i = 0; i < N-1; i++) {
			if (map[i+1][j] == map[i][j]) {
				tmp++;
			}
			else {
				res = max(res, tmp);
				tmp = 1;
			}
		}
		res = max(res, tmp);
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {

			Swap(i, j, i, j + 1);
			ans = max(ans,check());
			Swap(i, j, i, j + 1);
			
			Swap(i, j, i+1, j);
			ans = max(ans, check());
			Swap(i, j, i+1, j);
			
		}
	}
	cout << ans << "\n";
	return 0;
}