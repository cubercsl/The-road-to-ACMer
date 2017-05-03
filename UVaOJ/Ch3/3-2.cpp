// Molar Mass, ACM/ICPC Seoul 2007, UVa1586

/*Sample Input
4
C
C6H5OH
NH2CH2COOH
C12H22O11
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		double sum = 0;
		char s[100];
		double arr[] = {12.010, 1.008, 16.000, 14.010};
		int a[4] = {0};
		cin >> s;

		for (int i = 0; i < strlen(s); i++)
		{
			if (s[i] == 'C')
				if (isdigit(s[i + 1]) && isdigit(s[i + 2]))
					a[0] += 10 * (s[i + 1] - '0') + (s[i + 2] - '0');
				else
					a[0] += isdigit(s[i + 1]) ? s[i + 1] - '0' : 1;
			if (s[i] == 'H')
				if (isdigit(s[i + 1]) && isdigit(s[i + 2]))
					a[1] += 10 * (s[i + 1] - '0') + (s[i + 2] - '0');
				else
					a[1] += isdigit(s[i + 1]) ? s[i + 1] - '0' : 1;
			if (s[i] == 'O')
				if (isdigit(s[i + 1]) && isdigit(s[i + 2]))
					a[2] += 10 * (s[i + 1] - '0') + (s[i + 2] - '0');
				else
					a[2] += isdigit(s[i + 1]) ? s[i + 1] - '0' : 1;
			if (s[i] == 'N')
				if (isdigit(s[i + 1]) && isdigit(s[i + 2]))
					a[3] += 10 * (s[i + 1] - '0') + (s[i + 2] - '0');
				else
					a[3] += isdigit(s[i + 1]) ? s[i + 1] - '0' : 1;
		}
		for (int i = 0; i < 4; i++)
			sum += arr[i] * a[i];
		cout << fixed << setprecision(3) << sum << endl;
	}
	return 0;
}
