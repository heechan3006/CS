#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int weight[10];
bool visited[10];
int n;
int sum;
int result = 0;
int two[10] = { 1,2,4,8,16,32,64,128,256,512 };
int factor[10] = { 0,1,2,6,24,120,720,5040,40320,362880 };
void calc(int now, int left, int right) {
	if (now == n) {
		result++;
		return;
	}
	if (left >= sum - left) {
		result += two[n - now] * factor[n - now];
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		calc(now + 1, left + weight[i], right);
		if (left >= right + weight[i]) {
			calc(now + 1, left, right + weight[i]);
		}
		visited[i] = false;
	}
}
int main() {
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++){
		cin >> n;
		memset(visited, false, sizeof(visited));
		memset(weight, 0, sizeof(weight));
		sum = 0;
		result = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &weight[i]);
			sum += weight[i];
		}
		calc(0, 0, 0);
		printf("#%d %d\n", test_case,result);
	}
	return 0;
}