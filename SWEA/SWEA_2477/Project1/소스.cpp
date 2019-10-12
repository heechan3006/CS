#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct point {
	int num;
	int time;
};
pair<int, int> num_count[1001];
int N, M,K,A,B;
int ans;
int TK[1001];
int rep_time[21];
int recep_time[21];
point repair[21];
point reception[21];
queue<int> reception_wait_q;
queue<int> repair_wait_q;
int cnt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test_case=1; test_case<=t; test_case++){
		cin >> N >> M >> K >> A >> B;
		for (int i = 1; i <= N; i++) {
			cin >> recep_time[i];
		}
		for (int i = 1; i <= M; i++) {
			cin >> rep_time[i];
		}
		for (int i = 1; i <= K; i++) {
			cin >> TK[i];
		}
		int time = 0;
		cnt = 0;
		ans = 0;
		while (1) {
			// Á¤ºñ¼Ò µµÂø
			for (int i = 1; i <= K; i++) {
				if (TK[i] == time) {
					reception_wait_q.push(i);
				}
			}
			for (int i = 1; i <= N; i++) {
				if (reception[i].time == time && reception[i].num != 0) {
					num_count[reception[i].num].first = i;
					repair_wait_q.push(reception[i].num);
					reception[i].num = 0;
				}
			}
			for (int i = 1; i <= M; i++) {
				if (repair[i].time == time && repair[i].num != 0) {
					num_count[repair[i].num].second = i;
					cnt++;
					repair[i].num = 0;
				}
			}
			for (int i = 1; i <= N; i++) {
				if (reception_wait_q.empty()) break;
				if (reception[i].num == 0) {
					reception[i].num = reception_wait_q.front();
					reception_wait_q.pop();
					reception[i].time = time + recep_time[i];
				
				}
			}

			for (int i = 1; i <= M; i++) {
				if (repair_wait_q.empty()) break;
				if (repair[i].num == 0) {
					repair[i].num = repair_wait_q.front();
					repair_wait_q.pop();
					repair[i].time = time + rep_time[i];
				}
			}
			if (cnt == K) {
				for (int i = 1; i <= K; i++) {
					if (num_count[i].first == A && num_count[i].second==B){
						ans+=i;
					}
				}
				break;
			}
			time++;
		}
		cout << "#" << test_case << " ";
		if (ans == 0) cout << -1 << "\n";
		else cout << ans << "\n";
	}
	return 0;
}
