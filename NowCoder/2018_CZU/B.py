def dfs(n, m):
    return 1 + (dfs(n >> 1, m >> 1) << 2) if n & 1 and m & 1 else 0

def main():
    n, m  = map(int,input().split())
    print (dfs(n, m))

if __name__ == '__main__':
    main()