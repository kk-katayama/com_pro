n=int(input())
s=list(input())
x=[]
y=[]
count=0
a=0

for i in range(n-2):
    print("**************")
    y=[]
    if x.count(s[i])!=0:
        if len(x)==10:
            break
        continue
    
    else:
        x.append(s[i])
        for j in range(i+1,n-1):
                for k in range(j+1,n):
                    v=s[j]+s[k]
                    a+=1
                    print(a)
                    if y.count(v)!=0:
                        continue
                    else:
                        y.append(v)
                        count+=1
                        

                
                        
                
print(a)        
    
print(count)

