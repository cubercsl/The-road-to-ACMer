s, c = 0, 0
while True:
    try:
        s += int(input())
        c += 1
    except:
        break
print(s / c * 2)