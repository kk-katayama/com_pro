w = input()
f = True
for i in range(ord('a'),ord('z')+1):
    x = w.count(chr(i))
    if(x%2==1):
        f = False
if(f):
    print("Yes")
else:
    print("No")
