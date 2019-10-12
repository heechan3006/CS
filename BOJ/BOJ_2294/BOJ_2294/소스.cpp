#include <iostream>
#include <algorithm>

#define MAXK 10001
#define MAXN 101

using namespace std;

int N, K;
int D[MAXK];
int A[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		D[i] = MAXK;
	}
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	
	for (int j = 1; j <= N; j++) {
		for (int i = A[j]; i <= K; i++) {
			D[i] = min(D[i],D[i - A[j]] + 1);
		}
	}
	if (D[K] == MAXK) cout << "-1\n";
	else{
		cout << D[K]<<"\n";
	}
	return 0;
}