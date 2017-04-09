#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int histogram[100001];

long long divideConquer(int l, int r) {
	long long ans = 0;
	if (l == r) return histogram[l];
	ans = max(divideConquer(l,(l+r )/2), divideConquer((l + r) / 2 + 1 , r));
	int left  = (l + r) / 2;
	int right = (l + r) / 2 + 1;
	long long minLength = min(histogram[left], histogram[right]);
	ans = max(ans, minLength * 2);
	while (l < left || right < r)
	{
		if ( l <= left &&( right == r || histogram[left-1] > histogram[right+1])) {
			left--;
			minLength = min(minLength, (long long)histogram[left]);
		}
		else{
			right++;
			minLength = min(minLength, (long long)histogram[right]);
		}
		ans = max(ans, minLength * (long long)(right - left + 1));
	}
	return ans;
}

int main() {
	while (true) {
		cin >> N;
		if (N == 0) return 0;
		for (int i = 1; i <= N; i++)
			cin >> histogram[i];
		cout << divideConquer(1, N) << '\n';
	}
}