import sys
n, y = map(int, input().split())
for i in range(0, n+1):
    for j in range(0, n+1):
        if i + j > n: continue
        if 10*i + 5*j + (n - i - j) == y // 1000:
            print(i, j, n - i - j)
            sys.exit()
print(-1, -1, -1)
