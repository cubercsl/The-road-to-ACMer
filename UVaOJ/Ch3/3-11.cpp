// Kickdown, ACM/ICPC NEERC 2006, UVa1588

/*Sample Input
2112112112
2212112
12121212
21212121
2211221122
21212
*/

#include <bits/stdc++.h>
using namespace std;
char str1[202];
char str2[202];
int main()
{
	int i, j, len1, len2, x1, x2;
	while (cin >> str1 >> str2)
	{
		len1 = strlen(str1);
		len2 = strlen(str2);
		memset(str1 + len1, 0, sizeof(str1) - len1);
		memset(str2 + len2, 0, sizeof(str2) - len2);
		for (i = 0; i < len1; i++)
			str1[i] -= 48;
		for (i = 0; i < len2; i++)
			str2[i] -= 48;
		for (i = 0; i < len1; i++)
		{
			for (j = 0; j < len2; j++)
				if (str1[i + j] + str2[j] > 3)
					break;
			if (j == len2)
				break;
		}
		x1 = len2 + i;
		for (i = 0; i < len2; i++)
		{
			for (j = 0; j < len1; j++)
				if (str2[i + j] + str1[j] > 3)
					break;
			if (j == len1)
				break;
		}
		x2 = len1 + i;
		cout << max(max(len1, len2), min(x1, x2)) << endl;
	}
	return 0;
}
