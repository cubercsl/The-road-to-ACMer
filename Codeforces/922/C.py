import math

def main():
    n, k = map(int, input().split())
    if k > 43:
        print('No')
    else:
        lcm = 1
        for i in range(1, k + 1):
            lcm = i * lcm // math.gcd(i, lcm)
        print ("Yes" if (n + 1) % lcm == 0 else "No")

if __name__ == '__main__':
    main()