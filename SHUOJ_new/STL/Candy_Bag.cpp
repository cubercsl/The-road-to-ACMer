#include <bits/stdc++.h>
#define input(n) while(cin >> n)
#define input_2(a, b) while(cin >> a >> b)
#define Tcase int T; cin >> T; while(T--)
#define clr(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x & -x)
#define Lson L, mid, node << 1
#define Rson mid + 1, R, node << 1 | 1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

struct node
{
    int num, id;
    bool operator < (const node &a) const
    {
        if (num == a.num)
            return id > a.id;
        return num < a.num;
    }
};

priority_queue<node, vector<node> > q;

int main()
{
    int n;
    scanf("%d", &n);
    while (!q.empty())
        q.pop();
    for (int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        node tmp = {num, i};
        q.push(tmp);
        tmp = q.top();
        q.pop();
        tmp.num--;
        q.push(tmp);
    }
    int ans[100010];
    while (!q.empty())
    {
        node tmp = q.top();
        q.pop();
        ans[tmp.id] = tmp.num;
    }
    printf("%d", ans[1]);
    for (int i = 2; i <= n; i++)
        printf(" %d", ans[i]);
    printf("\n");
}
