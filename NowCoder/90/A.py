t = input();
while True:
    try:
        n = int(input())
        print (1 << (n - 1))
    except:
        break
