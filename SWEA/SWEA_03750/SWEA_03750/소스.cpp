#include <iostream>

using namespace std;


int go(long long n,int cnt) {
	int tmp;
	tmp = n % 10;
	n = n / 10;
	if (n == 0) {
		if ((cnt + tmp) / 10 == 0) return cnt + tmp;
		n = cnt + tmp;
		cnt = 0;
		tmp = 0;
	}
	go(n, cnt + tmp);
}
long long n;

int main() {
	int t;
	int cnt;
	scanf("%d", &t);
	for (int test_case=1; test_case <= t; test_case++){
		scanf("%llu", &n);
		cnt = go(n,0);
		printf("#%d %d\n", test_case,cnt);
	}
	return 0;
}