#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> v;

bool binary(int s, int e, int target)
{	
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (v[mid] == target) return true;
		if (v[mid] > target)
			e = mid - 1;
		else
			s = mid + 1;
	}	

	return false;
}

int main() {

	scanf("%d", &N);
	v.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	///

	int m, temp;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &temp);
		if (binary(0, N-1, temp))
			printf("1\n");
		else
			printf("0\n");
	}

}