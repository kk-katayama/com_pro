n, a, b = map(int,input().split())
res = 0
for val in range(1, n+1):
    x = val
    buf = 0
    while val > 0:
        buf += val % 10
        val //= 10
    if a <= buf and buf <= b:
        res += x
print(res)
