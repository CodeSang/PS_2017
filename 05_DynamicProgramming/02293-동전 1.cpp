#include<iostream>
using namespace std;

int N, K;
int mat[101];
int mem[10001];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> mat[i];

	mem[0] = 1;
	for (int i = 0; i < N; i++)
		for (int j = mat[i]; j <= K; j++)
			mem[j] += mem[j - mat[i]];

	cout << mem[K] << endl;
	return 0;
}