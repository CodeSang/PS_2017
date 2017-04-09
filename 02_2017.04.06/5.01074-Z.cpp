#include<cstdio>
#include<cmath>
using namespace std;


int output(int N, int r, int c) {

	if (N == 0 )
		return 0;

	int N2 = pow(2 , (N - 1));

	if (r >= N2 && c >= N2)
		return N2 * N2 * 3 + output(N - 1, r - N2, c - N2);
	else if (r >= N2)
		return N2 * N2 * 2 + output(N - 1, r - N2, c);
	else if (c >= N2)
		return N2 * N2 * 1 + output(N - 1, r	 , c - N2);
	else
		return output(N - 1, r, c);
}

int main() {
	int N, r, c;
	while (scanf("%d %d %d", &N, &r, &c) == 3)
	{
		printf("%d\n", output(N,r,c));
	}
}