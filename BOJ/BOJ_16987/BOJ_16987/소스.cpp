#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int s;
	int w;
};
node egg[8];
bool check[8];
int N;
int ans = 0;
int chk() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (egg[i].s <= 0) cnt++;
	}
	return cnt;
}
void solve(int idx) {
	if (idx == N) {
		ans = max(ans, chk());
		return;
	}
	if (egg[idx].s <= 0) {
		solve(idx + 1);
		return;
	}
	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (idx == i || egg[i].s <= 0) continue;
		egg[i].s -= egg[idx].w;
		egg[idx].s -= egg[i].w;
		flag = true;
		solve(idx + 1);
		egg[i].s += egg[idx].w;
		egg[idx].s += egg[i].w;
	}
	if (!flag) solve(idx + 1);
}
int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> egg[i].s >> egg[i].w;
	}
	
	solve(0);
	printf("%d", ans);
}