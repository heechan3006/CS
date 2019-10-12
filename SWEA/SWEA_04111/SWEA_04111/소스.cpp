#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int camera[10001];
int n;
int k;
int main() {
	multiset<int> s;
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		cin >> camera[i];
	}
	sort(camera, camera + n);
	int answer = 0;
	for (int i = 0; i < n - 1; i++) {
		s.insert(camera[i + 1] - camera[i]);
	}
	int size = s.size();
	auto it = s.begin();
	for (int i = 0; i < size - (k - 1); i++) {
		answer += (*it);
		it++;
	}
	cout << answer;
	return 0;
}