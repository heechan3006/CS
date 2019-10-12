#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a[1001];
int d[1001];

int main() {
	cin >> N;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		int sum = 0;
		for (int j = 1; j <= i; j++) {
			if (a[i] < a[j]) {
				sum = max(sum, d[j]);
			}
		}
		d[i] = sum + 1;
		ans = max(ans, d[i]);
	}
	printf("%d\n", ans);
	return 0;
}