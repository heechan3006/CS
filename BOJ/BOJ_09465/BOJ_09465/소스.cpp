#include <iostream>
#include <algorithm>

using namespace std;

int N;
int D[2][100001];
int a[2][100001];
int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> a[i][j];
			}
		}
		D[0][0] = 0;
		D[1][0] = 0;
		D[0][1] = a[0][1];
		D[1][1] = a[1][1];
		for (int i = 2; i <= N; i++) {
			D[0][i] = max(D[1][i - 2], D[1][i - 1]) + a[0][i];
			D[1][i] = max(D[0][i - 2], D[0][i - 1]) + a[1][i];
		}
		printf("%d\n", max(D[0][N], D[1][N]));
	}
	return 0;
}