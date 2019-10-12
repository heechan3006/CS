#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

vector<int> v;


int main() {
	int t;
	scanf("%d", &t);
	for (int test_case= 1; test_case<=t; test_case++){
		scanf("%d %d", &N, &K);
	
		for (int i = 0; i < N; i++) {
			int tmp;
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		double a = 0;
		sort(v.begin(), v.end());
		for (int i = N - K; i < N; i++) {
			a = (a + (double)v[i]) / 2;
		}
		printf("#%d %lf\n", test_case,a);
		v.clear();
	}
	return 0;
}