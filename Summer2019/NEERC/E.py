n, k = map(int, raw_input().split())
dic = {}
for i in range(k):
    s = raw_input().split()
    try:
        dic[s[-1]] = max(dic[s[-1]], len(s))
    except:
        dic[s[-1]] = len(s)
ans = 0
for value in dic.values():
    ans += value
# print(ans)
if ans <= n:
    print('YES')
else:
    print('NO')