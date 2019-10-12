#include <iostream>

using namespace std;

int N;

int main() {
	cin >> N;
	if (N < 100) {
		cout << N << "\n";
		return 0;
	}
	int cnt = 99;
	for (int i = 100; i <= N; i++) {
		int a = i % 10;
		int b = (i / 10) % 10;
		int c = i / 100;
		if (a - b == b - c) {
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}