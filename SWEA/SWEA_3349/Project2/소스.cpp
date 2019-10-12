#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int W, H, N;
int sub_x[1000];
int sub_y[1000];

int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {
		scanf("%d %d %d", &W, &H, &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &sub_y[i], &sub_x[i]);
		}
		int cur_x = sub_x[0];
		int cur_y = sub_y[0];
		int sum = 0;
		for (int i = 0; i < N; i++) {
			int dist_x = sub_x[i] - cur_x;
			int dist_y = sub_y[i] - cur_y;
			if (dist_x * dist_y > 0) {
				sum += min(abs(dist_x), abs(dist_y));
				sum += abs(abs(dist_x) - abs(dist_y));
			}
			else {
				sum += abs(dist_x) + abs(dist_y);
			}
			cur_x = sub_x[i];
			cur_y = sub_y[i];
		}
	
		printf("#%d %d\n", test_case, sum);
		memset(sub_x, 0, sizeof(sub_x));
		memset(sub_y, 0, sizeof(sub_y));
		}
	return 0;
}