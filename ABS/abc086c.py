import sys
n = int(input())
a = []
a.append((0, 0, 0))
for i in range(n):
    t, x, y = map(int, input().split())
    a.append((t, x, y))
for i in range(0, n):
    t = a[i+1][0] - a[i][0]
    x = abs(a[i+1][1] - a[i][1])
    y = abs(a[i+1][2] - a[i][2])
    if x + y > t or (x + y) % 2 != t % 2:
        print("No")
        sys.exit()
print("Yes")
