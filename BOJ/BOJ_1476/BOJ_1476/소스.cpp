#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int E, S, M;

int main() {
	scanf("%d%d%d", &E, &S, &M);
	int e = 1;
	int s = 1;
	int m = 1;
	int years = 1;
	while (1) {
		if (e % 16 == 0) e = 1;
		if (s % 29 == 0) s = 1;
		if (m % 20 == 0) m = 1;
		if (e == E && s == S && m == M) {
			printf("%d\n", years);
			break;
		}
		e++;
		s++;
		m++;
		
		years++;
	}
	return 0;
}