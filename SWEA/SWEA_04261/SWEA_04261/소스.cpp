#include <iostream>
#include <string>
#include <vector>

using namespace std;

char key_pad[8][4] = { {'a','b','c','0'},{'d','e','f','0'},
				 {'g','h','i','0'},{'j','k','l','0'},
				 {'m','n','o','0'},{'p','q','r','s'},
				 {'t','u','v','0'},{'w','x','y','z'} };

int n;
vector<string> word;
int main() {
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++){
		string s,in;
		cin >> s >> n;
		for (int i = 0; i < n; i++) {
			cin >> in;
			word.push_back(in);
		}
		int ans = 0;
		for (int i = 0; i < word.size(); i++) {
			string temp = word[i];
			bool flag = true;
			if (temp.size() != s.size()) continue;
			for (int j = 0; j < temp.size(); j++) {
				int idx = s[j] - '0' - 2;
				bool check = false;
				for (int k = 0; k < 4; k++) {
					if (key_pad[idx][k] == '0') continue;
					if (key_pad[idx][k] == temp[j]) {
						check = true;
						break;
					}
				}
				if (!check) {
					flag = false;
					break;
				}
			
			}
			if (flag) ans++;
		}
		printf("#%d %d\n", test_case, ans);
		word.clear();
	}
	return 0;

}