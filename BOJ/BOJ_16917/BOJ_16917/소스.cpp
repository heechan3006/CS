#include <iostream>
#include <algorithm>
using namespace std;

int A, B, C, X, Y;

int main() {
	cin >> A >> B >> C >> X >> Y;
	int min_v = min(X, Y);
	int max_v = max(X, Y);
	int ans = min(A + B, 2 * C)* min_v;
	int tmp_ans = ans;
	if (X > Y) {
		int tmp_min_v = X - min_v;
		tmp_ans += A * tmp_min_v;
	}
	else if (X < Y) {
		int tmp_min_v = Y - min_v;
		tmp_ans += B * tmp_min_v;
	}
	ans = min(ans + (max_v-min_v)*2*C, tmp_ans);
	printf("%d\n", ans);
	return 0;
	
}