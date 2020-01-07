#include <stdio.h>

using namespace std;
#define MAXN 1000

int N, A, B;

int num[MAXN];
int ans[MAXN];
int ans_cnt;
int q[MAXN];
int q_head;
int q_tail;
void empty(int& time) {

	int size = q_tail - q_head;
	if (size % 2) size = size / 2 + 1;
	else size = size / 2;
	while (size--) {
		q_head++;
		ans[ans_cnt++] = time;
	}
}
int main() {

	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {
		ans_cnt = 0;
		q_head = 0;
		q_tail = 0;
		scanf("%d%d%d", &N, &A, &B);
		for (int i = 0; i < N; i++) {
			scanf("%d", &num[i]);
		}
		int idx = 0;
		int time = 0;
		
		while (ans_cnt<N) {
			if (idx <= N && num[idx] == time) {
				q[q_tail++] = num[idx++];
			}
			if (q_tail - q_head>0) {
				if (q_tail - q_head >= A || time - q[q_head] == B) empty(time);
			}
			time++;
		}
		printf("#%d ", test_case);
		for (int i = 0; i < N; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}