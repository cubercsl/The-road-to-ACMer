// Just a Hook HDU1698

/*Sample Input
1
10
2
1 5 2
5 9 3
*/

#include <bits/stdc++.h>
using namespace std;
#define Lson L, M, node << 1
#define Rson M + 1, R, node << 1 | 1

const int maxn = 1e5 + 20;
int col[maxn << 2]; //用来标记每个节点，为0则表示没有标记，否则为标记，以颜色的价值作为标记。
int sum[maxn << 2]; //求和

void PushUp(int node) //向上更新和
{
	sum[node] = sum[node << 1] + sum[node << 1 | 1];
}

void PushDown(int node, int m) // 对某一个区间进行改变，如果被标记了，在查询的时候就得把改变传给子节点，因为查询的并不一定是当前区间
{							   // m为区间长度
	if (col[node])			   // 已经标记过，该区间被改变过
	{
		col[node << 1] = col[node << 1 | 1] = col[node]; // 标记子节点
		sum[node << 1] = (m - (m >> 1)) * col[node];	 // 更新左儿子的和
		sum[node << 1 | 1] = (m >> 1) * col[node];		 // 更新右儿子的和
		col[node] = 0;
	}
}

void build(int L, int R, int node)
{
	col[node] = 0; // 初始化为所有节点均未标记
	sum[node] = 1; // 初始值为1
	if (L == R)
		return;
	int M = (L + R) >> 1;
	build(Lson);
	build(Rson);
}

void update(int x, int y, int c, int L, int R, int node)
{
	if (x <= L && R <= y)
	{
		col[node] = c;
		sum[node] = c * (R - L + 1); // 更新代表某个区间的节点和，该节点不一定是叶子节点
		return;
	}
	PushDown(node, R - L + 1); // 向下传递
	int M = (L + R) >> 1;
	if (x <= M)
		update(x, y, c, Lson); // 更新左儿子
	if (y > M)
		update(x, y, c, Rson); // 更新右儿子
	PushUp(node);			   // 向上传递更新和
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int N, Q;
		scanf("%d", &N);
		build(1, N, 1);
		scanf("%d", &Q);
		while (Q--)
		{
			int add, x, y;
			scanf("%d%d%d", &x, &y, &add);
			update(x, y, add, 1, N, 1);
		}
		printf("Case %d: The total value of the hook is %d.\n", i, sum[1]);
	}
	return 0;
}
