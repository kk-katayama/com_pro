from itertools import combinations
mod=10**9+7
def solve(n,k,a):
  if min(a)>0:
    ans=1
    a.sort(reverse=1)
    for i in a[:k]:
      ans*=i
      ans%=mod
    return ans
  if max(a)<0:
    if k%2==0:
      a.sort()
      ans=1
      for i in a[:k]:
        ans*=i
        ans%=mod
      return ans
    else:
      a.sort(reverse=1)
      ans=1
      for i in a[:k]:
        ans*=i
        ans%=mod
      return ans
  if n==k:
    ans=1
    for i in a:
      ans*=i
      ans%=mod
    return ans
  if k==1:
    return max(a)
  if n-k==1:
    ans=1
    if a.count(0)>1:return 0
    p=[]
    m=[]
    for i in a:
      if i>0:p.append(i)
      elif i<0:m.append(i)
    if 0 in a:
      if len(m)%2==0:
        for i in a:
          if i==0:continue
          ans=(ans*i)%mod
      else:ans=0
    else:
      if len(m)%2==0:
        for i in sorted(p)[1:]+m:ans=(ans*i)%mod
      else:
        for i in p+sorted(m)[:-1]:ans=(ans*i)%mod
    return ans


  ans=1
  p=[]
  m=[]
  for i in a:
    if i<0:m.append(i)
    elif i>=0:p.append(i)
  p.sort()
  m.sort(reverse=1)

  while k>1:
    if k<=5:
      if len(p)>=10:p=p[-10:]
      if len(m)>=10:m=m[-10:]
      ans*=solve2(len(p)+len(m),k,m+p)
      ans%=mod
      k=0
      break
    if len(p)<2:
      ans*=m.pop()*m.pop()
      k-=2
    elif len(m)<2:
      ans*=p.pop()*p.pop()
      k-=2
    elif m[-1]*m[-2]>p[-1]*p[-2]:
      ans*=m.pop()*m.pop()
      k-=2
    else:
      ans*=p.pop()*p.pop()
      k-=2
    ans%=mod
  if k:
    ans*=p.pop()
  return ans
  print(ans%mod)

def solve2(n,k,a):
  ans=-10**20
  for c in combinations(range(n),k):
    anss=1
    for i in c:anss*=a[i]
    ans=max(ans,anss)
  return ans%mod

n,k=map(int,input().split())
a=list(map(int,input().split()))
print(solve(n,k,a))

"""
from random import randint
for i in range(10000):
  n=randint(1,10)
  k=randint(1,n)
  a=sorted([randint(-10,10)for _ in range(n)])
  print(n,k,a)
  ans1=solve(n,k,a)
  ans2=solve2(n,k,a)
  if ans1==ans2:print("ok")
  else:
    print("error")
    print(n,k)
    print(*a)
    print(ans1,ans2)
    exit()
"""
