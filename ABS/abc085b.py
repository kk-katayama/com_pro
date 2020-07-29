n = int(input())
a = [int(input()) for i in range(n)]
a.sort()
res = 1
for i in range(0, n-1):
    if a[i] != a[i+1]: res += 1
print(res)
