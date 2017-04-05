#include<iostream>
using namespace std;


int main() {
	int M;
	cin >> M;

	int A = M / 3;
	if (M % 3) A++;

	int B = 0;


	if (M % 4 == 0)
	{

		while (true)
		{
			if (M % 4)break;
			M /= 4;
			B++;

		}
	}



	for (int i = 2; i <= M; i++)
	{
		if (M%i == 0)
		{

			while (true)
			{
				if (M%i)break;
				M /= i;
				B++;

			}
		}

	}

	cout << A << " " << B << endl;
}