#include<iostream>
using namespace std;

int go(int n)
{
	int sum = n;

	while (n > 0)
	{
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

int main() {


	int t, n;
	cin >> t;

	for (int test = 0; test < t; test++)
	{
		cin >> n;

		bool check = false;
		for (int i = 0; i < 1000; i++)
		{
			check |= (n == go(n - i));
		}

		if (!check)
			cout << "Self" << '\n';
		else
			cout << "No" << '\n';
	}
	return 0;
}