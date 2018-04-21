import math
n, x, y = map(int, input().split())
print ("Yes" if n % math.gcd(x, y) == 0 else "No")