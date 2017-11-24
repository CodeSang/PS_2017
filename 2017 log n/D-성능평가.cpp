#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;


int ans[51];
vector< vector<int> > algo;


vector<pair<int, pair<int,int> > > v;

int main() {
	int K, N;

	cin >> K >> N;
	for (int i = 0; i < K; i++)
		cin >> ans[i];

	algo.resize(N);
	for (int i = 0; i < N; i++)
	{
		algo[i].resize(K);
		for (int j = 0; j < K; j++)
			cin >> algo[i][j];
	}

	for (int i = 0; i < N; i++)
	{

		int out = 0;
		int m = INT32_MAX;

		for (int j = 0; j < K; j++)
		{
			if (ans[j] != algo[i][j]) {
				out++;
				m = min(m, abs(ans[j] - algo[i][j]));
			}
		}

		v.push_back({ out,{m,i} });
	}

	sort(v.begin(), v.end());

	cout << v[0].second.second << endl;
	return 0;
}

