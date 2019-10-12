#include <iostream>

using namespace std;

int N;
int D[11];

int main() {
	int t;
	cin >> t;
	while (t--){
		cin >> N;
		D[1] = 1;
		D[2] = 2;
		D[3] = 4;
		for (int i = 4; i <= N; i++) {
			D[i] = D[i - 1] + D[i - 2] + D[i - 3];
		}
		printf("%d\n", D[N]);
	}
	return 0;
}