#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
//숫자 48 ~ 57
//대문자 65~90
//소문자 97~122
//공백 32
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		cin >> N;
		cin.ignore(2,'\n');
		string s;
		getline(cin, s);
		int cnt = 0;
		bool flag = false;
		bool possible = true;
		vector<string> v[5];
		cout << "#" << test_case << " ";
		string tmp_s = "";
		int idx = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				v[idx].push_back(tmp_s);
				tmp_s = "";
				continue;
			}
			if (s[i] == '.' || s[i] == '?' || s[i] == '!') {
				v[idx].push_back(tmp_s);
				tmp_s = "";
				idx++;
				i++;
				continue;
			}
			tmp_s += s[i];

		}
		
		for (int i = 0; i <N; i++) {
			int cnt = 0;
			
			for (int j = 0; j < v[i].size(); j++) {
				bool flag = false;
				if ('A' > v[i][j][0] || v[i][j][0] > 'Z') continue;
				if (v[i][j].size() == 1) {
					cnt++;
					continue;
				}
				else {
					for (int k = 1; k < v[i][j].length(); k++) {
						if ('a' > v[i][j][k] || v[i][j][k] > 'z') {
							flag = true;
							break;
						}

					}
					if (!flag) cnt++;
				}
				
			}
			cout << cnt << " ";
		}
		cout << "\n";
		
	}
	return 0;
}