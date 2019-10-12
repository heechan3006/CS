#include <iostream>
#include <math.h>
#define MAX_N 300000
using namespace std;

int A, P;
int visited[MAX_N];
int ans;
int compute_num(int A, int P,int ans) {
	if (A== 0) return ans;
	compute_num(A / 10, P,ans+pow(A%10,P)); 
}
void dfs(int A) {
	visited[A] += 1;
	if (visited[A] == 3) return;
	dfs(compute_num(A, P,0));
	
}
int main() {
	cin >> A >> P;
	dfs(A);
	int cnt = 0;
	for (int i = 0; i < MAX_N; i++) {
		if (visited[i] == 1) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
}