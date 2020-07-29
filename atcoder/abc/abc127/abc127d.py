n, m = map(int,input().split())
a = list(map(int,input().split()))
b = []
c = []
for i in range(m):
    bb, cc = map(int,input().split())
    b.append(bb)
    c.append(cc)

pairs = []
for i in range(n):
    pairs.append( (a[i], 1) )
for i in range(m):
    pairs.append( (c[i], b[i]) )

pairs.sort(reverse = True)

idx = 0
res = 0
for i in range(n):
    if pairs[idx][1]== 0:
        idx += 1
    p = list(pairs[idx])        
    res += p[0]
    p[1] -= 1
    pairs[idx] = tuple(p)
    
print(res)
    
    
