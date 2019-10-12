#include <iostream>
#include <algorithm>
#define MAXN 100001

using namespace std;
int D_min[2][3];
int D_max[2][3];
int A[MAXN][3];

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		D_min[0][i] = A[0][i];
		D_max[0][i] = A[0][i];
	}
	int ans_min = 1e6;
	int ans_max = 0;
	for (int i = 1; i < N; i++) {
		int curr = i % 2;
		int prev = (i - 1) % 2;
		D_min[curr][0] = min(D_min[prev][1], D_min[prev][0]) + A[i][0];
		D_min[curr][1] = min(D_min[prev][0], min(D_min[prev][1], D_min[prev][2])) + A[i][1];
		D_min[curr][2] = min(D_min[prev][1], D_min[prev][2]) + A[i][2];
		
		D_max[curr][0] = max(D_max[prev][1], D_max[prev][0]) + A[i][0];
		D_max[curr][1] = max(D_max[prev][0], max(D_max[prev][1], D_max[prev][2])) + A[i][1];
		D_max[curr][2] = max(D_max[prev][1], D_max[prev][2]) + A[i][2];
		
		
	}
	
	for (int i = 0; i < 3; i++) {
		ans_min = min(ans_min, D_min[(N-1)%2][i]);
		ans_max = max(ans_max, D_max[(N-1)%2][i]);
	}
	cout << ans_max << " " << ans_min << "\n";
}