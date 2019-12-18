#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 50;
int N;
string W,S;
int cache[101][101];
vector<string> v;

bool match1(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1) return ret;
	if (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		return ret = match1(w + 1, s + 1);
	}
	if (w == W.size()) return ret = (s == S.size());
	if (W[w] == '*') {
		if (match1(w+1,s) || (s < S.size() && match1(w,s+1))) return ret = 1;
	}
	return ret = 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		v.clear();
		cin >> W;
		cin >> N;

		for (int i = 0; i < N; i++) {
			memset(cache, -1, sizeof(cache));
			cin >> S;
			if (match1(0, 0)) {
				v.push_back(S);
			}
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << "\n";

		}
	}
	
	
}