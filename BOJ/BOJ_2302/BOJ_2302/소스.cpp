#include <iostream>
#include <cstring>

using namespace std;
int VIP[41];
int D[41];
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N>>M; 
	for (int i = 1; i <= M; i++) {
		cin >> VIP[i];
	}
	D[0] = 1;
	D[1] = 1;
	for (int i = 2; i <= N; i++) {
		D[i] = D[i - 1] + D[i - 2];
	}
	int result = 1;
	for (int i = 1; i <= M; i++) {
		result *= D[VIP[i] - VIP[i - 1] - 1];
	}
	result *= D[N - VIP[M]];
	cout << result << "\n";
}