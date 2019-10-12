#include <iostream>
#include <algorithm>
#define MAXN 1000
using namespace std;

int sx = -1, sy;
int N, M;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			cin >> tmp;
			if (tmp) {
				if (sx == -1) {
					sx = i, sy = j;
				}
				else {
					cout << abs(i - sx) + abs(j - sy) ;
					return 0;
				}
			}
		}
	}
}
