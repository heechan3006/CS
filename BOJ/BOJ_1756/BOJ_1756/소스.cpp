#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
const int MAXN = 300001;
const int INF = 1e9;

int N, D;
int cur_idx ;
struct node {
	int idx;
	int depth;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> D >> N;
	
	stack<node> s;
	int tmp;
	for (int i = 1; i <= D; i++) {

		cin >> tmp;
		if (!s.empty() && s.top().idx <= tmp) {
			s.top().depth = i;
		}
		else {
			s.push({ tmp,i });
		}
	}
	bool flag = false;
	cur_idx = D;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		while (!s.empty() && tmp > s.top().idx) s.pop();
		if (s.empty()) {
			cout << "0\n";
			return 0;
		}
		s.top().depth = min(s.top().depth, cur_idx) - 1;
		cur_idx = s.top().depth;
		if (s.top().depth == -1) {
			cout << "0\n";
			return 0;
		}

	}
	cout << s.top().depth+1 << "\n";
	return 0;
	
}