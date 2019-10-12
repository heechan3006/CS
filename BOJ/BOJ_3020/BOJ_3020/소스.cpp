#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAXN 200000
#define MAXH 500000
using namespace std;

int N, H;

int main() {
	scanf("%d%d", &N, &H);
	vector<int> Bottom(N/2);
	vector<int> Top(N/2);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (i % 2 == 0) {
			Bottom[i / 2] = tmp;
		}
		else {
			Top[i / 2] = tmp;
		}
	}
	sort(Bottom.begin(), Bottom.end());
	sort(Top.begin(), Top.end());
	int res = 987654321;
	int cnt;
	for (int i = 1; i <= H; i++) {
		int tmp = Bottom.size() - (lower_bound(Bottom.begin(), Bottom.end(), i)-Bottom.begin());
		tmp += Top.size() - (upper_bound(Top.begin(), Top.end(), H - i) - Top.begin());
		if (res > tmp) {
			res = tmp;
			cnt = 1;
		}
		else if (res == tmp) {
			cnt++;
		}
	}
	printf("%d %d\n", res, cnt);
	return 0;
}

