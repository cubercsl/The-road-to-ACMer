def solve():
    s = input()
    a = int(s)
    b = 0
    s = s[::-1]
    for i in range(len(s)):
        if (s[i] == '4'):
            b += 10 ** i
    print(a - b, b)

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        print("Case #%d:" % (t + 1), end = ' ')
        solve()