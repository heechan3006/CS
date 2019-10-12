#include <iostream>
#include <cstring>
#define MAXN 10000
using namespace std;

int D[MAXN];
int coin[MAXN];
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> coin[i];
		}
		cin >> M;
		memset(D, 0, sizeof(D));
		D[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = coin[i]; j <= M; j++) {
				D[j] += D[j - coin[i]];
			}
		}
		cout << D[M] << "\n";
	}
	return 0;
}