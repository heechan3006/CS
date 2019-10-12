#include <iostream>

using namespace std;

int N;
int ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int cnt_five = 0;
	ans = 5000;
	bool flag = false;
	while (cnt_five * 5 <= N) {
		if ((N - cnt_five * 5) % 3 == 0) {
			flag = true;
			int tmp = cnt_five + (N - cnt_five * 5) / 3;
			if (ans > tmp) ans = tmp;
		}
		cnt_five++;
	}
	if (flag) cout << ans << "\n";
	else cout << "-1\n";
	return 0;
}