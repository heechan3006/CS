#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

string map[2];
int D[2][101][21];
string scroll;
int dp(int x, int y, int idx) {
	if (idx == scroll.length()) {
		return 1;
	}
	int& ret = D[x][y][idx];
	if (ret != -1) return ret;
	
	ret = 0;
	for (int i = y; i <= map[x].length(); i++) {
		if (map[x][i] == scroll[idx]) {
			ret += dp(1 - x, i+1, idx + 1);
		}
	}
	return ret;
}
int main() {
	cin >> scroll;
	for (int i = 0; i < 2; i++) {
		cin >> map[i];
	}
	memset(D, -1, sizeof(D));
	int ret = 0;
	for (int i = 0; i < 2; i++) {
		ret += dp(i, 0, 0);
	}
	cout << ret << "\n";
	return 0;
}