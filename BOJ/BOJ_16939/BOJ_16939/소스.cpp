#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int xz[] = { 1,3,5,7,9,11,22,20 };
int yz[] = { 14,15,6,7,18,19,22,23 };
int xy[] = { 2,3,16,18,9,8,15,13 };
vector<int> v;
bool check_color(vector<int> v) {
	int value;
	for (int i = 0; i < v.size(); i++) {
		if (i % 4 == 0) value = v[i];
		if (v[i] != value) return false;
	}
	return true;
}
bool check(int x[],vector<int> v, int dir) {
	deque<int> q;
	for (int i = 0; i < 8; i++) {
		q.push_back(v[x[i]]);
	}
	//시계방향
	if (dir == 0){
		for (int i = 0; i < 2; i++) {
			int tmp = q.back();
			q.pop_back();
			q.push_front(tmp);
		}
	}
	//반시계
	else {
		for (int i = 0; i < 2; i++) {
			int tmp = q.front();
			q.pop_front();
			q.push_back(tmp);
		}
	}
	int len = q.size();
	for (int i = 0; i < len; i++) {
		int color = q.front();
		v[x[i]] = color;
		q.pop_front();
	}
	if (check_color(v)) return true;
	return false;
}
int main() {
	int tmp;
	for (int i = 0; i < 24; i++) {
		cin >> tmp;
		v.push_back({ tmp });
	}
	
	if (check(xz, v, 0) || check(xz, v, 1) || check(yz, v, 0) || check(yz, v, 1) || check(xy, v, 0) || check(xy, v, 1)) {
		printf("1");
		return 0;
	};
	printf("0");
	return 0;
}