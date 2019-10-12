#include <iostream>
#include <map>

using namespace std;

int n, m, k;

int main() {
	int t,T;
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++){

		map<int,int> time;
		cin >> n >> m >> k;
		int last = 0;
		for (int i = 0; i < n; i++) {
			cin >> t;
		
			if (!time.count(t)) {
				time.insert(make_pair(t, 1));
			}
		
			else{
				time.insert(make_pair(t, time.count(t) + 1));
			}
			if (t > last) last = t;
		
		}
		int sum = 0;
		bool possible = true;
	
		for (auto it = time.begin(); it != time.end(); it++) {
		
			t = (*it).first;
			int eat = (*it).second;
			sum += eat;
			int product = (t / m) * k;
			if (product < sum) {
				possible = false;
				break;
			}
		}
		if (possible) {
			printf("#%d Possible\n",test_case);
		}
		else {
			printf("#%d Impossible\n",test_case);
		}
	}
	return 0;
	
}