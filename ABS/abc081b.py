n = int(input())
a = list(map(int, input().split()))
res = 100000
for val in a:
    cnt = 0
    while val % 2 == 0:
        val /= 2
        cnt += 1
    res = min(res, cnt)
print(res)
