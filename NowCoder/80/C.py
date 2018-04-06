def main():
    mod = 998244353
    p = int(input())
    f = 1
    for i in range(1, p):
        f = f * i
        f = f % mod
    ans = p * p % mod * f * f * 2 % mod
    print (ans)
    

if __name__ == '__main__':
    main()