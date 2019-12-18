#include <iostream>
#define MAXN 8
using namespace std;

int sorted[MAXN];
int list[] = { 21,10,12,20,25,13,15,22 };
void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
		}
	}
	if (i > mid) {
		for (int l = j; l <= right; l++) {
			sorted[k++] = list[l];
		}
	}
	else {
		for (int l = i; l <= mid; l++) {
			sorted[k++] = list[l];
		}
	}
	for (int l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}
void merge_sort(int left, int right) {
	int mid = (left + right) / 2;
	if (left == right) return;
	merge_sort(left, mid);
	merge_sort(mid + 1, right);
	merge(left, mid, right);
}
int main() {
	merge_sort(0, 7);
	for (int i = 0; i < MAXN; i++) {
		printf("%d ", list[i]);
	}
	return 0;
}