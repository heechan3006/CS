#include <iostream>
using namespace std;
string reverse(string::iterator& it) {
	char head = *it;
	++it;
	if (head == 'b' || head == 'w') {
		return string(1, head);
	}
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	string s = string(2, 'wwb');
	
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		string::iterator it = s.begin();
		cout << reverse(it) <<'\n';
	}
	
	return 0;
}