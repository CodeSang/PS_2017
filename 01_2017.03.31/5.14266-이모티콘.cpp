#include<iostream>
#include<queue>
using namespace std;


struct imoge{
	int now;
	int seconds;
	int clip;
};

bool chk[2111][2111];
int S;
int main() {
	cin >> S;
	queue<imoge> q;
	q.push({ 1,0,0 });
	while (!q.empty()) {

		auto iter = q.front();
		q.pop();

		if (iter.now > 1500) continue;
		if (chk[iter.now][iter.clip]) continue;
		chk[iter.now][iter.clip] = true;

		if (iter.now == S)
		{		
			cout << iter.seconds << endl;
			return 0;
		}

		// clip Board 복사

		if (iter.now != iter.clip)
			q.push({ iter.now, iter.seconds + 1, iter.now });

		// 화면 하나 삭제
		if (1 != iter.now)
			q.push({ iter.now - 1, iter.seconds + 1, iter.clip });

		// 붙여 넣기
		if (0 != iter.clip)
			q.push({ iter.now + iter.clip, iter.seconds + 1, iter.clip });

	}

}
