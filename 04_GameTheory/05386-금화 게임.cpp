#include<iostream> 
using namespace std;

bool mat[111];

int main() {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		long long n, k;
		cin >> n >> k;

		mat[0] = false;

		for (int i = 1; i < k; i++)
		{
			mat[i] = !mat[i - 1];
		}
		mat[k] = true;
		long long ans = 0;		
		for (long long temp = 1LL; n - temp >= 0LL; temp *= k)
		{
			if (!mat[(n - temp) % (k + 1LL)])
			{
				ans = temp;
				break;
			}
			if (k == 1)break;
		}
		cout << ans << '\n';
	}

}