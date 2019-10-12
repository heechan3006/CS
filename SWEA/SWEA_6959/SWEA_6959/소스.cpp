#include <iostream>

using namespace std;
int N;
char ans[2] = { 'B','A' };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int order = 0;
	int sum = 0;
	while (N) {
		sum += N % 10;
		N /= 10;
		order++;
	}
	int cnt = 0;
	while (1) {
		int a = sum / 10;
		int b = sum % 10;
		if (a == 0) break;
		cnt += a;
		sum = a + b;
	}
	cnt += order - 1;
	cout << ans[cnt % 2] << "\n";
}