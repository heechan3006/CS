#include <iostream>

using namespace std;

int d[1001];
int main() {
	int n;
	cin >> n;
	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= n; i++) {
		d[i] = 2 * d[i - 2] + d[i - 1];
		d[i] %= 10007;
	}
	printf("%d", d[n]);
	return 0;
}