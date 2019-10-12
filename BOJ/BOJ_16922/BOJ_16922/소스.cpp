#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
bool visited[50 * 21];
int value[] = { 1,5,10,50 };
int N;
int cnt = 0;
void go(int now, int lower, int sum) {
	if (now == N) {
		if (!visited[sum]) {
			visited[sum] = true;
			cnt++;
		}
	}
	else {
		for (int k = lower; k < 4; k++) {
			go(now + 1, k, sum + value[k]);
		}
	}
}
int main() {
	cin >> N;
	go(0, 0, 0);
	printf("%d\n", cnt);
	return 0;
}