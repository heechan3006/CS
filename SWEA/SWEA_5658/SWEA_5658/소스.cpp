#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N, K;
string map[28];
void shift(int idx) {
	string tmp_s = "";
	tmp_s += map[idx-1][N - 1];
	for (int i = 0; i < map[idx-1].length()-1; i++) {
		tmp_s += map[idx-1][i];
	}
	map[idx] = tmp_s;
}
int convert(string s) {
	int order = 0;
	int sum = 0;
	int tmp;
	for (int i = s.length()-1; i >= 0;i--){
		if ('A' <= s[i] && s[i] <= 'F') {
			tmp = (int)(s[i] - 'A')+10;
		}
		else if ('0' <= s[i] && s[i] <= '9') {
			tmp = (int)(s[i] - '0');
			
		}
		sum += tmp * pow(16, order);
		order++;
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case=1; test_case<= t; test_case++){
		cin >> N >> K;
		cin >> map[0];
		int idx = N;
		for (int i = 1; i < N; i++) {
			shift(i);
			if (map[0] == map[i]) {
				idx = i-1;
				break;
			}
		}
		vector<string> v;
		for (int i = 0; i < idx; i++) {
			int cnt = 0;
			string tmp = "";
			for (int j = 0; j < N; j++) {
				tmp += map[i][j];
				cnt++;
				if (cnt % (N / 4) == 0) {
					v.push_back(tmp);
					cnt = 0;
					tmp = "";
				}
			}
		}
		sort(v.rbegin(), v.rend());
		v.erase(unique(v.begin(), v.end()), v.end());
		int ans = convert(v[K-1]);
		cout << "#" << test_case<<" "<<ans << "\n";
	}
	return 0;
}