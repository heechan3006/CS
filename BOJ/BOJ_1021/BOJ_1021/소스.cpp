#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> v;
vector<int> num;
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 1; i <= N; i++) {
		num.push_back(i);
	}
	int ans = 0;
	int cnt = 0;
	while (cnt < M) {
		vector<int> tmp_v;
		int t = v[cnt];
		int max_v = 0;
		int idx = 0;
		for (int i = 0; i < num.size(); i++) {
			if (num[i] == t) {
				idx = i;
				max_v = min(i, (int)(num.size() - i));
				break;
			}
		}
		for (int i = idx+1; i < num.size(); i++) {
			tmp_v.push_back(num[i]);
		}
		for (int i = 0; i < idx; i++) {
			tmp_v.push_back(num[i]);
		}
		num.clear();
		for (int i = 0; i < tmp_v.size(); i++) {
			num.push_back(tmp_v[i]);
		}
		
		cnt++;
		ans += max_v;
	}
	cout << ans << "\n";
}