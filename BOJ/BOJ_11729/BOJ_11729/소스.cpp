#include <iostream>
using namespace std;

void go(int n, int from, int to) {
	if (n == 0) return;
	go(n - 1, from, 6 - from - to);
	cout << from << " " << to << "\n";
	go(n - 1, 6 - from - to, to);
}
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	cout << (1 << N) - 1 << "\n";
	go(N,1,3);
	return 0;

}