import numpy as np
import sys
input = sys.stdin.readline

h,w,k,v = map(int,input().split())
a=np.array([list(map(int, input().split())) for i in range(h)])

np.cumsum(a, axis=0, out=a)
np.cumsum(a, axis=1, out=a)
a=np.insert(a, 0, 0, axis=1)
a=np.insert(a, 0, 0, axis=0)

ans2=0
# 縦と横の区間全探索　
for i in range(w+1):
    for j in range(i+1,w+1):
        if a[0,j]-a[0,i]+(j-i)*k>v:
            continue
        for l in range(h+1):
            for m in range(l+1,h+1):
                if (a[m,j]-a[m,i])-(a[l,j]-a[l,i])+(j-i)*(m-l)*k<=v:
                    ans2=max(ans2,(j-i)*(m-l))
print(ans2)

        
        
        
        



        
        
        
        



        
        
        
        

