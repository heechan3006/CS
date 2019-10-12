#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, K;

bool d[360];
int arr[10];
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	d[0] = true;
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < 360; k++) {
			for (int j = 0; j < 360; j++) {
				if (d[j] == false) continue;
				d[(j - arr[i] + 360) % 360] = true;
				d[(j + arr[i]) % 360] = true;
			}
		}
	}
	int tmp;
	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp);
		if (d[tmp]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
	
}