#include <iostream>
#include <algorithm>
#define MAXN 20
#define INF 987654321
using namespace std;

int N;

int map[MAXN][MAXN];
int arr[MAXN][MAXN];
int answer = INF;
int simulate(int x, int y, int d1, int d2) {
	int num[5] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = 5;
		}
	}
	// 1번
	int idx = y;
	for (int i = 0; i < x + d1; i++) {
		if (i >= x) idx--;
		for (int j = 0; j <= idx; j++) {
			arr[i][j] = 1;
		}
	}
	// 2번
	idx = y + 1;
	for (int i = 0; i <= x + d2; i++) {
		if (i > x) idx++;
		for (int j = idx; j < N; j++) {
			arr[i][j] = 2;
		}
	}
	// 3번
	idx = y - d1 + d2 ;
	for (int i = N - 1; i >= x + d1; i--) {
		if (i < x + d1 + d2) idx--;
		for (int j = 0; j < idx; j++) {
			arr[i][j] = 3;
		}
	}
	// 4번
	idx = y - d1 + d2;
	for (int i = N - 1; i > x + d2; i--) {
		if (i <= x + d1 + d2) idx++;
		for (int j = idx; j < N; j++) {
			arr[i][j] = 4;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			num[arr[i][j] - 1] += map[i][j];
		}
	}
	sort(num, num + 5);
	return num[4] - num[0];
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
	for (int x = 0; x < N - 1; x++) {
		for (int y = 1; y < N - 1; y++) {
			for (int d1 = 1; d1 <= y; d1++) {
				for (int d2 = 1; d2 <= N - y; d2++) {
					if (x + d1 + d2 >= N || y - d1 < 0 || y + d2 >= N) continue;
					int sum = simulate(x, y, d1, d2);
					if (answer > sum) answer = sum;
					if (answer == 0) {
						cout << "0\n";
						return 0;
					}
				}
			}
		}
	}
	cout << answer << "\n";
	return 0;
}