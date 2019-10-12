#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 98765432
using namespace std;

int map[20][20];
int N, M,K;
int ans;
int cost[20 + 2];

int check_cost(int sx, int sy, int k) {
	//위쪽 삼각형
	int idx = 0;
	int num = 0;
	for (int i = sx - k + 1; i <= sx; i++) {
		idx++;
		for (int j = sy - idx + 1; j < sy + idx; j++) {
			if (i < 0 || j < 0 || i >= N || j >= N) continue;
			if (map[i][j]) num+=M;
		}
	}
	//아래쪽 삼각형
	for (int i = sx + 1; i <= sx + k; i++) {
		idx--;
		for (int j = sy - idx + 1; j < sy + idx; j++) {
			if (i < 0 || j < 0 || i >= N || j >= N) continue;
			if (map[i][j]) num+=M;
		}
	}
	
	return num;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i < 22; i++) cost[i] = i * i + (i - 1) * (i - 1);
	for (int test_case=1; test_case<=t; test_case++){
		
		cin >> N >> M;
		int pay = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j]) pay += M;
			}
		}

		for (K = 1; K <= 21; K++) if (cost[K] > pay) break;
		
		

		for (int k = K-1; k >= 1; k--){
			ans = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int sum = check_cost(i, j, k);
					if (ans < sum) ans = sum;
					}
				}
			if (ans >= cost[k]) break;
		}
		ans /= M;
		cout << "#"<<test_case<<" "<<ans << "\n";
	}
	return 0;
}