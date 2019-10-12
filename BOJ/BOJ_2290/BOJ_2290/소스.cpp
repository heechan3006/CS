#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int s;
char map[130][130];
int main() {
	string st;
	
	cin >> s >> st;
	int len = st.length();

	for (int h = 0; h < 2 * s + 3; h++) {
		for (int i = 0; i < len; i++) {
			if (h == 0) {
				if (st[i] == '1' || st[i] == '4') {
					for (int j = 0; j < s + 2; j++) cout << " ";
				}
				else {
					cout << " ";
					for (int j = 0; j < s; j++) {
						cout << "-";
					}
					cout << " ";
				}
			}
			else if (1 <= h && h <= s) {
				if (st[i] == '0' || st[i] == '4' || st[i] == '8' || st[i] == '9') {
					cout << "|";
					for (int j = 0; j < s; j++) {
						cout << " ";
					}
					cout << "|";
				}
				else if (st[i] == '5' || st[i] == '6') {
					cout << "|";
					for (int j = 0; j < s+1; j++) {
						cout << " ";
					}
				}
				else {
					for (int j = 0; j < s+1; j++) {
						cout << " ";
					}
					cout << "|";
				}
			}
			else if (h == s + 1) {
				if (st[i] == '0' || st[i] == '1' || st[i] == '7') {
					for (int j = 0; j < s + 2; j++) {
						cout << " ";
					}
				}
				else {
					cout << " ";
					for (int j = 0; j < s; j++) {
						cout << "-";
					}
					cout << " ";
				}
			}
			else if (s + 2 <= h && h <= 2 * s + 1) {
				if (st[i] == '0' || st[i] == '6' || st[i] == '8') {
					cout << "|";
					for (int j = 0; j < s; j++) cout << " ";
					cout << "|";
				}
				else if (st[i] == '2') {
					cout << "|";
					for (int j = 0; j < s + 1; j++) cout << " ";
				}
				else {
					for (int j = 0; j < s + 1; j++) cout << " ";
					cout << "|";
				}
			}
			else {
				if (st[i] == '1' || st[i] == '4' || st[i] == '7') {
					for (int j = 0; j < s + 2; j++) {
						cout << " ";
					}
				}
				else {
					cout << " ";
					for (int j = 0; j < s; j++) {
						cout << "-";
					}
					cout << " ";
				}
			}
			cout << " ";
		}
		cout << "\n";
	}
	return 0;
}