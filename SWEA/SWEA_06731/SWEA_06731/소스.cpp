#include <iostream>
#include <cstring>

using namespace std;

int N;
char map[1001][1001];
int horizontal[1000];
int vertical[1000];

int main() {
	int t;
	scanf("%d",&t);
	for (int test_case=1; test_case<=t; test_case++){
		scanf("%d",&N);
		while (getchar() != '\n');
		for (int i = 0; i < N; i++) {
			scanf("%s", map[i]);
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 'B') {
					horizontal[i]++;
					vertical[j]++;
				}
			}
		}
		
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0 ; j < N; j++){
				int sum = horizontal[i] + vertical[j];
				if (map[i][j] == 'B') sum--;
				if (sum % 2) cnt++;
			}
		}
		printf("#%d %d\n", test_case,cnt);
		memset(map, 0, sizeof(map));
		memset(horizontal, 0, sizeof(horizontal));
		memset(vertical, 0, sizeof(vertical));
	}
	return 0;
}