#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> ans;

int main() {
	cin >> N; 

	for (int i = 1; i <=N; i++)
	{
		vector<int> temp;

		temp.push_back(N);
		temp.push_back(i);

		int old = i;
		int num = N - i;
		while ( num >= 0)
		{
			temp.push_back(num);

			int tempInteger = old;
			old = num;
			num = tempInteger - num;
		}

		if (ans.size() <= temp.size())
			swap(ans, temp);
	}
	cout << ans.size() << '\n';
	for (auto &iter : ans)
		cout << iter << ' ';
}