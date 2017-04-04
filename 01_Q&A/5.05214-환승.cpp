#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M, K;
vector<int> node[101101];
bool chk[101101] = { false, };

int main() {

	cin >> N >> K >> M;

	for (int i = 0; i < M; i++)
	{
		int temp;
		for (int j = 0; j < K; j++)
		{
			cin >> temp;
			node[N + i + 1].push_back(temp);
			node[temp].push_back(N + i + 1);
		}
	}


	queue<pair<int, int> > q;
	q.push({ 1, 1});
	chk[1] = true;
	while(!q.empty())
	{
		auto f = q.front();
		q.pop();

		if (f.first == N)
		{
			cout << f.second << endl;
			return 0;
		}

		for (auto iter : node[f.first])
		{

			for (auto iter2 : node[iter])
			{
				if (chk[iter2]) continue;
				chk[iter2] = true;
				q.push({ iter2, f.second + 1 });
			}
		}
	}


	cout << -1 << endl;
	return 0;
}