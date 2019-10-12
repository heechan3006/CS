#include <iostream>

using namespace std;

int N;
long long D[91][2];

int main() {
	cin >> N;
	D[1][0] = 0;
	D[1][1] = 1;
	D[2][0] = 1;
	D[2][1] = 0;

	for (int i = 3; i <= N; i++) {
		D[i][0] = D[i - 1][0] + D[i - 1][1];
		D[i][1] = D[i - 1][0];
	}
	long long ans = D[N][0] + D[N][1];
	printf("%lld\n", ans);
	return 0;
}