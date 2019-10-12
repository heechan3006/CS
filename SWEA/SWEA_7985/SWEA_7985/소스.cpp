#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAXN 1024
using namespace std;

int map[MAXN];
vector<int> v[11];
int K;
void dfs(int low, int high, int level) {
	if (low > high) return;
	int mid = (low + high) / 2;
	v[level].push_back(map[mid]);
	dfs(low, mid - 1, level + 1);
	dfs(mid + 1, high, level + 1);
	
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case=1; test_case<=t; test_case++){
		for (int i = 0; i < 11; i++) v[i].clear();
		scanf("%d", &K);
	
		for (int i = 0; i < (1 << K)-1; i++) {
			scanf("%d", &map[i]);
		}
		dfs(0,(1<<K)-2,1);
		printf("#%d ", test_case);
		for (int i = 1; i <= K; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				printf("%d ", v[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}