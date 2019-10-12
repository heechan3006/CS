#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 10000001

using namespace std;

int num[MAXN];

int N;
long long total_num = 0;
int ans = 0;
int max_height = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int height;
			cin >> height;
			num[height] += 1;
			max_height = max(height, max_height);
			total_num += height;
		}
	}
	
	long long target = total_num / 2;
	if (total_num % 2 == 1) {
		target += 1;
	}
	long long tmp = total_num;
	
	for (int i = max_height; i > 0; i--) {
		if (tmp < target) {
			ans = i + 1;
			break;
		}
		else if (tmp == target || i == 1) {
			ans = i;
			break;
		}
		tmp -= num[i];
		num[i - 1] += num[i];
	}
	cout << ans << "\n";
	return 0;
}