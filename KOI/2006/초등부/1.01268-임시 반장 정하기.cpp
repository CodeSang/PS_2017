#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;


int N;
int mat[1001][5];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 5; j++)
			cin >> mat[i][j];

	int M = 0;
	int Midx;
	int cnt[1001] = { 0 };
	for (int i = 0; i < N; i++)
	{

		int temp = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < N; k++)
				if (mat[i][j] == mat[k][j]) cnt[k] = 1;

		for (int k = 0; k < N; k++)
			if (cnt[k] > 0) temp++;

		if (M < temp)
		{
			M = temp;
			Midx = i;
		}
	}

	cout << Midx + 1 << endl;
}