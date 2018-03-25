t = input()
mod = 100000007
while True:
    try:
        x, a, y, b = map(int, input().split())
        print ("YES" if pow(x, a, mod) == pow(y, b, mod) else "NO")
    except:
        break
