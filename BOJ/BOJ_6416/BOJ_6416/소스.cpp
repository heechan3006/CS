#include <iostream>
#include <vector>
using namespace std;
#define MAX_NUM 14

bool visit[MAX_NUM];
int cnt = 0;
int in[MAX_NUM];
int out[MAX_NUM];
bool have_cycle = false;
vector<int> adj[MAX_NUM];
void dfs(int now) {
    if (have_cycle) return;
    cnt++;
    visit[now] = true;
    for (int i = 0; i < adj[now].size(); i++) {
        int next = adj[now][i];
        if (visit[next]) {
            have_cycle = true;
            return;
        }
        else {
            dfs(next);
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test_case = 0;
    while (++test_case) {
        for (int i = 0; i < MAX_NUM; i++) {
            adj[i].clear();
            in[i] = 0;
            out[i] = 0;
            cnt = 0;
            visit[i] = false;
            have_cycle = false;
        }
        while (true) {
            int a, b;
            cin >> a >> b;
            if (a == 0 && b == 0) break;
            else if (a == -1 && b == -1) return 0;
            adj[a].push_back(b);
            in[b]++;
            out[a]++;
        }
        int root_cnt = 0;
        int root_index = 0;
        int total_cnt = 0;
        int not_root_cnt = 0;

        for (int i = 0; i < MAX_NUM; i++) {
            if (in[i] == 0 && out[i] > 0) {
                root_cnt++;
                root_index = i;
            }
            if (in[i] != 0 || out[i] != 0)
                total_cnt++;

            if (in[i] == 1)
                not_root_cnt++;

        }

        if (root_cnt != 1 && total_cnt != 0)
            cout << "Case " << test_case << " is not a tree.\n";
        else {
            if (total_cnt == 0)
                cout << "Case " << test_case << " is a tree.\n";
            else {
                dfs(root_index);
                if (total_cnt == cnt && have_cycle == false)
                    cout << "Case " << test_case << " is a tree.\n";
                else
                    cout << "Case " << test_case << " is not a tree.\n";
            }
        }
    }

}