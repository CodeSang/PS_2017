#include<iostream>
#include<queue>
using namespace std;


int N, M;
int ice[2][333][333];

int bfsCount(int y, int x) {

	bool visited[333][333] = { false };

	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;

	while (!q.empty())
	{
		auto iter = q.front();
		q.pop();
		cnt++;

		if (iter.first - 1 >= 0 && !visited[iter.first - 1][iter.second] && ice[0][iter.first - 1][iter.second] > 0) {
			visited[iter.first-1][iter.second] = true;
			q.push({ iter.first-1,iter.second });
		}
		if (iter.first + 1 <  N &&!visited[iter.first + 1][iter.second]&& ice[0][iter.first + 1][iter.second] > 0) {
			visited[iter.first+1][iter.second] = true;
			q.push({ iter.first+1,iter.second });
		}
		
		if (iter.second - 1 >= 0 && !visited[iter.first][iter.second - 1] &&ice[0][iter.first][iter.second - 1] > 0) {
			visited[iter.first][iter.second - 1] = true;
			q.push({ iter.first,iter.second - 1});
		}
		if ( iter.second + 1 < M && !visited[iter.first][iter.second + 1] && ice[0][iter.first][iter.second + 1] > 0) {
			visited[iter.first][iter.second+1] = true;
			q.push({ iter.first,iter.second+1 });
		}


	}

	return cnt;
}

int main() {

	cin >> N >> M;
	
	queue<pair<int , int> > q;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ice[0][i][j];
			if (ice[0][i][j] > 0) q.push({ i,j });
		}

	int ans = 0;
	while ( !q.empty())
	{
		auto test = q.front();
		if (bfsCount(test.first, test.second) != q.size()) {
			cout << ans << endl;
			return 0;
		}

		while(!q.empty()) {
		
			auto iter = q.front();
			q.pop();

			int cnt = 0;

			if (iter.first  - 1 >= 0 && ice[0][iter.first - 1][iter.second] < 1) cnt++;
			if (iter.first  + 1 <  N && ice[0][iter.first + 1][iter.second] < 1) cnt++;
			if (iter.second - 1 >= 0 && ice[0][iter.first][iter.second - 1] < 1) cnt++;
			if (iter.second + 1 <  M && ice[0][iter.first][iter.second + 1] < 1) cnt++;

			ice[1][iter.first][iter.second] = ice[0][iter.first][iter.second] - cnt;
		}
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				ice[0][i][j] = ice[1][i][j];
				if (ice[0][i][j] > 0) q.push({ i,j });
			}
		ans++;
	}

	cout << "0" << endl;
	return 0;
}