#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

int D[16][1 << 16];
int W[16][16];
int N;
int ans = INF;
int dp(int now, int visited) {
	if (visited == (1 << N) - 1) {
		if (W[now][0] != 0) {
			return W[now][0];
		}
		return INF;
	}
	int &result = D[now][visited];
	if (result != -1) return result;
	result = INF;
	for (int next = 0; next < N; next++) {
		if (visited & (1 << next) || W[now][next] == 0) continue;
		result = min(result, dp(next, visited | (1 << next)) + W[now][next]);
	}
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}
	memset(D, -1, sizeof(D));
	int ans =dp(0, 1);
	cout << ans << "\n";
}