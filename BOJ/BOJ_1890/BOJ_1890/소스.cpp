#include <iostream>
#include <cstring>

using namespace std;

long long D[101][101];
int A[101][101];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	D[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == 0) continue;
			if (i + A[i][j] < N) {
				D[i + A[i][j]][j] += D[i][j] ;
			}
			if (j + A[i][j] < N) {
				D[i][j + A[i][j]] += D[i][j] ;
			}
		}
	}
	cout << D[N - 1][N - 1] << "\n";
	
}