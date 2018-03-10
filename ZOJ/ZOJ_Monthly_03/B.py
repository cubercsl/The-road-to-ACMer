def main():
    t = input()
    while t > 0:
        n = int(input())
        l , r = 0, 10**500
        ans = 0
        while l <= r:
            m = l + r >> 1
            if n < (m + 1) * (m + 1):
                ans = m & 1
                r = m - 1
            else:
                l = m + 1
        print ans
        t -= 1

if __name__ == '__main__':
    main()
