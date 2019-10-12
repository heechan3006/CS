#include <iostream>

using namespace std;

long long d[1000001];
const long long mod = 1000000009LL;
int t;
int main() {
	long long n;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 4; j <= n; j++) {
			d[j] = d[j - 1] + d[j - 2] + d[j - 3];
			d[j] = d[j] % mod;
		}
		printf("%d\n", d[n]);
	}
	
	return 0;
}