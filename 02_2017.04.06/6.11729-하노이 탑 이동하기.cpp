#include<cstdio>
#include<cmath>
int N;
void input() {
	scanf("%d", &N);
}

void Hanoi(int from , int to , int temp, int floor) {

	if (floor == 1)
	{
		printf("%d %d\n", from , to);
		return;
	}

	Hanoi(from,temp,to,floor - 1);
	printf("%d %d\n", from, to);
	Hanoi(temp, to, from, floor - 1);
}

void proccess() {
	printf("%.lf\n", pow(2, N) - 1);
	Hanoi(1,3,2,N);
}

int main() {
	input();
	proccess();
}