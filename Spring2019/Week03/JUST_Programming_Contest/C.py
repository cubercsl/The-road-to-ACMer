for i in range(int(input())):
    n, m = map(int, input().split())
    print(2 if (n + m) & 1 else 12)
