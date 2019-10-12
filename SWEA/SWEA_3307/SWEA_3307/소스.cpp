#include <iostream>
#include <cstring>

using namespace std;
int num[1001];
int arr[1001];
int N;
int ans = 0;

int main() {
	int t;
	scanf("%d", &t);
	for (int test_case=1; test_case<= t; test_case++){
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &num[i]);
		}
		ans = 0;
		for (int i = 0; i < N; i++) {
			arr[i] = 1;
			for (int j = 0; j < i; j++) {
				if (num[j] < num[i] && arr[i] < arr[j] + 1) {
					arr[i] = arr[j] + 1;
				}
			}
			if (arr[i] > ans) ans = arr[i];
		}
		//printf("%d\n", ans);
		printf("#%d %d\n", test_case, ans);
		memset(num, 0, sizeof(num));
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}