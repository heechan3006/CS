#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

int a[2],b[2],c[2],d[2];

int main() {
	scanf("%d%d%d%d%d%d%d%d", &a[0], &a[1], &b[0], &b[1], &c[0], &c[1], &d[0], &d[1]);
	double a0 = 0, b0 = 100, ans = 1e9;
	while (b0 - a0 > 1e-9) {
		double ap = (2 * a0 + b0) / 3;
		double bp = (a0 + b0 * 2) / 3;
		double tmp_x1 = a[0] + (b[0] - a[0]) * ap /100;
		double tmp_y1 = a[1] + (b[1] - a[1]) * ap / 100;
		double tmp_x2 = c[0] + (d[0] - c[0]) * ap / 100;
		double tmp_y2 = c[1] + (d[1] - c[1]) * ap / 100;
		double dist_a = (tmp_x2 - tmp_x1) * (tmp_x2 - tmp_x1) + (tmp_y2 - tmp_y1) * (tmp_y2 - tmp_y1);
		
		tmp_x1 = a[0] + (b[0] - a[0]) * bp / 100;
		tmp_y1 = a[1] + (b[1] - a[1]) * bp / 100;
		tmp_x2 = c[0] + (d[0] - c[0]) * bp / 100;
		tmp_y2 = c[1] + (d[1] - c[1]) * bp / 100;
		double dist_b = (tmp_x2 - tmp_x1) * (tmp_x2 - tmp_x1) + (tmp_y2 - tmp_y1) * (tmp_y2 - tmp_y1);
		
		if (dist_a < dist_b) {
			b0 = bp;
			if (ans > dist_a) {
				ans = dist_a;;
			}
		}
		
		else {
			a0 = ap;
			if (ans > dist_b) ans = dist_b;
		}
	}
	printf("%.10lf", sqrt(ans));
	return 0;
}