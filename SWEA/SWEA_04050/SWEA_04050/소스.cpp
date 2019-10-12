#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int n;
int cost[100000];


int main() {
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++){
		cin >> n;
	
		for (int i = 0; i < n; i++) {
			cin >> cost[i];
		}
		sort(cost, cost + n);
		int pay = 0 ;
		for (int i = n - 1; i >= 0; i = i - 3) {
			if (i == 0) pay = pay + cost[i];
			else if (i == 1) pay = pay + cost[i] + cost[i - 1];
			else{
				pay = pay + cost[i] + cost[i - 1];
			}
		}
		memset(cost, 0, sizeof(cost));
		printf("#%d %d\n", test_case, pay);
		//printf("%d\n", pay);
	}
	return 0;
}