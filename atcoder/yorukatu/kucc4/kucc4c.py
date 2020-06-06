import collections

s1=list(input())
s2=list(input())
s3=list(input())
n=len(s1)//2

s1=collections.Counter(s1)
s2=collections.Counter(s2)
s3=collections.Counter(s3)
flag=True
# どっちの数を最大,最小どれだけ取れるか？
s1cnt = 0
s2cnt = 0
for i in s3:
    if s1[i] + s2[i] < s3[i]:
        flag=False
        break
    else:
        s1cnt += max(0, s3[i] - s2[i])
        s2cnt += max(0, s3[i] - s1[i])

if not flag:
    print('NO')

else:
    if s1cnt <= n and s2cnt <= n:
        print('YES')
    else:
        print('NO')
