#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 17;
template <class T>
struct BIT
{
    T bit[N];
    BIT() { memset(bit, 0, sizeof(bit)); }
    void update(int x, T v)
    {
        for (; x < N; x += x & -x) bit[x] = max(bit[x], v);
    }
    T query(int x)
    {
        T ret = 0;
        for (; x; x -= x & -x) ret = max(ret, bit[x]);
        return ret;
    }
};

BIT<long long> bit;

int main()
{
    int n;
    cin >> n;
    map<pair<int, int>, long long> dic;
    for (int i = 0, x, y, z; i < n; i++)
    {
        cin >> x >> y >> z;
        dic[{x, y}] += z;
    }
    vector<tuple<int, int, long long> > vec;
    vector<int> tmp;
    for (auto& t : dic) vec.emplace_back(t.first.first, -t.first.second, t.second), tmp.push_back(t.first.second);
    sort(vec.begin(), vec.end());
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    int x, y;
    long long z;
    long long ans = 0;
    for (auto& t : vec)
    {
        tie(x, y, z) = t;
        y = -y;
        int id = lower_bound(tmp.begin(), tmp.end(), y) - tmp.begin() + 1;
        long long tt = bit.query(id - 1) + z;
        ans = max(ans, tt);
        bit.update(id, tt);
    }
    cout << ans << endl;
}