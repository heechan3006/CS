#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int time[100001];

int main() {
	cin >> N >> M;
	memset(time, 0, sizeof(time));
	long long max = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &time[i]);
		if (time[i] > max) {
			max = time[i];
		}
	}
	long long time1 = 0; 
	long long time2 = max * M;
	long long mid;
	long long min = max * M;
	
	while (time1 <= time2) {
		mid = (time1 + time2) / 2;
		long long answer = 0;
		for (int i = 0; i < N; i++) {
			answer += mid / time[i];
		}
		if (answer < M) {
			time1 = mid + 1;
		}
		else {
			if (min > mid) {
				min = mid;
			}
			time2 = mid - 1;
		}
	}
	printf("%lld\n", min);
	
}