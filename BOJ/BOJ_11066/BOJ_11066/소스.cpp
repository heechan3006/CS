#include <iostream>
#include <algorithm>
using namespace std;

int D[501][501];
int cost[501];
int sum[501];
int K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}
		for (int i = 1; i < K; i++) {
			for (int j = 1; j + i <= K; j++) {
				int k = j + i;
				D[j][k] = 98765432;
				for (int mid = j; mid < k; mid++) {
					D[j][k] = min(D[j][k], D[j][mid] + D[mid + 1][k] + sum[k] - sum[j - 1]);
				}
			}
		}
		cout << D[1][K] << "\n";
	}
	return 0;
}