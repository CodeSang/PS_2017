#include<iostream>
using namespace std;


int main() {
	long long N;
	cin >> N;
	if (N % 5LL == 0LL || N % 5LL == 2LL)
		cout << "CY" << endl;
	else
		cout << "SK" << endl;
	return 0;
}