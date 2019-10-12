#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//char map[10][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int max_h = 0;
	int max_w = 0;
	for (max_h = 1; s.size() % max_h != 0 || max_h < s.size() / max_h; max_h++);
	max_w = s.size() / max_h;
	int idx = 0;
	int w = 0;
	int h = 0;
	vector<vector<char>> map;
	map.resize(max_h, vector<char>(max_w, ' '));
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++) {
			map[i][j] = s[idx++];
		}
	}
	
	string ans = "";
	for (int j = 0; j < map[0].size(); j++) {
		for (int i = 0; i < map.size(); i++) {
			ans += map[i][j];
		}
	}
	cout << ans << "\n";
	return 0;
}