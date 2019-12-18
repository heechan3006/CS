#include <iostream>
using namespace std;
const int MAXN = 10001;

int num[MAXN];

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		
		cin >> tmp;
		num[tmp]++;
	}
	for (int i = 1; i < MAXN; i++) {
		if (num[i] == 0) continue;
		while (num[i]--) {
			printf("%d\n", i);
		}
	}
	return 0;
}