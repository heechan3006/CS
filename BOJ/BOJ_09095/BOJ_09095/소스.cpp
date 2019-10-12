#include <iostream>

using namespace std;

int d[11];
int t;
int main() {
	int n;
	cin >> t;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 0; i < t; i++) {
		cin >> n;
		
		for (int i = 4; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		printf("%d\n", d[n]);
	}
	
	return 0;
}