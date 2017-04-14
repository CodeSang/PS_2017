#include<iostream>
#include<queue>
using namespace std;

struct tomato {

	int y;
	int x;
	int day;
	tomato() {}
	tomato(int y_, int x_, int day_)
	{
		y = y_;
		x = x_;
		day = day_;
	}
};

int M, N;
int mat[1001][1001];
bool visited[1001][1001] = { false };
int rawTomato = 0;

queue<tomato> q;

int main() {
	cin >> M >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> mat[i][j];
			if (mat[i][j] == 0) rawTomato++;
			else if (mat[i][j] == 1) {
				q.push(tomato(i, j, 0));

				
			}
		}

	int dx[4] = { 0,  0, 1, -1 };
	int dy[4] = { 1, -1, 0,  0 };

	int ans = 0;
	while (!q.empty())
	{
		tomato temp;
		temp.x = q.front().x;
		temp.y = q.front().y;
		temp.day = q.front().day;
		
		ans = max(ans, temp.day);
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int tempx = temp.x + dx[i];
			int tempy = temp.y + dy[i];
			if (tempx >= 0 && tempx < M && tempy >= 0 && tempy < N)
			{
				if (mat[tempy][tempx] == 0)
				{
					q.push(tomato(tempy, tempx, temp.day + 1));
					mat[tempy][tempx] = 1;
					rawTomato--;
				}
			}
		}
	}

	if (rawTomato != 0)
		cout << "-1" << endl;
	else
		cout << ans << endl;

	return 0;
}