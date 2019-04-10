from math import *
import string

def solve():
    n, l = map(int, input().split())
    a = list(map(int, input().split()))
    b = [0] * (l + 1)
    p = []
    for i in range(1, l):
        if (a[i] != a[i - 1]):
            g = gcd(a[i], a[i - 1])
            p.append(g)
            p.append(a[i - 1] // g)
            p.append(a[i] // g)
            b[i] = g
            b[i - 1] = a[i - 1] // g
            b[i + 1] = a[i] // g
    p = list(set(p))
    p.sort()
    for i in range(1, l + 1):
        if (b[i] == 0 and b[i - 1] != 0):
            b[i] = a[i - 1] // b[i - 1]
    for i in range(l - 1, -1, -1):
        if (b[i] == 0 and b[i + 1] != 0):
            b[i] = a[i + 1] // b[i + 1]    
    dic = {}
    for ch, index in zip(string.ascii_uppercase, range(26)):
        dic[p[index]] = ch
    s = ''
    for it in b:
        s += dic[it]
    print(s)

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        print("Case #%d:" % (t + 1), end = ' ')
        solve()