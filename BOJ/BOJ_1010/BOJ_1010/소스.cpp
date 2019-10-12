#include <iostream>
#include <cstring>
using namespace std;

int N,M;
int D[31][31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(D, 0, sizeof(D));
		cin >> N >> M;
		for (int i = 0; i <= M ; i++) {
			D[1][i] = i;
		}
		for (int i = 2; i <= N; i++) {
			for (int j = i; j<= M ; j++) {
				for (int k = j; k >=i; k--){
					D[i][j] += D[i - 1][k - 1];
				}
			}
		}
		cout << D[N][M] << "\n";
	}
}