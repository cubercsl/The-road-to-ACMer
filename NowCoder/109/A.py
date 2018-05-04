import math

x, y, z = map(float, input().split())
ans = (math.sqrt(x * y / z) + math.sqrt(y * z / x) + math.sqrt(x * z / y)) * 4
print(int(ans)) 