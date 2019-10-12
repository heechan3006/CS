#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int map[1005][1005];

int main() {
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++){
		cin >> m >> n;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++) {
			
				if (map[i][j] == 0) {
					map[i + 2][j] = 1;
					map[i][j + 2] = 1;
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) cnt++;
			}
		}
		printf("#%d %d\n", test_case, cnt);
	}
	return 0;
}