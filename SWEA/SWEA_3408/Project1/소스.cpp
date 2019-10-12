#include <iostream>

using namespace std;


int N;
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {
		scanf("%d", &N);
		unsigned long long sum1 = 0;
		unsigned long long sum2 = 0;
		unsigned long long sum3 = 0;
		int s1 = 1;
		int s2 = 1;
		int s3 = 2;
		for (int i = 0; i < N; i++){
			sum1 += s1;
			s1++;
			sum2 += s2;
			s2 += 2;
			sum3 += s3;
			s3 += 2;
			
		}
		printf("#%d %llu %llu %llu\n", test_case,sum1, sum2, sum3);
		
	}
	return 0;
}