T = int(input())
for t in range(T):
    s, a, b, c = map(int, input().split())
    ans = s // c
    print(ans + ans // a * b)