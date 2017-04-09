#include<cstdio>
using namespace std;

int N, M;
int A[1000001];
int B[1000001];

int main() {
	
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < M; i++)
		scanf("%d", &B[i]);

	int a = 0, b = 0;

	while (a < N && b < M)
	{
		if (A[a] < B[b])
		{
			printf("%d ", A[a]);
			a++;
		}
		else {
			printf("%d ", B[b]);
			b++;
		}
	}

	if (a < N)
	{
		for(;a<N;a++)
			printf("%d ", A[a]);
	}
	else {
		for (; b<M; b++)
			printf("%d ", B[b]);
	}
}