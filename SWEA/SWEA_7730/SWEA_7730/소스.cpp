#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


#define MAXV 1000000
using namespace std;

int map[MAXV];
int N;
int M;


int main() {
	int t;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int test_case = 1; test_case<=t; test_case++){
		
		cin >> N >> M;
		
		for (int i = 0; i < N; i++) {
			cin >> map[i];
		}
		int left = 0;
		int right = 1e9;
		int ans = -1;
		int mid;
		long long sum = 0;
		while (left <= right) {
			sum = 0;
			mid = (left + right) / 2;
			for (int i = 0; i < N; i++) {
				if (map[i] - mid > 0) sum += map[i] - mid;
			}
			
			if (sum >= M) {
				left = mid + 1;
				if (ans < mid) ans = mid;
			}
			else {	
				right = mid - 1;
			}
			
		}
		printf("#%d %d\n", test_case,ans);
	}
	return 0;
}

