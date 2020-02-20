def dyn(n,d00,d01,d02,d03,d10,d11,d12,d13):
    D00 = d00 + d10*int(n != 0)
    D10 = d10*int(n==0)
    D01 = d00*9 + d10*(n-1+int(n==0)) + d01 + d11*int(n!=0)
    D11 = d10*(int(n!=0)) + d11*(int(n==0))
    D02 = d01*9 + d11*(n-1+int(n==0)) + d02 + d12*int(n!=0)
    D12 = d11*(int(n!=0)) + d12*(int(n==0))
    D03 = d02*9 + d12*(n-1+int(n==0)) + d03 + d13*int(n!=0)
    D13 = d12*(int(n!=0)) + d13*(int(n==0))
    return D00,D01,D02,D03,D10,D11,D12,D13

N = str(input())
K = int(input())
S = len(N)
D00=0
D01=0
D02=0
D03=0
D10=1
D11=0
D12=0
D13=0

for i in range(S):
    [D00,D01,D02,D03,D10,D11,D12,D13] = dyn(int(N[i]),D00,D01,D02,D03,D10,D11,D12,D13)

if K == 1:
    print(D01+D11)
elif K==2:
    print(D02+D12)
else:
    print(D03+D13)

