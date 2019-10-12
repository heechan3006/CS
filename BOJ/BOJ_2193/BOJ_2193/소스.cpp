#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long D[91][2];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	memset(D, 0, sizeof(D));
	D[1][0] = 0;
	D[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		D[i][0] = D[i - 1][1] + D[i - 1][0];
		D[i][1] = D[i - 1][0] ;
	}
	cout << D[N][0] + D[N][1] << "\n";
}