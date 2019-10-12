#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAXN 100001

using namespace std;
int N;
int map[MAXN];


int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <=t; test_case++){
		scanf("%d", &N);
		string ans;
		int idx = 0;
		int tmp, n = 1;
		bool possible = true;
		for (int i = 0; i < N; i++) {
			scanf("%d", &tmp);
			if (!possible) continue;
			while (1) {
				if (idx != 0 && tmp == map[idx - 1]) {
					idx--;
					ans += '-';
					break;
				}
				else {
					if (n > N) { 
						possible = false;
						break; 
					}
					map[idx] = n;
					idx++;
					n++;
					ans += '+';
				
				}
			}
		}
		if (possible) cout << "#"<< test_case<<" "<<ans << "\n";
		else cout << "#"<< test_case<<" NO\n";
	
	}
	return 0;
}

