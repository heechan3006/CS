#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 1000

using namespace std;
struct node {
	int d;
	int w;
	bool operator < (const node& a) const {
		if (w > a.w) return true;
		return false;
	}
};
vector<node> v;
bool visited[MAXN];
int last_day = 0;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int d, w;
		cin >> d >> w;
		v.push_back({ d,w });
		last_day = max(last_day, d);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int day = last_day; day >= 1; day--) {
		for (int i = 0; i < v.size(); i++) {
			if (!visited[i] && v[i].d >= day) {
				ans += v[i].w;
				visited[i] = true;
				break;
			}
		}
	}
	
	cout << ans<<"\n";
	return 0;
}