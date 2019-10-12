#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#define MAXN 101
#define MOD 1000000000
using namespace std;

int cache[10][MAXN][1 << 10];

int N;
int dp(int start, int length, int num) {
	if (length == N) {
		return num == (1 << 10) - 1 ? 1 : 0;
	}
	int& result = cache[start][length][num];
	if (result != -1) return result;

	result = 0;
	if (start - 1 >= 0) {
		result += dp(start - 1, length + 1, num | (1 << start - 1));
	}
	if (start + 1 < 10) {
		result += dp(start + 1, length + 1, num | (1 << start + 1));
	}
	result %= MOD;
	return result;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case=1; test_case<=t; test_case++){
		scanf("%d", &N);
		int result = 0;
		for (int start = 1; start <= 9; start++) {
			memset(cache, -1, sizeof(cache));
			result += dp(start, 1, 1 << start);
			result %= MOD;
		}
		printf("#%d %d\n", test_case,result);
	}
	return 0;
}


