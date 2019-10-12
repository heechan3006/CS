#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 100000+2
using namespace std;


int grade[MAXN];

int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> N;
		int tmp_x, tmp_y;
		for (int i = 0; i < N; i++) {
			cin >> tmp_x >> tmp_y;
			grade[tmp_x] = tmp_y;
		}
	
		int ans = 0;
		int min_grade = MAXN;
		for (int i =1; i <= N; i++){
			if (min_grade > grade[i]) {
				ans++;
				min_grade = grade[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
