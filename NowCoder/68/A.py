import math

def main():
    t = input()
    while True:
        try:
            a, b = map(float, input().split())
            print ("counterclockwise" if math.sin(b - a) > 0 else "clockwise")
        except EOFError:
            break

if __name__ == '__main__':
    main()