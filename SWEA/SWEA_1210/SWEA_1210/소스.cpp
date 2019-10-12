#include <iostream>
#include <cstring>

using namespace std;

int map[102][102];

int main() {
	int t;
	int x, y;
	//freopen("input.txt", "r", stdin);
	for (int test_case = 1; test_case <= 10; test_case++) {
		scanf("%d", &t);
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				scanf(" %1d", &map[i][j]);
				if (map[i][j] == 2) {
					x = i;
					y = j;
				}
			}
		}

		for (int i = 99; i >= 0; i--) {
			if (map[i][y + 1] == 1) {
				while (1) {
					y++;
					if (map[i][y + 1] != 1) {
						break;
					}
				}
			}
			else if (map[i][y - 1] == 1) {
				while (1) {
					y--;
					if (map[i][y - 1] != 1)
						break;
				}
			}
		}
		printf("#%d %d\n", t,y - 1);
	}
	return 0;
	
}