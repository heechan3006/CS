#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[101];
int ans = 0;
void go(int start,int end, int cnt) {
	if (start >= end || end - start + 1 < cnt) {
		if (arr[start] >= 50) ans++;
		return;
	}

	if (arr[start] * cnt >= 50) {
		ans++;
		go(start + 1, end - cnt + 1, 1);
	}
	else{
		go(start, end,cnt + 1);
	}
}
void quick_sort(int* map, int start, int end) {
	if (start >= end) {
		return;
	}
	int left = start-1 ;
	int right = end + 1;
	int pivot = map[(left + right) / 2];
	while(1){
		while (map[++left] > pivot);
		while (map[--right] < pivot);
		if (left >= right) break;
		swap(map[left], map[right]);
	}
	quick_sort(map, start, left - 1);
	quick_sort(map, right+1, end);
	
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case=1; test_case<=t; test_case++){
		scanf("%d", &N);
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		ans = 0;
		quick_sort(arr,0,N-1);
		go(0, N-1,1);
		//printf("%d\n", ans);
		printf("#%d %d\n",test_case, ans);
	}
	return 0;
}