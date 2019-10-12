#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, L;
int arr[21][10001];
int ti[21];
int ki[21];

int main() {
	int t;
	cin >> t;
	for (int test_case=1; test_case <=t; test_case++){
		cin >> N >> L;
		for (int i = 1; i <= N; i++) {
			cin >> ti[i] >> ki[i];	
		}
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= L; k++) {
				if (k < ki[j]) arr[j][k] = arr[j - 1][k];
				else {
					arr[j][k] = max(arr[j - 1][k], arr[j - 1][k - ki[j]] + ti[j]);
				}
			}
		}
		printf("#%d %d\n", test_case,arr[N][L]);
		memset(arr, 0, sizeof(arr));
		memset(ti, 0, sizeof(ti));
		memset(ki, 0, sizeof(ki));
	}
	return 0;
}