#include<iostream>
using namespace std;

int N;
int n[1111];

int main() {
	cin >> N;
	n[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		int temp = 0;
		if (i - 1 > 0)	temp |= n[i - 1];
		if (i - 3 > 0)	temp |= n[i - 3];
		if (i - 4 > 0)	temp |= n[i - 4];

		n[i] = (1 ^ temp);
	}

	if (n[N] == 0)
		cout << "SK" << endl;
	else
		cout << "CY" << endl;
	return 0;
}