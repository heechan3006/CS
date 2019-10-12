#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

int N;

int map[300][300];
int dist[200];

int dx[] = { -1,0,1,-1,0,1 };
int dy[] = { -1,-1,-1,1,1,1 };
int A, B;

int main() {
	int t;
	int ax, ay, bx, by;
	int sum = 1;
	for (int i = 1; i <= 150; i++) {
		dist[i] = sum;
		sum += i;
	}
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {

		scanf("%d %d", &A, &B);

		for (int i = 1; i <= 145; i++) {
			if (dist[i] > A) {
				ax = i - 1;
				break;
			}
		}
		for (int i = 1; i <= 145; i++) {
			if (dist[i] > B) {
				bx = i - 1;
				break;
			}
		}
		ay = A - dist[ax];
		by = B - dist[bx];
		int diff_x = abs(ax - bx);
		int diff_y = abs(ay - by);

		int num = 0;
		if ((ax < bx && ay > by) || (ax > bx && ay < by)) {
			num = min(diff_x, diff_y);
		}
		printf("#%d ", test_case);
		if (diff_x < diff_y) printf("%d\n", diff_y + num);
		else printf("%d\n", diff_x + num);
	}
	return 0;
}