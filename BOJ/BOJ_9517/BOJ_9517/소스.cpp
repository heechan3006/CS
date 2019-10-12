#include <iostream>
#include <vector>

using namespace std;

int N, idx;

int main() {
	cin >> idx;
	cin >> N;
	int time = 0;
	vector<pair<int, char>> v;
	for (int i = 0; i < N; i++) {
		int tmp_t;
		char tmp_ans;
		cin >> tmp_t >> tmp_ans;
		v.push_back({ tmp_t,tmp_ans });
	}
	int len = v.size();
	int cnt = 0;
	
	while (1){
		int next_t = v[cnt].first;
		char next_ans = v[cnt].second;
		time += next_t;
		if (time > 210) break;
		if (next_ans == 'T') {
			idx++;
			if (idx > 8) idx = 1;
		}
		cnt++;
		if (cnt > len) cnt = 0;
	}
	cout << idx << "\n";
}