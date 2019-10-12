#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 101
#define INF 987654321
using namespace std;

int N, M;
vector<int> v;
int D[MAXN][MAXN];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			D[i][j] = INF;
		}
	}
	ans = 100 * 100;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		D[from][to] = 1;
		D[to][from] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			sum += D[i][j];
		}
		if (ans >= sum) {
			if (ans == sum) {
				v.push_back(i);
			}
			else {
				v.clear();
				ans = sum;
				v.push_back(i);
			}
		}
	}
	cout << v[0] << "\n";
	return 0;
}