#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
int A[9];
int total = 0;
void psum(vector<int>& v, int index, int sum) {
	if (index == 0) {
		total = sum;
		return;
	}
	psum(v, index - 1, sum + abs(A[v[index]] - A[v[index - 1]])) ;
}
int main(){
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		v.push_back(i);
	}
	
	int ans = 0;
	do {
		
		psum(v, N - 1,0);
		if (ans < total) ans = total;
	} while (next_permutation(v.begin(), v.end()));
	printf("%d\n", ans);
}