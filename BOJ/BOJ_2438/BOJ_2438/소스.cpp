#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int N;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int tmp = i;
		while (tmp--) {
			printf("*");
		}
		printf("\n");
	}
}