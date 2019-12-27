#include <iostream>
using namespace std;
const int MAXN = 2 * 123457 ;
bool check[MAXN];
int psum[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	for (int i = 2; i < MAXN; i++) {
		check[i] = true;
	}
	for (int i = 2; i * i < MAXN; i++) {
		if (check[i]) {
			for (int j = i * i; j < MAXN; j+=i) {
				check[j] = false;
			}
		}
	}
	for (int i = 1; i < MAXN; i++) {
		if (check[i]) {
			psum[i] = psum[i-1] + 1;
		}
		else {
			psum[i] = psum[i - 1];
		}
	}
	while (1) {
		cin >> N;
		if (N == 0) break;
		cout << psum[2 * N] - psum[N] << "\n";
	}
	return 0;
}