#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	stack<pair<char,int> > st;
	bool flag = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '[') {
			st.push({ s[i],-1});
		}
		else {
			if (s[i] == ')') {
				
				int sum = 0;
				while (st.size()) {
					if (st.top().first != 'n' && st.top().first == '[') {
						printf("0");
						return 0;
					}
					if (st.top().first == '(') {
						st.top().first = 'n';
						if (sum == 0) sum = 1;
						st.top().second = sum * 2;
						break;
					}
					sum += st.top().second;
					st.pop();
				}
				
			}
			else if (s[i] == ']') {
				int sum = 0;
				while (st.size()) {
					if (st.top().first != 'n' && st.top().first == '(') {
						printf("0");
						return 0;
					}
					if (st.top().first == '[') {
						st.top().first = 'n';
						if (sum == 0) sum = 1;
						st.top().second = sum * 3;
						break;
					}
					sum += st.top().second;
					st.pop();
				}
			}
		}
	}
	int ans = 0;
	while (st.size()) {
		if (st.top().first != 'n') {
			printf("0");
			return 0;
		}
		ans += st.top().second;
		st.pop();
	}
	printf("%d", ans);
	return 0;
}
