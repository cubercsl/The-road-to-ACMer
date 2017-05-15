#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		string name, max_name;
		int fin, cls, pas, money, max_money = 0, sum = 0;
		char m, w;
		bool moni, west;
		while (n--)
		{
			cin >> name >> fin >> cls >> m >> w >> pas;
			moni = m == 'Y' ? 1 : 0;
			west = w == 'Y' ? 1 : 0;
			money = 0;
			if (fin > 80 && pas >= 1)
				money += 8000;
			if (fin > 85 && cls > 80)
				money += 4000;
			if (fin > 90)
				money += 2000;
			if (fin > 85 && west)
				money += 1000;
			if (cls > 80 && moni)
				money += 850;
			sum += money;
			if (money > max_money)
			{
				max_money = money;
				max_name = name;
			}
		}
		cout << max_name << endl;
		cout << max_money << endl;
		cout << sum << endl;
	}
	return 0;
}
