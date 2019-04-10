#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    a -= x;
    if (a < 0) return puts("No"), 0;
    if (a + b < y) return puts("No"), 0;
    if (a + b + c < y + z) return puts("No"), 0;
    puts("yes");
}