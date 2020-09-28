# 中国剰余定理(CRT)  

x = r1 (mod m1)  
x = r2 (mod m2)  

を満たすxで0 <= x < lcm(m1, m2) を満たすものを返す。中国人はすごい。  

## ライブラリ  
[ライブラリ](https://github.com/kk-katayama/com_pro/blob/master/Numerical/CRT/lib/CRT.cpp)  

## 関数  
### CRT(r1, m1, r2, m2)  
返り値はpairの形で(r, m)。x = r (mod m) でm はlcm(m1, m2)。
