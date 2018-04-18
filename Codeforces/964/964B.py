n, a, b, c, t = map(int, input().split())
s = 0
for x in list(map(int,input().split())):
    s += t - x
print (n * a if b >= c else n * a + s * (c - b)) 
