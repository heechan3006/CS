#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
char arr[100005];
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case<=t; test_case++){
		scanf("%s", &arr);
		int len = strlen(arr);
		int cnt = 0;
		int check = 0;
		int ans = 0;
		for (int i = 0; i < len; i++) {
			if (arr[i] == '(') {
				cnt++;
				check = 1;
			}
			else if (arr[i] == ')' && check == 1) {
				cnt--;
				ans += cnt;
				check = 0;
			}
			else {
				cnt--;
				ans += 1;
				check = 0;
			}

		}
		printf("#%d %d\n", test_case,ans);
	}
	return 0;
}