#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1000;
int map[MAXN][100];
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	
	for (int i = 0; i < N ; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	bool pos =  false;
	bool pos1 = false;
	
	for (int j = 0; j < M && !pos; j++) {
		bool flag = false;
		for (int i = 0; i < N; i++) {
			if (!flag && map[i][j] == 0) {
				flag = true;
				continue;
			}
			if (flag && map[i][j]) {
				pos = true;
				break;
			}
		}
	}
	for (int j = 0; j < M && !pos1; j++) {
		for (int i = N - 1; i >= 0; i--) {
			bool flag1 = false;
			if (!flag1 && map[i][j] == 0) {
				flag1 = true;
				continue;
			}
			if (!flag1 && map[i][j]) {
				pos1 = true;
				break;
			}
		}		
	}
	if (pos && pos1) {
		printf("NO");
		return 0;
	}

	printf("YES");
	return 0;
	
}
