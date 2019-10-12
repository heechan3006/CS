#include <iostream>
#include <cstring>
#define MOD 9901
#define MAXN 100001
using namespace std;

int N;
int D[MAXN][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	
	D[0][0] = 1;
	D[0][1] = 1;
	D[0][2] = 1;
	for (int i = 1; i < N; i++) {
		
		D[i][0] = (D[i-1][0] + D[i-1][1] + D[i-1][2])%MOD;
		D[i][1] = (D[i - 1][0] + D[i-1][2])%MOD;
		D[i][2] = (D[i - 1][0] + D[i - 1][1])%MOD;
	}
	cout << (D[N - 1][0] + D[N - 1][1] +D[N-1][2])%MOD<< "\n";
}
