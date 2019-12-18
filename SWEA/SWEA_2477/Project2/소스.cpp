#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAXN 10
#define MAXK 1001
using namespace std;

queue<int> reception_wait_q;
queue<pair<int,int> > repair_wait_q;
queue<pair<int,int> > arrival_q;
pair<int,int> reception[MAXN];
int reception_time[MAXN];
pair<pair<int,int> ,int> repair[MAXN];
int repair_time[MAXN];
vector<int> arrival_time;

int N, M, K, A, B;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	freopen("input.txt", "r", stdin);
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		
		cin >> N >> M >> K >> A >> B;
		
		arrival_time.resize(K+1, 0);
		for (int i = 1; i <= N; i++) {
			cin >> reception_time[i];
		}
		for (int i = 1; i <= M; i++) {
			cin >> repair_time[i];
		}
		for (int i = 1; i <= K; i++) {
			cin >> arrival_time[i];
		}
		sort(arrival_time.begin(), arrival_time.end());
		for (int i = 1; i <= K; i++) {
			arrival_q.push({ i,arrival_time[i] });
		}
		memset(reception, 0, sizeof(reception));
		memset(repair, 0, sizeof(repair));
		int time = 0;
		int cnt = 0;
		int ans = 0;
		while (cnt < K) {
			while (!arrival_q.empty()) {
				if (arrival_q.front().second != time) break;
				reception_wait_q.push(arrival_q.front().first);
				arrival_q.pop();
				
			}
			for (int i = 1; i <= N; i++) {
				reception[i].second--;
				//빈 접수창구
				if (reception[i].first == 0 && reception[i].second <= 0 && !reception_wait_q.empty()) {
					reception[i].first = reception_wait_q.front();
					reception[i].second = reception_time[i];
					reception_wait_q.pop();
				}
				//접수완료 -> 고객번호, 접수번호
				else if (reception[i].first != 0 && reception[i].second <= 0) {
					repair_wait_q.push({ reception[i].first,i });
					reception[i] = { 0,0 };
					if (!reception_wait_q.empty()) {
						reception[i].first = reception_wait_q.front();
						reception[i].second = reception_time[i];
						reception_wait_q.pop();
					}
				}
			}

			for (int i = 1; i <= M; i++) {
				repair[i].second--;
				// 빈 정비창구
				if (repair[i].first.second == 0 && repair[i].second <= 0 && !repair_wait_q.empty()) {
					repair[i].first.first = repair_wait_q.front().first;
					repair[i].first.second = repair_wait_q.front().second;
					repair[i].second = repair_time[i];
					repair_wait_q.pop();
				}
				// 정비완료 -> 고객번호,접수창구번호, 정비창구번호
				if (repair[i].first.second != 0 && repair[i].second <= 0) {
					if (repair[i].first.second == A && i == B) {
						ans += repair[i].first.first;
					}
					cnt++;
					repair[i] = { {0,0},0 };
					if (!repair_wait_q.empty()) {
						repair[i].first.first = repair_wait_q.front().first;
						repair[i].first.second = repair_wait_q.front().second;
						repair[i].second = repair_time[i];
						repair_wait_q.pop();
					}
				}
			}
			time++;
		}
		cout << "#" << test_case << " ";
		if (ans == 0) cout << "-1\n";
		else cout << ans << "\n";
	}
	
	return 0;
}