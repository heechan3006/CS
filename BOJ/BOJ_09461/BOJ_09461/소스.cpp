#include <iostream>
#include <memory.h>
using namespace std;
int N;

long long D[1001] = {0,1,1,1,2,2,3,4,5, };

int main() {
	int t;
	cin >> t;
	for (int i = 9; i <=100; i++) {
		D[i] = D[i - 1] + D[i - 5];
	}
	while(t--){
		cin >> N;	
		printf("%lld\n", D[N]);
		}
	return 0;
}