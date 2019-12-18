#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5;
struct node {
	string name;
	int x;
	int y;
	int z;
	bool operator < (const node& a) const {
		if (x > a.x) return true;
		if (x == a.x) {
			if (y < a.y) return true;
			if (y == a.y) {
				if (z > a.z) return true;
				if (z == a.z) {
					if (name < a.name) return true;
				}
			}
		}
		return false;
	}
};

node arr[MAXN];

int main() {
	int N;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		int x, y, z;
		cin >> s >> x >> y >> z;
		arr[i] = { s,x,y,z };
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		cout << arr[i].name <<"\n";
	}
	return 0;
}