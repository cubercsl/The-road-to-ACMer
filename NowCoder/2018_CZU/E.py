def main():
    n, a, b, q = map(int, input().split())

    while True:
        try:
            l, r = map(int, input().split())
            print(int(a * (r - l + 1) + (b - a) * (l + r) * (r - l + 1) / (2 * n)))
        except:
            return

if __name__ == '__main__':
    main()