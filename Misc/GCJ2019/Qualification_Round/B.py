def solve():
    n = int(input())
    s = input()
    s = s.replace('E', 'e')
    s = s.replace('S', 'E')
    s = s.replace('e', 'S')
    print(s)

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        print("Case #%d:" % (t + 1), end = ' ')
        solve()