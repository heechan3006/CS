#include <iostream>
#include <memory.h>

using namespace std;

int map[102][102];
int dist = 0;
int ans;

int main() {
	//freopen("input.txt", "r", stdin);
	int t;
	for (int test_case = 1; test_case<=10; test_case++){
		scanf("%d", &t);
		memset(map, 0, sizeof(map));
		for (int i = 0; i < 100; i++) {
			for (int j = 1; j<= 100; j++){
				scanf("%1d",&map[i][j]);
			}
		}
		int y;
		ans = 10e5;
		int location= 0;
		for (int j = 1; j <= 100; j++){
			if (!map[0][j]) continue;
			dist =	1;
			y = j;
			for (int i = 0; i< 100; i++) {
				if (map[i][y - 1]) {
					while (1) {
						y--;
						dist++;
						if (!map[i][y-1]) break;
					}
				}
				else if (map[i][y + 1]) {
					while (1) {
						y++;
						dist++;
						if (!map[i][y + 1]) break;
					}
				}
				else {
					dist++;
				}
			}
			if (ans > dist) {
				location = j - 1;
				ans = dist;
			}
		}
		//printf("%d\n", location);
		printf("#%d %d\n", test_case,location);
	}
	return 0;
}
