#include <iostream>
#include <algorithm>

using namespace std;
int map[100000];
int N, K;

void quicksort(int* base, int start, int end,int max) {
	if (start >= end || start >= max) {
		return;
	}
	int left = start - 1, right = end + 1;
	int pivot = base[(start + end) / 2];
	while (1) {
		while (base[++left] > pivot);
		while (base[--right] < pivot);
		if (left >= right) break;
		swap(base[left], base[right]);
	}
	quicksort(base, start, left - 1, max);
	quicksort(base, right + 1, end, max);
}
int main() {
	int t;
	int width = 0;
	scanf("%d",&t);
	for (int test_case=1; test_case <=t; test_case++){
		scanf("%d %d",&N,&K);
		for (int i = 0; i < N; i++) {
			scanf("%d", map+i);
		
		}
		width = map[N - 1] - map[0];
		if (K >= N) {
			printf("#%d 0\n", test_case);
		}
		else if (K == 1) {
			printf("#%d %d\n", test_case, width);
		}
		else {
			int sum = 0;
			for (int i = 1; i < N; i++) {
				map[i - 1] = map[i] - map[i - 1];
			}
			K--;
			quicksort(map, 0, N - 2, K);
			for (int i = 0; i < K; i++) {
				sum += map[i];
			}
			printf("#%d %d\n", test_case, width - sum);
		}		
	}
	return 0;
}