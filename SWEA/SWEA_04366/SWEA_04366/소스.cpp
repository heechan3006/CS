#include <iostream>
#include <math.h>

using namespace std;

string bi, tri;

void get_tri_from_dec(const int dec, string &s) {
	if (dec < 3) {
		s += dec;
		return;
	}
	get_tri_from_dec(dec / 3, s);
	s += dec % 3;
}
int get_dec_from_bi(string s) {
	int dec = 0;
	int power = 1;
	for (int i = s.size() - 1; i >= 0; i--, power*=2) {
		dec += (s[i] - '0') * power;
	}
	return dec;
}
int get_dec_from_tri(string s) {
	int dec = 0;
	int power = 1;
	for (int i = s.size() - 1; i >= 0; i--, power *= 3) {
		dec += (s[i] - '0') * power;
	}
	return dec;
}
int main() {
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++){
		cin >> bi;
		cin >> tri;
	
		for (int i = 0; i < bi.size(); i++) {
			int tmp = bi[i];
			if (bi[i] == '0') {
				bi[i] = '1';
			}
			else bi[i] = '0';
			int dec_bi = get_dec_from_bi(bi);
			int dec_tri = get_dec_from_tri(tri);
			bi[i] = tmp;
			int diff = abs(dec_bi - dec_tri);
			string str_tri;
			get_tri_from_dec(diff, str_tri);
			int cnt = 0;
			for (char c : str_tri) {
				if (c != '\0') cnt++;
			}
			if (cnt == 1) {
				printf("#%d %d\n", test_case,dec_bi);
				break;
			}
		}
	}
}