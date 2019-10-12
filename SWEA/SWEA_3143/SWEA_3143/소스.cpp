#include <iostream>
#include <cstring>

char A[10001];
char B[101];
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int test_case = 1; test_case<= t; test_case++){
		string a, b;
		cin >> a >> b;
		for (int i = 0; i< a.size(); i++) {
			A[i] = a[i];
		}
		for (int i = 0; i< b.size(); i++) {
			B[i] = b[i];
		}
		int ans = 0;
		int cnt = 0;
		for (int i = 0; i < a.size(); i++) {
			if (A[i] == B[cnt]) {
				if (cnt == b.size()-1) {
					ans++;
					cnt = 0;
					continue;
				}
				cnt++;
			
			}
			else {
				if (A[i] == B[0]) cnt = 1;
				else cnt = 0;
			}
		
		}
		ans = a.size() - ans * b.size() + ans;
		printf("#%d %d\n", test_case,ans);
		//printf("%d\n", ans);
		memset(A, NULL, sizeof(A));
		memset(B, NULL, sizeof(B));
		}
	return 0;
}