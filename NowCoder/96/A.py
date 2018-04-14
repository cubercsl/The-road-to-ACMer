def main():
    while True:
        try:
            print("yes" if input().lower() == "lovelive" else "no")
        except:
            break

if __name__ == '__main__':
    main()