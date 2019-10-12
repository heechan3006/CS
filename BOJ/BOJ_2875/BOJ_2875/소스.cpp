#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;

int main() {
	scanf("%d%d%d", &N, &M, &K);
	
	printf("%d\n", min(min(N/2,M),(N+M-K)/3));
}