#include <iostream>
#include <vector>

using namespace std;

int N;
struct node {
	int x;
	int y;
	bool visited;
};

int ans = 10e5;
void dfs(vector<node> &v,int now, int len, int before) {
	if (now == N) {
		len +=(abs(v[1].x - v[before].x) + abs(v[1].y - v[before].y));
		if (ans > len) {
			ans = len;
		}
		return;
	}
	for (int i = 2; i < v.size(); i++) {
		if (!v[i].visited){
			v[i].visited = true;
			dfs(v,now+1,len+abs(v[i].x-v[before].x)+abs(v[i].y-v[before].y),i);
			v[i].visited = false;
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case= 1; test_case<=t; test_case++){
		scanf("%d", &N);
		vector<node> v(N + 2);
		for (int i = 0; i < N + 2; i++) {
			int tmp_x, tmp_y;
			scanf("%d %d", &tmp_x, &tmp_y);
			v[i].x = tmp_x;
			v[i].y = tmp_y;
			v[i].visited = false;
		}
		ans = 10e5;
		dfs(v,0, 0, 0);
		printf("#%d %d\n", test_case,ans);
	}
	return 0;
}