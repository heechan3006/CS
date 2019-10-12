#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[31][31 * 500];
int weight[31];
int marble[7];
int N, M;
void dp(int idx, int cur_weight) {
	if (idx > N) return;
	int& ret = cache[idx][cur_weight];
	if (ret != -1) return;
	ret = 1;
	dp(idx + 1, cur_weight + weight[idx]);
	dp(idx + 1, cur_weight);
	dp(idx + 1, abs(cur_weight - weight[idx]));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> weight[i];
	}
	cin >> M;
	for (int j = 0; j < M; j++) {
		cin >> marble[j];
	}
	memset(cache, -1, sizeof(cache));
	dp(0, 0);
	for (int i = 0; i < M; i++) {
		if (marble[i] > 30 * 500) {
			cout << "N ";
		}
		else if (cache[N][marble[i]] == 1) {
			cout << "Y ";
		}
		else {
			cout << "N ";
		}
	}
	return 0;
}