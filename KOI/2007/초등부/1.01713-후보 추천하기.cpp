#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int N, M;

struct student {
	int old;
	int vote;
	int num;

	bool operator<(const student& left)
	{
		return this->num < left.num;
	}

};
vector<student> v;

int main() {

	cin >> N;
	cin >> M;

	int temp;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;

		if (v.size() < N)
		{
			bool chk = false;
			for (auto &iter : v)
			{
				if (iter.num == temp)
				{
					chk = true;
					iter.vote++;
				}
			}
			if(!chk) v.push_back({ i,1,temp });
		}
		else
		{
			bool chk = false;
			int oldidx = 0;
			int vote = INT32_MAX;
			int old = 0;

			for (int j =0; j < v.size(); j++)
			{
				if (v[j].num == temp)
				{
					chk = true;
					v[j].vote++;
					break;
				}else if (v[j].vote < vote)
				{
					vote = v[j].vote;
					old = v[j].old;
					oldidx = j;
				}
				else if (v[j].vote == vote)
				{
					if (old > v[j].old)
					{
						old = v[j].old;
						oldidx = j;
					}
				}
			}

			if (!chk) {
				v[oldidx].old = i;
				v[oldidx].vote = 1;
				v[oldidx].num = temp;
			}
		}
	}


	sort(v.begin(), v.end());
	for (auto iter : v)
		cout << iter.num << " ";
	cout << endl;
}