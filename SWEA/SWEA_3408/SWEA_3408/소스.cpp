#include <iostream>

using namespace std;


long long N;
long long s1, s2, s3;
int main() {
	int t;
	cin >> t;
	for (int test_case=1; test_case <= t; test_case++){
		cin >> N;
		s1 = (N * (1 + N)) / 2;
		s2 = (N * (2 + (N - 1) * 2)) / 2;
		s3 = (N * (4 + (N - 1) * 2)) / 2;
		printf("#%d %llu %llu %llu\n", test_case,s1, s2, s3);
	}
	return 0;
}