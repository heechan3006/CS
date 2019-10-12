#include <iostream>
#include <deque>

using namespace std;

int L1[] = { 1,4,7,10,13,16,19,22,25,54,51,48 };
int L2[] = { 34,31,28,29,30,33,36,35 };
int R1[] = { 27,24,21,18,15,12,9,6,3,46,49,52 };
int R2[] = { 43,40,37,38,39,42,45,44 };
int F1[] = { 34,35,36,16,17,18,43,44,45,52,53,54 };
int F2[] = { 19,20,21,24,27,26,25,22 };
int B1[] = { 48,47,46,39,38,37,12,11,10,30,29,28 };
int B2[] = { 9,8,7,4,1,2,3,6 };
int U1[] = { 36,37,30,7,8,9,37,40,43,21,20,19 };
int U2[] = { 10,11,12,15,18,17,16,13 };
int D1[] = { 45,42,39,3,2,1,28,31,34,25,26,27 };
int D2[] = { 46,47,48,51,54,53,52,49 };

char color[] = { 'o','w','r','g','b','y' };
char map[55];
char map2[55];
int T, N;
void rotate_cube(deque<int> q, deque<int> q1, int which[], int rot[],int dir) {
	for (int i = 0; i < 12; i++) {
		q.push_back(which[i]);
	}
	for (int i = 0; i < 8; i++) {
		q1.push_back(rot[i]);
	}
	if (dir == 1) {
		for (int i = 0; i < 3; i++) {
			int x = q.back();
			q.pop_back();
			q.push_front(x);
		}
		for (int i = 0; i < 2; i++) {
			int x = q1.back();
			q1.pop_back();
			q1.push_front(x);
		}
		
	}
	else {
		for (int i = 0; i < 3; i++) {
			int x = q.front();
			q.pop_front();
			q.push_back(x);
		}
		for (int i = 0; i < 2; i++) {
			int x = q1.front();
			q1.pop_front();
			q1.push_back(x);
		}
	}
	int q_size = q.size();
	int q1_size = q1.size();
	for (int i = 0; i < q_size; i++) {
		int idx = q.front();
		map[which[i]] = map2[idx];
		q.pop_front();
	}
	for (int i = 0; i < q1_size; i++) {
		int idx = q1.front();
		map[rot[i]] = map2[idx];
		q1.pop_front();
	}
}
void solve(string s) {
	char which = s[0];
	char rot = s[1];
	deque<int> q;
	deque<int> q1;
	if (which == 'L') {
		if (rot == '+'){
			rotate_cube(q, q1,L1,L2,1);
		}
		else {
			rotate_cube(q, q1, L1, L2, 0);
		}
	}
	else if (which == 'R') {
		if (rot == '+') {
			rotate_cube(q, q1, R1, R2, 1);
		}
		else {
			rotate_cube(q, q1, R1, R2, 0);
		}
	}

	else if (which == 'F') {
		if (rot == '+') {
			rotate_cube(q, q1, F1, F2, 1);
		}
		else {
			rotate_cube(q, q1, F1, F2, 0);
		}
	}
	else if (which == 'B') {
		if (rot == '+') {
			rotate_cube(q, q1, B1, B2, 1);
		}
		else {
			rotate_cube(q, q1, B1, B2, 0);
		}
	}
	else if (which == 'U') {
		if (rot == '+') {
			rotate_cube(q, q1, U1, U2, 1);
		}
		else {
			rotate_cube(q, q1, U1, U2, 0);
		}
	}
	else if (which == 'D') {
		if (rot == '+') {
			rotate_cube(q, q1, D1, D2, 1);
		}
		else {
			rotate_cube(q, q1, D1, D2, 0);
		}
	}
}
int main() {
	
	cin >> T;
	while (T--) {
		int cnt = 0;
		int cnt1 = 0;
		for (int i = 1; i <= 54; i++) {
			map[i] = color[cnt1];
			map2[i] = color[cnt1];
			cnt++;
			if (cnt % 9 == 0) cnt1++;
		}
		cin >> N;
		for (int i = 0; i < N ; i++){
			string s;
			cin >> s;
			solve(s);
			for (int i = 1; i <= 54; i++) {
				map2[i] = map[i];
			}
		}
		int count = 0;
		for (int i = 10; i < 19; i++) {
			printf("%c", map[i]);
			count++;
			if (count % 3 == 0) printf("\n");
		}
	}
}
