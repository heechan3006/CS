#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 50
using namespace std;
int N;
int A[MAXN], B[MAXN];
void quick_sort(int i, int j,int arr[]) {
	if (i >= j) return;
	int left = i;
	int right = j;
	int pivot = arr[(i + j) / 2];
	while (left <= right) {
		while (arr[left] < pivot) left++;
		while (arr[right] > pivot) right--;
		if (left <= right) {
			int tmp = arr[right];
			arr[right] = arr[left];
			arr[left] = tmp;
			left++;
			right--;
		}
	}
	quick_sort(i, right, arr);
	quick_sort(left, j, arr);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	quick_sort(0, N - 1, A);
	quick_sort(0, N - 1, B);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += A[N-i-1] * B[i];
	}

	cout << ans << "\n";
	return 0;
}