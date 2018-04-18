mod = 1000000009
def inv(x):
    return pow(x,mod - 2, mod)

n, a, b, k = map(int, input().split())
s = input()
q = pow(b, k, mod) * inv(pow(a, k, mod))
t = 0
for i in range(k):
    sgn = 1 if s[i] == '+' else -1
    t += sgn * pow(a, n - i, mod) * pow(b, i, mod)
    t %= mod
    t += mod
    t %= mod
print(((t * (1 - pow(q, (n + 1) // k, mod)) * inv(1 - q) % mod) + mod) % mod if q != 1 else (t * (n + 1) // k) % mod)
