#include <iostream>

using namespace std;

int arrn[100] = {};

int main()
{
	int t, v,result = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> arrn[i];
	}
	cin >> v;
	for (int i = 0; i < t; i++)
	{
		if (arrn[i] == v)
			result++;
	}
	cout << result;
}