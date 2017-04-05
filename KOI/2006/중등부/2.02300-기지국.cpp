#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> point;
int N;

int mem[10011];
int Go(int s, int t) {

	if (mem[s] != -1) return mem[s];
	if (s > t) return 0;

	int my = min(0, point[s].second);
	int My = max(0, point[s].second);

	mem[s] = abs(point[s].second) * 2 + Go(s + 1, t);
	for (int i = s + 1; i <= t; i++)
	{
		my = min(my, point[i].second);
		My = max(My, point[i].second);
		int temp = max({ (point[i].first - point[s].first), abs(my) * 2,My * 2 });
		mem[s] = min(mem[s], temp + Go(i+1, t));
	}
	return mem[s];
}

int main() {
	memset(mem, -1, sizeof(mem));
	cin >> N;
	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		point.push_back({ x,y });
	}
	sort(point.begin(), point.end());
	cout << Go(0, N - 1) << endl;
}