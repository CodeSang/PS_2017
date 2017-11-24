#include<iostream>
#include<string>
using namespace std;


int CustomHash(const char *str) {
	unsigned long hash = 5381;
	int c;
	while (c = *str++)
		hash = ((hash << 5) + hash) + c;
	return hash & 0x7FFFFFFF;
}


int main() {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		string str;
		cin >> str;

		int temp = 1;
		while (true)
		{
			string tempStr = str + " " + to_string(temp);
			if (CustomHash(tempStr.c_str()) % 10000 == 0) break;
			temp++;
		}

		cout << temp <<endl;

	}
	return 0;
}