def popcnt(n):
   c = (n & 0x5555555555555555) + ((n>>1) & 0x5555555555555555)
   c = (c & 0x3333333333333333) + ((c>>2) & 0x3333333333333333)
   c = (c & 0x0f0f0f0f0f0f0f0f) + ((c>>4) & 0x0f0f0f0f0f0f0f0f)
   c = (c & 0x00ff00ff00ff00ff) + ((c>>8) & 0x00ff00ff00ff00ff)
   c = (c & 0x0000ffff0000ffff) + ((c>>16) & 0x0000ffff0000ffff)
   c = (c & 0x00000000ffffffff) + ((c>>32) & 0x00000000ffffffff)
   return c
n = int(input())
s = input()
f = []
f.append(0)
M = 200000
for i in range(1,M+1):
    x = i
    cnt = 0
    while x > 0:
        x = x % popcnt(x)
        cnt += 1
    f.append(cnt)

    
buf = s.count('1')
if buf == 0:
    for i in range(n):
        if s[i] == '1':
            print(0)
        else:
            print(1)
else:
    a = buf + 1
    pow2a = []
    pow2a.append(1)
    for i in range(M):
        pow2a.append((pow2a[i]*2) % a)
    b = buf - 1
    pow2b = []
    pow2b.append(1)
    if buf != 1:
        for i in range(M):
            pow2b.append((pow2b[i]*2) % b)
    asum = 0
    for i in range(n):
        if s[i] == '1':
            asum = (asum + pow2a[n - 1 - i]) % a
    bsum = 0
    if buf != 1:    
        for i in range(n):
            if s[i] == '1':            
                bsum = (bsum + pow2b[n - 1 - i]) % b
    if buf == 1:
        for i in range(n):
            if s[i] == '1':
                print(0)
            else:
                x = (asum + pow2a[n - 1 - i]) % a
                print(f[x] + 1)
    else:
        for i in range(n):
            if s[i] == '1':
                x = (bsum - pow2b[n - 1 - i] + b) % b
                print(f[x] + 1)
            else:
                x = (asum + pow2a[n - 1 - i]) % a
                print(f[x] + 1)                
