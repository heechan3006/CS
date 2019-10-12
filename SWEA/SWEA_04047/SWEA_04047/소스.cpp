#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int card[4][13];
int ans[4];
int main() {
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++){
		string	s;
		cin >> s;
		
		char tmp;
		int tmp_num;
		int tmp_cnt;
		for (int i = 0; i < s.size(); i = i + 3) {
			tmp = s[i];
			tmp_num = (int)((s[i+1]-'0')*10 + s[i+2]-'0');
			if (tmp == 'S') tmp_cnt = 0;
			else if (tmp == 'D') tmp_cnt = 1;
			else if (tmp == 'H') tmp_cnt = 2;
			else tmp_cnt = 3;
			card[tmp_cnt][tmp_num] += 1;
		}
		
		bool possible = true;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				if (card[i][j] == 1) ans[i] += 1;
				else if (card[i][j] > 1) {
					possible = false;
					break;
				}
			}
			if (!possible) break;
		}
		if (possible){
			printf("#%d %d %d %d %d\n", test_case,13-ans[0], 13-ans[1], 13-ans[2], 13-ans[3]);
		}
		else {
			printf("#%d ERROR\n",test_case);
		}
		memset(card, 0, sizeof(card));
		memset(ans, 0, sizeof(ans));
	}
	return 0;
	
}