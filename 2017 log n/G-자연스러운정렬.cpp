#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N;
vector<string> str;

bool cmp(string left, string right)
{
	int lindex = 0, rindex = 0;

	while (lindex < left.length() && rindex < right.length())
	{
		long long ltemp = INT64_MAX;
		long long rtemp = INT64_MAX;

		while (lindex < left.length()  && left[lindex] >= '0' && left[lindex] <= '9') {

			if (ltemp == INT64_MAX) ltemp = 0;


			ltemp *= 10LL;
			ltemp += (long long)(left[lindex] -'0');
			lindex++;
		}

		while (rindex < right.length()  && right[rindex] >= '0' && right[rindex] <= '9') {

			if (rtemp== INT64_MAX) rtemp = 0;
			rtemp *= 10LL;
			rtemp += (long long)(right[rindex]-'0');
			rindex++;
		}

		if (ltemp != INT64_MAX || rtemp != INT64_MAX)
		{
			if (ltemp == rtemp) continue;
			return ltemp < rtemp;
		}
		
		if(left[lindex] != right[rindex])
			return left[lindex] < right[rindex];

		lindex++;
		rindex++;
	}

	return (lindex - left.length() < rindex - right.length());
}

int main() {
	
	cin >> N;
	str.resize(N);
	for (int i = 0; i < N; i++)
		cin >> str[i];

	sort(str.begin(), str.end(), cmp);

	for (int i = 0; i < N; i++)
		cout << str[i] << '\n';

	return 0;
}