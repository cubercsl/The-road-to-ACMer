def main():
    n = int(input())
    cnt = 0
    for a in range(1, n + 1):
        for b in range(a, n + 1):
            c = (a ^ b)
            if(c >= b and c <= n and a + b > c):
                cnt += 1
    print (cnt)

if __name__ == '__main__':
    main()