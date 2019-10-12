#include <iostream>

using namespace std;
int D, H, M;
int D0 = 11;
int H0 = 11;
int M0 = 11;

int compute_min(int &D, int &H, int &M) {
	return 60 * 24 * D + 60 * H + M;

}
int main()
{
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		cin >> D >> H >> M;
		int minute,minute0;
		minute = compute_min(D, H, M);
		minute0 = compute_min(D0, H0, M0);
		int diff = minute - minute0;
		if (diff < 0) printf("#%d -1\n",test_case);
		else {
			printf("#%d %d\n", test_case,diff);
		}
	}
	return 0;
}

