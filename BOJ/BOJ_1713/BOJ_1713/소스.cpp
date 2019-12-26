#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAXN 20
using namespace std;

int cost[MAXN];
struct node {
	int idx;
	int cnt;
	int time;
	bool operator < (const node& a) const {
		if (a.cnt <= cnt) {
			if (a.cnt == cnt) {
				if (a.time < time) return true;
				return false;
			}
			return true;
		}
		return false;
	}
};
int N,M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	vector<node> v;
	
	for (int time = 0; time < M; time++){
		int num;
		cin >> num;
		bool flag = false;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].idx == num) {
				flag = true;
				v[i].cnt++;
				break;
			}
		}
		if (v.size()==N) {			
			if (!flag) {
				sort(v.begin(), v.end());
				v.pop_back();
			}
		}
		
		if (!flag) {
			v.push_back({ num,1,time });
		}
	
	}
	vector<int> ans;
	for (int i = 0; i < v.size(); i++) {
		ans.push_back(v[i].idx);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}