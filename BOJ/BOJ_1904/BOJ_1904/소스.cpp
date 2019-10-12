#include <iostream>
#define MAXN 1000001
#define MOD 15746
using namespace std;

int N;
int D[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	D[1] = 1;
	D[2] = 2;
	for (int i = 3; i <= N; i++) {
		D[i] = (D[i - 1] + D[i - 2])%MOD;
	}
	cout << D[N]%MOD << "\n";
}