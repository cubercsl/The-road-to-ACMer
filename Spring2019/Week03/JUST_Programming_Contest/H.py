import string
for i in range(int(input())):
    print("YES" if input() in string.ascii_lowercase * 40 else "NO")