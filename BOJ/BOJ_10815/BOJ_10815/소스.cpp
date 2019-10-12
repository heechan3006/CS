#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define MAX_N 500000
using namespace std;

int N, M;
int card[MAX_N];
int card_1[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &card[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &card_1[i]);
	}
	sort(card, card + N);
	for (int i = 0; i < M; i++) {
		int row = 0;
		int high = N - 1;
		int ans = 0;
		while (row <= high) {
			int mid = (row + high) / 2;
			if (card[mid] <= card_1[i]) {
				if (card[mid] == card_1[i]) {
					ans = 1;
					break;
				}
				row = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		printf("%d ", ans);	
	}
	return 0;
}