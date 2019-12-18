#include <iostream>
#include <algorithm>
#include <cstring>
const int MAXN = 200;
const int INF = 987654321;
using namespace std;

int cache[MAXN+1];
int N;

int map[MAXN];

int lis(int idx) {
	int& ret = cache[idx + 1];
	if (ret != -1) return ret;
	ret = 0;
	int value = (idx == -1 ? -INF : map[idx]);
	for (int next = idx + 1; next < N; next++) {
		if (value < map[next]) {
			ret = max(ret, lis(next) + 1);
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	cout << N - lis(-1) << "\n";
	return 0;
}