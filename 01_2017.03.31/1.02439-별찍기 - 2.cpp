#include<iostream>
using namespace std;


void printModule(int N, char c)
{
	for (int i = 0; i < N; i++)
		cout << c;
}

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		printModule(n - i, ' ');
		printModule(i, '*');
		cout << '\n';
	}
}