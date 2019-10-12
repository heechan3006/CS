#include <iostream>

using namespace std;

int N;
int D[100001];

int main() {
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (D[i] > D[i - j * j] + 1 || D[i] == 0) {
				D[i] = D[i - j * j] + 1;
			}
		}
	}
	printf("%d\n", D[N]);
}