#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {

	int t; 
	cin >> t; 

	for (int i = 0; i < t; i++)
	{

		vector <pair <int, int >> ll;
		vector <pair <int, int >> ans;

		int N;
		cin >> N;

		for (int j = 0; j < N; j++)
		{
			int a, b;
			cin >> a >> b;

			ll.push_back({ a,b });
		}

		sort(ll.begin(), ll.end());


		for (int j = 0; j < ll.size(); )
		{
			int b = ll[j].first, e = ll[j].second;
			int k = j + 1;
			while (k < ll.size() && e >= ll[k].first) {

				e = max(e, ll[k].second);
				k++;

			}

			ans.push_back({b, e	});
			j = k;
		}

		cout << ans.size() << '\n';

		for (int j = 0; j < ans.size(); j++)
		{
			cout << ans[j].first << " " << ans[j].second;

			if (j + 1 == ans.size())break;
			cout << " ";
		}
		cout << '\n';

	}
	return 0;
}