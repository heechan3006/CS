#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool broken[10];
int possible(int c) {
	int len = 0;
	if (c == 0) {
		if (broken[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}
	while (c > 0) {
		if (broken[c % 10] == true) {
			return 0;
		}
		c /= 10;
		len++;
	}
	return len;
}
int main() {
	int n,num_broken;
	cin >> n;
	cin >> num_broken;
	
	for (int i = 0; i < num_broken; i++) {
		int x;
		cin >> x;
		broken[x] = true;
	}
	int ans = abs(n - 100);
	
	for (int i = 0; i < 1000000; i++) {
		int c = i;
		int len = possible(c);
		if (len > 0) {
			int press = abs(c - n);
			
			if (ans > press + len) {
				ans = press + len;
			}
		}
		
	}
	cout << ans << "\n";
	return 0;
}