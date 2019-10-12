#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int D[501][501];
int A[501][501];
int N;

int main() {
	cin >> N;
	int cnt = N;
	while(cnt--){
		for (int j = 0; j < N-cnt; j++) {
			cin >> A[cnt][j];
		}
		
	}
	
	for (int i = 0; i < N; i++) {
		D[0][i] = A[0][i];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N-i; j++){
			D[i][j] += max(D[i-1][j],D[i-1][j+1])+A[i][j];
		}
	}
	cout << D[N - 1][0] << "\n";
}