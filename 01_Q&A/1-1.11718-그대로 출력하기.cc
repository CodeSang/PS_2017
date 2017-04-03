#include<iostream>
#include<string>
#include<cstring>
#include<cstdio> // stdio.h

using namespace std;

int main() {
	char str[101];
	while(scanf("%[^\n]\n", str) == 1)
		printf("%s\n", str);
}