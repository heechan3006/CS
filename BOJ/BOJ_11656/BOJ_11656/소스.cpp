#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
vector<string> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		v.push_back(s.substr(i));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}
