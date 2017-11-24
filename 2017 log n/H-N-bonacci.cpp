#include<iostream>
#include<queue>
#define MOD  1000000007 
using namespace std;


int main() {
	int t;
	int n, k;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> k;

		if (k == n) {
			cout << 1 << '\n';
			continue;
		}
		else if (k < n)
		{
			cout << 0 << '\n';
			continue;
		}

		int sum_ = 1;

		queue<int> q; 
		for (int j = 1; j < n; j++)
			q.push(0);
		q.push(1);

		for (int j = n+1; j < k; j++)
		{
			q.push(sum_);
			sum_ = (sum_ + sum_) % MOD;
			sum_ = (sum_ - q.front() + MOD ) % MOD;
			q.pop();
		}

		cout << sum_ << '\n';
	}
	return 0;
}