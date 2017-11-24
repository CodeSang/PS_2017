#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int K, N, now;

int robot[11];
int main() {
	cin >> N >> K;

	int before = 0;
	int after = 0;

	priority_queue<int> robotpq;

	for (int i = 0; i < N; i++)
		robotpq.push(0);

	for (int i = 0; i < K; i++)
	{
		int s, e;
		cin >> s >> e;

		if (robot[now] < s)
			robot[now] = s + e;
		else
			robot[now] += e;

		before = max(before, robot[now]);
		now = (now + 1) % N;


		int t = -robotpq.top();
		robotpq.pop();

		if (t < s)
			t = s + e;
		else
			t += e;

		robotpq.push(-t);

		after = max(after, t);
	}




	cout << (before - after ) * 100LL<< endl;
	return 0;

}