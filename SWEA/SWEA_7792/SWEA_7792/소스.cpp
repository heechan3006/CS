#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool alpha[26];
int N;

int main() {
	int t;
	cin >> t;
	for (int test_case = 1; test_case<=t ;test_case++){
		
		cin >> N;
		vector<string> v[21];
		cin.ignore(100, '\n');
		string s;
		for (int i = 0; i < N; i++) {
			memset(alpha, false, sizeof(alpha));
			getline(cin, s);
			int cnt = 0;
			for (int j = 0; j < s.length(); j++) {
				if (s[j] == ' ') continue;
				if (!alpha[s[j]-'A']){
					alpha[s[j] - 'A'] = true;
					cnt++;
				}
			}
			v[cnt].push_back(s);
		}
		int max_cnt = 0;
		for (int i = 0; i < 21; i++) {
			if (!v[i].empty()) max_cnt = i;
		}
		sort(v[max_cnt].begin(), v[max_cnt].end());
		cout <<"#"<< test_case<<" "<< v[max_cnt][0]<< "\n";
	}
	return 0;
}