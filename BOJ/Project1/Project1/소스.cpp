#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> rocks = { 2, 14, 11, 21, 17 };

int n = 2;
bool is_possible(vector<int> rocks, int n, int min_dist) {
	int cnt = 0;
	int s = 0;
	int e = 1;
	while (e < rocks.size()) {
		
		if (rocks[e] - rocks[s] < min_dist) {
			cnt++;
			e++;
		}
		else {
			s = e;
			e++;
		}
	}
	return cnt <= n;
}
int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	sort(rocks.begin(), rocks.end());
	vector<int> tmp(rocks.size() + 2, 0);
	for (int i = 1; i <= rocks.size(); i++) {
		tmp[i] = rocks[i - 1];
	}
	tmp[tmp.size() - 1] = distance;
	rocks = tmp;
	int low = 1;
	int high = 1e9;
	while (low <= high) {
		int mid = (low + high) / 2;
		cout << mid << "\n";
		if (is_possible(rocks, n, mid)) {
		
			low = mid + 1;
			answer = mid;
		}
		else {
			high = mid - 1;
		}
	}

	return answer;
}

int main() {
	solution(25, rocks, 2);
}