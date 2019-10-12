#include <iostream>
#include <cstring>

using namespace std;
int D[2][41];

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
		D[0][0] = 1;
		D[1][1] = 1;
		for (int i = 2; i <= N; i++) {
			D[0][i] = D[0][i - 1] + D[0][i - 2];
			D[1][i] = D[1][i - 1] + D[1][i - 2];
		}
	
		cout << D[0][N] << " " << D[1][N] << "\n";
	}
}