#include <iostream>
#include <algorithm>

using namespace std;

string s;

bool compare(char a, char b) {
	if (a > b) return true;
	return false;
}
int main() {
	cin >> s;
	long long sum = 0;
	bool zero = false;
	for (int i = 0; i < s.size(); i++) {
		sum += s[i] - '0';
		if (s[i] - '0' == 0) {
			zero = true;
		}
	}
	if (sum % 3 != 0 || !zero) {
		printf("-1\n");
	}
	else {
		sort(s.begin(), s.end(), compare);
		cout << s << "\n";
	}
}