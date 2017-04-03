#include<iostream>
#include<iomanip>
using namespace std;


int main() {

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int num, student[1001];
		cin >> num;

		double sum = 0;
		for (int j = 0; j < num; j++)
		{
			cin >> student[j];
			sum += student[j];
		}

		sum /= num;

		int cnt = 0;
		for (int j = 0; j < num; j++)
			if (student[j] > sum) cnt++;

		cout.precision(3);
		cout <<fixed<< cnt / (double)num  *100<< '%' <<endl;
		
	}
}


//https://www.acmicpc.net/source/3682659