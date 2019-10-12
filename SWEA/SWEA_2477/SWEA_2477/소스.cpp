#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
	int idx;
	int time;
	int a_time;
	int b_time;
};
struct point {
	int num;
	int time;
};
struct info {
	int recepN;
	int repairN;
};
info num_count[1001];
point recep[10] ;
point repair[10] ;
int TK[1001];
int N, M, K, a, b;
int A[10];
int B[10];
queue<int> recep_wait_q;
queue<int> repair_wait_q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int test_case=  1; test_case<=t; test_case++){
		cin >> N >> M >> K >> a >> b;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
		}
		for (int j = 1; j <= M; j++) {
			cin >> B[j];
		}
		for (int i = 1; i <= K; i++) {
			cin >> TK[i];
		

		}
	
		int time = 0;
		int cnt = 0;
		int ans = 0;
		while (1) {
			// 접수대 대기
			for (int i = 1; i <= K; i++) {
				if (TK[i] == time) {
					recep_wait_q.push(i);
				}
			}
			// 접수대 끝난사람 정비 대기
			for (int i = 1; i <= N; i++) {
				if (recep[i].time == time && recep[i].num != 0) {
					repair_wait_q.push(recep[i].num);
					recep[i].num = 0;
				}
			}
			// 정비 끝난사람 숫자 카운트
			for (int i = 1; i <= M; i++) {
				if (repair[i].time == time && repair[i].num != 0) {
					repair[i].num = 0;
					cnt++;
				}
			}
			// 접수대 비어있으면 대기인원 넣기
			for (int i = 1; i <= N; i++) {
				if (recep_wait_q.empty()) break;
				if (recep[i].num == 0) {
					recep[i].num = recep_wait_q.front();
					recep[i].time = A[i] + time;
					recep_wait_q.pop();
					//기록
					num_count[recep[i].num].recepN = i;
				}
			}
			// 정비실 비어있으면 대기 인원 넣기
			for (int i = 1; i <= M; i++) {
				if (repair_wait_q.empty()) break;
				if (repair[i].num == 0) {
					repair[i].num = repair_wait_q.front();
					repair[i].time = B[i] + time;
					repair_wait_q.pop();
					num_count[repair[i].num].repairN = i;
				}
			}
			if (K == cnt) {
				for (int i = 1; i <= K; i++) {
					if (num_count[i].recepN == a && num_count[i].repairN == b) {
						ans += i;
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