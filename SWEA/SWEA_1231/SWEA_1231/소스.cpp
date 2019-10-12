#include <iostream>
#include <memory.h>

using namespace std;

int node[210];
int N;

void dfs(int idx) {
	if (node[idx] == 0) return;
	
	dfs(idx * 2);
	printf("%c", node[idx]);
	dfs(idx * 2 + 1);
}
int main() {
	for (int test_case = 1; test_case <= 10; test_case++){
		scanf("%d", &N);
		memset(node, 0, sizeof(node));
		for (int i = 1; i <= N; i++) {
			char tmp_alpha;
			scanf("%*d %c", &tmp_alpha);
			if (N % 2 == 0 && N / 2 > i || N % 2 == 1 && N / 2 >= i)
			{
				scanf("%*d %*d");
			
			}
			else if (N % 2 == 0 && N / 2 == i) {
				scanf("%*d");
			
			}
			node[i] = tmp_alpha;
		}
		int check = 1;
		printf("#%d ", test_case);
		dfs(1);
		printf("\n");
	}
}