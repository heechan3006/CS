#include <iostream>

using namespace std;

int N, M, D;
int map[17][17];
bool check[17][17];
int kill, ans = -999999;

void initCheck()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			check[i][j] = false;
}

void input()
{
	cin >> N >> M >> D;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
}

int abs(int a, int b)
{
	if (a > b)return a - b;
	else return b - a;
}

void castle(int now, int depth)
{
	if (depth == 3)
	{
		initCheck();
		kill = 0;
		for (int j = 0; j < N; j++)
		{
			int cnt = 0;
			int x[3] = { -1,-1,-1 }, y[3] = { -1,-1,-1 };
			int minD[3] = { 9999,9999,9999 };

			for (int i = M - 1; i >= 0; i--)
			{
				if (map[N][i] == 1)
				{
					for (int k = 0; k < N - j; k++)
						for (int l = M - 1; l >= 0; l--)
							if (map[k][l] == 1 && check[k][l] != true)
							{
								if ((abs(k, N - j) + (abs(l, i))) <= D)
								{
									if ((abs(k, N - j) + (abs(l, i))) <= minD[cnt])
									{
										x[cnt] = l;
										y[cnt] = k;
										minD[cnt] = (abs(k, N - j) + (abs(l, i)));
									}
								}
							}
					cnt++;
				}
			}
			for (int k = 0; k < cnt; k++)
			{
				if (check[y[k]][x[k]] != true && x[k] != -1 && y[k] != -1)
				{
					check[y[k]][x[k]] = true;
					kill++;
				}
			}
		}

		if (kill > ans) ans = kill;
	}

	for (int i = now; i < M; i++)
	{
		if (map[N][i] == 1) continue;
		map[N][i] = 1;
		castle(i, depth + 1);
		map[N][i] = 0;
	}
}

int main()
{
	input();
	castle(0, 0);
	cout << ans;
}