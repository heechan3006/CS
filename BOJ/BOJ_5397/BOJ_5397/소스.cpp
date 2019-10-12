#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int idx = 0;
		string ans = "";
		stack<char> result;
		stack<char> temp;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '<') {
				if (!result.empty()) {
					temp.push(result.top());
					result.pop();
				}
			}
			else if (s[i] == '>') {
				if (!temp.empty()) {
					result.push(temp.top());
					temp.pop();
				}
			}
			
			else if (s[i] == '-') {
				if (!result.empty()) {
					result.pop();
				}
			}
			else {
				result.push(s[i]);
			}
		
		}
		while (!temp.empty()) {
			result.push(temp.top());
			temp.pop();
		}
		while (!result.empty()) {
			ans += result.top();
			result.pop();
		}
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}
}