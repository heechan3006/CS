#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> v;
int main() {
	cin >> N;
	int tmp_s, tmp_e;
	for (int i = 0; i < N; i++) {
		cin >> tmp_s >> tmp_e;
		v.push_back({ tmp_e,tmp_s });
	}
	sort(v.begin(), v.end());
	int cnt = 1;
	int S = v[0].second;
	int E = v[0].first;
	for (int i = 1; i < N; i++) {
		if (v[i].second >= E) {
			S = v[i].second;
			E = v[i].first;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}