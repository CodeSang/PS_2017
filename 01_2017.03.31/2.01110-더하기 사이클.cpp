#include<iostream>
using namespace std;

int N;
int m[100];

int main() {
	cin >> N;
	int cnt = 0;
	while (true) {
		if (m[N]) break;
		m[N] = 1;
		cnt++;
		int temp = N;
		int sum = 0;
		while (temp > 0)
		{
			sum += temp % 10;
			temp /= 10;
		}
		N = (N % 10) * 10 + (sum % 10);
	}
	cout << cnt << endl;
	return 0;
}