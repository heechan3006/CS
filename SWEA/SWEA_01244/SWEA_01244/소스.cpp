#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;


int d[1000000];
int k;
int ans;
void go(string n, int cnt) {
	int now = stoi(n);
	if (d[cnt] > now) {
		return;
	}
	else {
		d[cnt] = now;
	}
	if (cnt == k) {
		if (now > ans) {
			ans = now;
			
		}
		return;
	}
	for (int i = 0; i < n.size(); i++) {
		for (int j = 1 + i; j < n.size(); j++) {
			string tmp = n;
			swap(tmp[i], tmp[j]);
			go(tmp, cnt + 1);
			
		}
	}
	
}

int main() {
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case ++){
		string s;
		cin >> s >> k;
		memset(d, -1, sizeof(d));
		ans = 0;
		go(s, 0);
		printf("#%d %d\n", test_case, ans);
		//printf("%d\n", ans);
		
		
	}
	
	return 0;
		
}