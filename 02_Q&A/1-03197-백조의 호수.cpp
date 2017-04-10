#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;


bool visited[1501][1501] = { false };
vector<string> river;
queue<pair<int, int>> iceMelt; // y , x;
int R, C;

void setInitMeltIce(int y, int x)
{
	visited[y][x] = true;
	if (river[y][x] == 'X')
	{
		iceMelt.push({ y,x });
	}
	else
	{
		if (y - 1 >= 0 && !visited[y - 1][x]) setInitMeltIce(y - 1, x);
		if (y + 1 <  R && !visited[y + 1][x]) setInitMeltIce(y + 1, x);
		if (x - 1 >= 0 && !visited[y][x - 1]) setInitMeltIce(y, x - 1);
		if (x + 1 <  C && !visited[y][x + 1]) setInitMeltIce(y, x + 1);
	}

	return;
}


void setMeltIce(int y, int x)
{
	visited[y][x] = true;
	if (river[y][x] == 'X')
	{
		river[y][x] = '.';
		iceMelt.push({ y,x });
	}
	else
	{
		if (y - 1 >= 0 && !visited[y - 1][x]) setMeltIce(y - 1, x);
		if (y + 1 <  R && !visited[y + 1][x]) setMeltIce(y + 1, x);
		if (x - 1 >= 0 && !visited[y][x - 1]) setMeltIce(y, x - 1);
		if (x + 1 <  C && !visited[y][x + 1]) setMeltIce(y, x + 1);
	}

	return;
}

// 매턴 녹이는 함수

void meltdown() {

	queue<pair<int, int>> temp;
	swap(temp, iceMelt);

	while (!temp.empty())
	{
		auto f = temp.front();
		temp.pop();
		setMeltIce(f.first, f.second);
	}
}

//백조가 백조에게 갈수 있는가 확인 하는 메소드.
bool visited2[1501][1501] = { false };
int swanX1 = -1, swanY1, swanX2, swanY2;
queue<pair<int, int>> swan;


bool meetSwan() {

	queue<pair<int, int>> temp;
	swap(temp, swan);

	while (!temp.empty()) {

		auto f = temp.front();
		temp.pop();

		int x = f.second;
		int y = f.first;

		if (x == swanX2 && y == swanY2) return true;

		if (y - 1 >= 0 && !visited2[y - 1][x] )
		{
			visited2[y - 1][x] = true;

			if(river[y - 1][x] == 'X')
				swan.push({ y - 1,x });
			else
				temp.push({ y - 1,x });

		}

		if (y + 1 < R && !visited2[y + 1][x])
		{
			visited2[y + 1][x] = true;
			if(river[y + 1][x] == 'X')
				swan.push({ y + 1,x });
			else
				temp.push({ y + 1,x });
		}
		if (x - 1 >= 0 && !visited2[y][x - 1] ) {

			visited2[y][x - 1] = true;
			if( river[y][x - 1] == 'X')
				swan.push({ y,x - 1 });
			else
				temp.push({ y,x - 1 });

		}
		if (x + 1 < C && !visited2[y][x + 1] )
		{
			visited2[y][x + 1] = true;
			if(river[y][x + 1] == 'X')
				swan.push({ y,x + 1 });
			else
				temp.push({ y,x + 1 });
		}
	}

	return false;
}

int main() {


	freopen("labudovi.i06", "r", stdin);
	cin >> R >> C;
	
	string temp;

	for (int i = 0; i < R; i++)
	{
		cin >> temp;
		river.push_back(temp);
		for (int j = 0; j < C; j++)
		{
			if (temp[j] == 'L')
			{
				if (swanX1 == -1)
				{
					swanX1 = j;
					swanY1 = i;

					swan.push({ swanY1, swanX1 });
					visited2[swanY1][swanX1] = true;

				}
				else
				{

					swanX2 = j;
					swanY2 = i;
				}
			}
		}
	}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (river[i][j] != 'X' && !visited[i][j]) setInitMeltIce(i, j);

	int ans = 0;
	while (!meetSwan())
	{
		meltdown();
		ans++;
	}

	cout << ans << endl;
	return 0;
}