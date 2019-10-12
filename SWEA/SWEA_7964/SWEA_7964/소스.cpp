#include <iostream>
#include <cstring>
#define MAXN 300000 + 2

using namespace std;

int map[MAXN];
int N, D;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test_case= 1; test_case<= t;test_case++){
		memset(map, 0, sizeof(map));
		cin >> N >> D;
		map[0] = 1;
		map[N + 1] = 1;
		int d = 0;
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			cin >> map[i];
			d++;
			if (map[i] == 1 && d <= D) {
				d = 0;	
			}
			else if (map[i] == 0 && d == D) {
				ans++;
				d = 0;
			}
		}
		cout << "#" << test_case<< " "<<ans << "\n";
	}
	return 0;
}
