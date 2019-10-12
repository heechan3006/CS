#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 1000000
using namespace std;

int D[MAXN];
int N;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	memset(D, 0, sizeof(D));
	D[1] = 0;
	for (int i = 2; i <= N; i++) {
		D[i] = D[i - 1] + 1;
		if (i % 2 == 0) {
			D[i] = min(D[i],D[i / 2] + 1);
		}
		if (i % 3 == 0) {
			D[i] = min(D[i], D[i / 3] + 1);
		}
		
	}
	cout << D[N] << "\n";
}