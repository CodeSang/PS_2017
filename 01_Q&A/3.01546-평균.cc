#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	vector<int> v;
	int M = 0;
	scanf("%d", &N);
	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &v[i]);
		M = max(M, v[i]);
	}

	double sum = 0;

	for (int i = 0; i < N; i++)
	{
		sum += (v[i] / (double)M) * 100.0;
	}

	printf("%0.2lf\n", sum / (double)N);
}