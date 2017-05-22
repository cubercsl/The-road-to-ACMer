// DNA Consensus String, ACM/ICPC Seoul 2006,UVa1367

/*Sample Input
3
5 8
TATGATAC
TAAGCTAC
AAAGATCC
TGAGATAC
TAAGATGT
4 10
ACGTACGTAC
CCGTACGTAG
GCGTACGTAT
TCGTACGTAA
6 10
ATGTTACCAT
AAGTTACGAT
AACAAAGCAA
AAGTTACCTT
AAGTTACCAA
TACTTACCAA
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        char dna[50][1000];

        // 信息输入
        cin >> m >> n;
        for (int i = 0; i < m; i++)
            cin >> dna[i];

        // 统计次数
        int cnt[1000][4];
        memset(cnt, 0, sizeof(cnt));
        //0:A;1:C;2:G;3:T
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                switch (dna[j][i])
                {
                case 'A':
                    cnt[i][0]++;
                    break;
                case 'C':
                    cnt[i][1]++;
                    break;
                case 'G':
                    cnt[i][2]++;
                    break;
                case 'T':
                    cnt[i][3]++;
                    break;
                }
                
        // 找出次数最多的
        int flag[1000];
        for (int i = 0; i < n; i++)
        {
            int max = 0;
            for (int j = 0; j < 4; j++)
                if (cnt[i][j] > max)
                {
                    max = cnt[i][j];
                    flag[i] = j;
                }
        }

        // 输出答案
        char ans[1000];
        for (int i = 0; i < n; i++)
        {
            switch (flag[i])
            {
            case 0:
                ans[i] = 'A';
                break;
            case 1:
                ans[i] = 'C';
                break;
            case 2:
                ans[i] = 'G';
                break;
            case 3:
                ans[i] = 'T';
                break;
            }
            cout << ans[i];
        }
        cout << endl;

        // 输出距离
        int dis = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (ans[i] != dna[j][i])
                    dis++;
        cout << dis << endl;
    }
    return 0;
}
