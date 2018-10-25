n, k = map(int, input().split())

dic = {}
arr = []
for i in range(n):
    s, t = input().split()
    dic[int(t)] = s
    arr.append(int(t))

ans = []
arr.sort(reverse=True)
for it in arr:
    if k >= it:
        ans.append(dic[it])
        k -= it

if k == 0:
    print(len(ans))
    for it in ans:
        print(it)
else:
    print(0)
