#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
unsigned long long A;
int main() {
	scanf("%llu", &A);
	int cnt = 0; 
	int res = 0;
	unsigned long long temp;
	while (A > 1) {
		temp = 1;
		while (temp < A) {
			temp *= 2;
		}
		if (temp == A) {
			res = 0;
			break;
		}
		A = temp - A;
		cnt++;
	}
	if (cnt % 2 == 1) res = 1;
	else res = 0;
	printf("%d\n", res);

	
}