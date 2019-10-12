#include <iostream>
#include <algorithm>

using namespace std;

int N;
int d[10001];
int a[10001];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	d[1] = a[1];
	d[2] = a[1] + a[2];

	for (int i = 3; i <= N; i++) {
		d[i] = max(d[i - 3] + a[i - 1] + a[i], d[i - 2] + a[i]);
		d[i] = max(d[i], d[i - 1]);
	}
	printf("%d\n", d[N]);
	return 0;
}