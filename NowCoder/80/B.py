def main():
    mod = 998244353
    n, m = map(int, input().split())
    ans = m * pow(n * n, mod - 2, mod) % mod
    print(ans)

if __name__ == '__main__':
    main()