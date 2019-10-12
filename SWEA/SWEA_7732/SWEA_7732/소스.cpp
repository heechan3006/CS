#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test_case = 1; test_case <=t; test_case++){
		vector<int> v[2];
		string s1, s2;
		cin >> s1;
		cin >> s2;
	
	
		int num_1 = 0;
		int num_2 = 0;
		int order = 10;
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] == ':') {
			
				v[0].push_back(num_1);
				v[1].push_back(num_2);
				order = 10;
				num_1 = 0;
				num_2 = 0;
				continue;
			}
			num_1 += (int)(s1[i]-'0');
			num_2 += (int)(s2[i]-'0');
			num_1 *= order;
			num_2 *= order;
			order /= 10;
			if (i==s1.length()-1) {

				v[0].push_back(num_1);
				v[1].push_back(num_2);
				order = 10;
				num_1 = 0;
				num_2 = 0;
				continue;
			}
		}
		
		int total_num_1 = 0;
		int total_num_2 = 0;
		int cnt = 3600;
		for (int i = 0; i < v[0].size(); i++) {
			total_num_1 += cnt * v[0][i];
			total_num_2 += cnt * v[1][i];
			cnt /= 60;
		}
		if (total_num_1 > total_num_2) total_num_2 += 24 * 3600;
		cnt = 3600;
		int total = abs(total_num_1 - total_num_2);
		printf("#%d ", test_case);
		for (int i = 0; i < 3; i++) {
			int time = total / cnt;
			total = total % cnt;
			cnt /= 60;
			printf("%02d", time);
			if (i == 2) break;
			printf(":");
		}
		printf("\n");
	}
	return 0;
}