import numpy as np
n = int(input())
res = [0]*(n+1)
for i in range(1,101):
    for j in range(1,101):
        for k in range(1,101):
            x = i*i + j*j + k*k + i*j + j*k + k*i
            if x <= n:
                res[x] += 1
for i in range(1,n+1):
    print(res[i])
