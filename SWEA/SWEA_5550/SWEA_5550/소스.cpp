#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

char check[6] = "croak";
vector<char> v;
int ans = 0;

int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <=t ; test_case++){
		string s;
		int k = 0;
		int cnt = 0;
		int pos = 0;
		bool visited = false;
		bool flag = false;
		cin >> s;
		v.clear();
		for (int i = 0; i < s.size(); i++) {
			v.push_back(s[i]);
		}
		while (!v.empty()) {
			int vsize = v.size();
			k = 0;
			pos = 0;
			visited = false;
			flag = false;
			for (int i = 0; i < vsize - k; i++) {
				if (v[i] == check[pos]) {
					v.erase(v.begin() + i);
					k++;
					i--;
					pos++;
					if (pos == 5) {
						pos = 0;
					}
					visited = true;
				}
			}
			if (pos != 0 || visited == false) {
				flag = true;
				break;
			}
			cnt++;
		}
		if (flag) {
			printf("#%d -1\n",test_case);
		}
		else {
			printf("#%d %d\n", test_case,cnt);
		}
	}
	return 0;
}