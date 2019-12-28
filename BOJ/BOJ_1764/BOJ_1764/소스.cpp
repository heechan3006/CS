#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

vector<string> v1,v2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v1.resize(N);
	for (int i = 0; i < N; i++) {
		string s;
		cin >> v1[i];
	}
	sort(v1.begin(), v1.end());
	while (M--) {
		string s;
		cin >> s;
		int low = 0;
		int high = v1.size()-1 ;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (v1[mid] < s) {
				low = mid + 1;
			}
			else if (v1[mid] > s) {
				high = mid - 1;
			}
			else {
				v2.push_back(s);
				break;
			}
		}
	}
	sort(v2.begin(), v2.end());
	cout << v2.size() << "\n";
	
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << "\n";
	}
	return 0;
	
}