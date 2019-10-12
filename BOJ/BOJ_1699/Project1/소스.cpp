#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int D[100001];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		D[i] = N;
	}
	D[1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j*j<= i; j++){
			D[i] = min(D[i],D[i - j*j] + 1);
		}
	}
	cout << D[N] << "\n";
}