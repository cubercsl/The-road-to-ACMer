def main():
    T = int(input())
    for t in range(T):
        n = int(input())
        ans = 0
        while n:
            ans += n // 5
            n //= 5
        print (ans)

if __name__ == '__main__':
    main()