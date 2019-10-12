#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<int>> v;
bool possible = false;
void go(int idx) {
	if (idx == 99) {
		possible = true;
		return;
	}
	for (int i = 0; i < v[idx].size(); i++) {
		go(v[idx][i]);
	}
}
int main() {
	int t;
	for (int test_case=1; test_case <= 10 ; test_case++){
		scanf("%d %d",&t, &N);
		v.resize(N);
		possible = false;
		for (int i = 0; i < N; i++) {
			int tmp_x, tmp_y;
			scanf("%d %d",&tmp_x,&tmp_y);
			v[tmp_x].push_back(tmp_y);
		}
		go(0);
		printf("#%d %d\n", t,possible);
		v.clear();
	}
}