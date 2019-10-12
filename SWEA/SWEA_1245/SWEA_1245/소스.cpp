#include <iostream>
#include <iomanip>
using namespace std;

int N;

double x[10], m[10];

int main() {
	cout.precision(10);
	int t;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> m[i];
		}
		printf("#%d ", test_case);
		for (int i = 0 ; i < N-1; ++i){
			double left = x[i], right = x[i + 1], ans = 0;
			for (int k = 0; k < 50; ++k) {
				double mid = (left + right) / 2;
				double s = 0;
				for (int j = 0; j <= i; ++j) {
					s += m[j] / ((mid - x[j]) * (mid - x[j]));
				}
				for (int j = i + 1; j < N; ++j) {
					s -= m[j] / ((mid - x[j]) * (mid - x[j]));
				}
				if (s > 0) {
					left = mid;
				}
				else {
					ans = mid;
					right = mid;
				}
			}
			printf("%.10f ", ans);
		}
		printf("\n");
	}
	return 0;
}