def main():
    T = int(input())
    for t in range(T):
        n = int(input())
        print((n // 2) * (n - n // 2))

if __name__ == '__main__':
    main()