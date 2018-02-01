#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 200000 + 100;
bool vis[maxn];
queue<int> a;
stack<int> s;
int b = 1;
int arr[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, k;
    while (~scanf("%d%d", &n, &k))
    {
        int tmp;
        for (int i = 0; i < k; i++)
        {
            scanf("%d", arr + i);
            vis[arr[i]] = true;
            a.push(arr[i]);
        }
        while (b <= n)
        {
            if (!s.empty() && s.top() == b)
            {
                s.pop();
                b++;
            }
            else if (!a.empty())
            {
                s.push(a.front());
                a.pop();
            }
            else
            {
                if (s.empty())
                {
                    for (int j = k; j < n; j++)
                    {
                        arr[j] = (n + k) - j;
                    }
                    k = n;
                    b = n + 1;
                }
                else
                {
                    for (int j = s.top() - 1; j >= b; j--)
                    {
                        if (!vis[j])
                        {
                            vis[j] = true;
                            arr[k++] = j;
                        }
                        else
                        {
                            printf("-1\n");
                            return 0;
                        }
                    }
                    b = s.top();
                }
            }
        }
        if (!s.empty() || !a.empty() || k != n)
        {
            printf("-1\n");
            return 0;
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                printf("%d%c", arr[i], i == (k - 1) ? '\n' : ' ');
            }
        }
    }
}
