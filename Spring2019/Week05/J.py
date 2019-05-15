import math
a, b, c, d = map(int, input().split())
p = (a + b + c + d) / 2
print(math.sqrt((p - a) * (p - b) * (p - c) * (p - d)))
