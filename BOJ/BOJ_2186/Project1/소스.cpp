#include<iostream>
#include<cstring>
#include<string>

#define endl "\n"
#define MAX 100
using namespace std;

int N, M, K, Answer;
char MAP[MAX][MAX];
int DP[MAX][MAX][80];

string Dest;
int Dest_Len;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


void Input()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
		}
	}
	cin >> Dest;
	Dest_Len = Dest.length();
	memset(DP, -1, sizeof(DP));
}

int DFS(int x, int y, int Idx)
{
	if (DP[x][y][Idx] != -1) return DP[x][y][Idx];
	if (Idx >= Dest_Len) return 1;

	DP[x][y][Idx] = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 1; k <= K; k++)
		{
			int nx = x + dx[i] * k;
			int ny = y + dy[i] * k;

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (MAP[nx][ny] != Dest[Idx]) continue;

			DP[x][y][Idx] = DP[x][y][Idx] + DFS(nx, ny, Idx + 1);
		}
	}
	return DP[x][y][Idx];
}

void Solution()
{
	char Temp = Dest[0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (MAP[i][j] == Temp)
			{
				Answer = Answer + DFS(i, j, 1);
			}
		}
	}
	cout << Answer << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("Input.txt", "r", stdin);
	Solve();

	return 0;
}
