iin = raw_input
ran = xrange

#iin = input
#ran = range


maxn = 1600
mod = 998244353

fac = [0 for _ in ran(maxn)]
fac[0] = 1
fac[1] = 1
for i in ran(2, maxn):
    fac[i] = fac[i - 1] * i

def fromPermutation(arr):
    n = len(arr)
    result = 0
    for i in ran(n):
        x = 0
        for j in ran(i + 1, n):
            if arr[j] < arr[i]: x += 1
        result += x * fac[n - i - 1]
    return result
    
def toPermutation(n, index):
    arr = [0 for _ in ran(n)]
    visited = [False for _ in ran(n)]
    for i in ran(n):
        count = index // fac[n - i - 1]
        index %= fac[n - i - 1]
        for j in ran(n):
            if visited[j]: continue
            if count == 0:
                visited[j] = True
                arr[i] = j
                break
            count -= 1
    return arr

def getFirst(n):
    arr = [i for i in ran(n)]
    arr[0] = 1
    arr[1] = 0
    return arr

def getLast(n):
    return [n - i - 1 for i in ran(n)]

def fromNumber(n, x):
    arr = [0 for _ in ran(n)]
    for i in ran(n):
        arr[n - i - 1] = x % n
        x //= n
    return arr

def toNumber(arr):
    n = len(arr)
    x = 0
    for i in ran(n):
        x = x * n + arr[i]
    return x

first = [(getFirst(i) if i >= 2 else 0) for i in ran(maxn)]
last = [(getLast(i) if i >= 2 else 0) for i in ran(maxn)]
firstNumber = [(toNumber(first[i]) if i >= 2 else 0) for i in ran(maxn)]
lastNumber = [(toNumber(last[i]) if i >= 2 else 0) for i in ran(maxn)]
firstIndex = [(fac[i - 1] if i >= 2 else 0) for i in ran(maxn)]
lastIndex = [(fac[i] - 1 if i >= 2 else 0) for i in ran(maxn)]

def calc(x):
    result = 0
    for i in range(2, maxn):
        if firstNumber[i] > x: break
        elif lastNumber[i] <= x:
            result = (result + lastIndex[i] - firstIndex[i] + 1) % mod
        else:
            num = fromNumber(i, x)
            arr = [0 for _ in range(i)]
            visited = [False for _ in range(i)]
            for j in range(i):
                k = num[j]
                if visited[k]:
                    while visited[k]: k -= 1
                    arr[j] = k
                    visited[k] = True
                    index = i
                    for l in range(j + 1, i):
                        index -= 1
                        while visited[index]: index -= 1
                        arr[l] = index
                    break
                else:
                    arr[j] = k
                    visited[k] = True
                    index = -1
                    for l in range(j + 1, i):
                        index += 1
                        while visited[index]: index += 1
                        arr[l] = index
                    if toNumber(arr) > x:
                        visited[k] = False
                        k -= 1
                        while visited[k]: k -= 1
                        arr[j] = k
                        visited[k] = True
                        index = i
                        for l in range(j + 1, i):
                            index -= 1
                            while visited[index]: index -= 1
                            arr[l] = index
                        break
            index = fromPermutation(arr)
            result = (result + index - firstIndex[i] + 1) % mod
    return result

t = int(iin())

for _ in ran(t):
    l, r = map(int, iin().split())
    result = calc(r) - calc(l - 1)
    print(result)
