#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;


int m, n;
int mat[33][33];
long long mem[33][33] = { 0 };
bool visited[33][33] = { false };
bool updated[33][33] = { false };
bool Nvisited[33][33] = { false };

int dx[8] = { 2,2,1,1,-1,-1,-2,-2 };
int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };

int srcx, srcy, dstx, dsty;
// 0 ºó¶¥, 1 ¹æ¼Ó,2 µ¹ ,3 src ,4 dst

queue<pair<int, int>> q;
int minCushion = 0;
long long CaseNum = 0;

void Mo(int y, int x, long long data)
{
	queue<pair<int, int>> temp;
	temp.push({ y, x });
	Nvisited[y][x] = true;

	while (!temp.empty()) {
		auto iter = temp.front();
		temp.pop();

		int ty = iter.first;
		int tx = iter.second;

		for (int i = 0; i < 8; i++)
		{
			int tempy = ty + dy[i];
			int tempx = tx + dx[i];

			if (tempy < m && tempy >= 0 && tempx >= 0 && tempx < n)
			{
				if (!visited[tempy][tempx])
				{
					
					if (!updated[tempy][tempx])
					{						
						if (mat[tempy][tempx] == 0)
						{
							q.push({ tempy,tempx });
							updated[tempy][tempx] = true;
						}
						else if (mat[tempy][tempx] == 1)
						{
							if (!Nvisited[tempy][tempx])
								temp.push({ tempy,tempx });
						}

						if (!Nvisited[tempy][tempx])
							if (mat[tempy][tempx] == 0 || mat[tempy][tempx] == 4)
								mem[tempy][tempx] += data;
						Nvisited[tempy][tempx] = true;

					}
					else {
						if (!Nvisited[tempy][tempx])
							if (mat[tempy][tempx] == 0 || mat[tempy][tempx] == 4)
								mem[tempy][tempx] += data;
						Nvisited[tempy][tempx] = true;
					}

				}
			}
		}
	}
}

long long Go()
{
	queue<pair<pair<int, int>, long long>> temp;

	while (!q.empty())
	{
		temp.push({ { q.front().first,q.front().second },mem[q.front().first][q.front().second] });
		q.pop();
	}

	while (!temp.empty())
	{
		memset(Nvisited, false, sizeof(Nvisited));
		auto iter = temp.front();
		temp.pop();
		Mo(iter.first.first, iter.first.second, iter.second);
	}

	return mem[dsty][dstx];
}


int main() {

	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];

			if (mat[i][j] == 3)
			{
				srcx = j;
				srcy = i;
			}
			else if (mat[i][j] == 4)
			{
				dstx = j;
				dsty = i;
			}
		}

	q.push({ srcy, srcx });
	visited[srcy][srcx] = true;
	mem[srcy][srcx] = 1;

	while (!q.empty()) {

		CaseNum = Go();



		if (CaseNum)
		{
			cout << minCushion << endl;
			cout << CaseNum << endl;
			return 0;
		}
		minCushion++;
	}

	cout << "-1" << endl;
	return 0;
}