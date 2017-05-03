// Crossword Answers, ACM/ICPC World Finals 1994, UVa232

/*Sample Input
2 2
AT
*O
6 7
AIM*DEN
*ME*ONE
UPON*TO
SO*ERIN
*SA*OR*
IES*DEA
0
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int r, c, puzzle = 0;
	char map[10][12];
	while (cin >> r)
	{
		if (r == 0)
			break;
		cin >> c;
		for (int i = 0; i < r; i++)
			cin >> map[i];

		// 标序号
		int cnt[10][12];
		int n = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (map[i][j] != '*')
					if (i == 0 || j == 0 || map[i - 1][j] == '*' || map[i][j - 1] == '*')
						cnt[i][j] = ++n;

		if (puzzle++)
			cout << endl;
		cout << "puzzle #" << puzzle << ":" << endl;

		// 输出行
		cout << "Across" << endl;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (map[i][j] != '*')
					if (j == 0 || map[i][j - 1] == '*')
					{
						cout << setw(3) << cnt[i][j] << ".";
						for (int k = j; k < c; k++)
						{
							if (map[i][k] == '*')
								break;
							cout << map[i][k];
						}
						cout << endl;
					}
		// 输出列
		cout << "Down" << endl;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (map[i][j] != '*')
					if (i == 0 || map[i - 1][j] == '*')
					{
						cout << setw(3) << cnt[i][j] << ".";
						for (int k = i; k < r; k++)
						{
							if (map[k][j] == '*')
								break;
							cout << map[k][j];
						}
						cout << endl;
					}
	}
	return 0;
}
