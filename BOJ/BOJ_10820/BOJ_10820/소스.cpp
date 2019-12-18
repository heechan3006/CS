#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	char s[101];
	while (cin.getline(s,sizeof(s))) {
		int num[4] = { 0, };
		for (int i = 0; i < 101; i++) {
			if (s[i] == '\0') break;
			if (s[i] >= 'a' && s[i] <= 'z') num[0]++;
			else if (s[i] >= 'A' && s[i] <= 'Z') num[1]++;
			else if (s[i] >= '0' && s[i] <= '9') num[2]++;
			else num[3]++;
		}
		for (int i = 0; i < 4; i++) {
			cout << num[i] << " ";
		}
		cout << "\n";
		memset(s, '\0', sizeof(s));
	}
	return 0;
}