def main():
    x, y = map(int, input().split())
    print ("Yes" if (x - y + 1) >= 0 and (x - y + 1) % 2 == 0 and y > 1 or  x == 0 and y == 1  else "No")

if __name__ == '__main__':
    main()