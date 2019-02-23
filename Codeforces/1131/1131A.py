w1,h1, w2, h2 = map(int, input().split())
print(2 * (w1 + 2) + h1 * 2 - w2 + (h2 - 1) * 2 + w2 + 2)