#include <iostream>
#include <memory.h>
using namespace std;

int ans[101];
bool total[10001];
int n;
int t;

int main() {
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++){
		cin >> n;
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> ans[i];
			sum += ans[i];
		}
	
		total[0] = true;
		for (int i = 0; i < n; i++) {
			for (int j = sum; j >= 0; j--) {
				if (total[j]) {
					total[j + ans[i]] = true;
				}
			}
		}
	
		for (int i = 0; i < 10001; i++) {
			if (total[i]) {
				cnt += 1;
			}
		}
		printf("#%d %d\n", test_case,cnt);
		memset(total, false, sizeof(total));
		memset(ans, 0, sizeof(ans));
	}
	return 0;
}
