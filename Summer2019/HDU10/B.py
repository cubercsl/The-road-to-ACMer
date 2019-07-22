import math
h = [2, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
b = [0] * 20
a = [0] * 20
for i in range(3, 20):
    h[i] = 4 * h[i - 1]  + 17 * h[i - 2] - 12 * h[i - 3] - 16
for i in range(1, 19):
    b[i] = 3 * h[i + 1] * h[i] + 9 * h[i + 1] * h[i - 1] + 9 * h[i] * h[i] + 27 * h[i] * h[i - 1] - 18 * h[i + 1] - 126 * h[i] - 81 * h[i - 1] + 192
for i in range(2, 19):
    a[i] = b[i] + (4 ** i)
    print(int(math.sqrt(a[i])) % (10 ** 9 + 7))