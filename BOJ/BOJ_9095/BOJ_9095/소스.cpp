#include <iostream>
#include <cstring>
using namespace std;

int D[12];
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> N;
		memset(D, 0, sizeof(D));
		D[1] = 1;
		D[2] = 2;
		D[3] = 4;
		for (int i = 4; i <= N; i++) {
			D[i] = D[i - 1] + D[i - 2] + D[i - 3] ;
		}
		cout << D[N] << "\n";
	}
}
