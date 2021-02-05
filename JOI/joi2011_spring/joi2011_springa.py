import sys
h,w = map(int, input().split())
s = [list(map(int, input().split())) for i in range(h)]

yoko = [[0] * 3 for i in range(h)]
tate = [[0] * 3 for i in range(w)]

for i in range(h):
    for j in range(w):
        yoko[i][s[i][j]] += 1
        tate[j][s[i][j]] += 1

res = 0
for i in range(h):
    for j in range(w):
        if s[i][j] == 0:
            res += yoko[i][1] * tate[j][2]
            res += yoko[i][2] * tate[j][1]
        if s[i][j] == 1:
            res += yoko[i][0] * tate[j][2]
            res += yoko[i][2] * tate[j][0]
        if s[i][j] == 2:
            res += yoko[i][1] * tate[j][0]
            res += yoko[i][0] * tate[j][1]            

print(res//2)        
