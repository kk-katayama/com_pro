# 最大公約数(GCD)  

ユークリッドの互除法で最大公約数を求めるよ。  

## ライブラリ  
[GCD](https://github.com/kk-katayama/com_pro/blob/master/Numerical/GCD/lib/gcd.cpp)  

## 関数  
### gcd(int a, int b)  
a,bの最大公約数を求める。計算量はO(log(min(a,b))) あってる？  

### lcm(int a, int b)  
a,bの最小公倍数を求める。lcm(a,b) = a*b/gcd(a,b)。
