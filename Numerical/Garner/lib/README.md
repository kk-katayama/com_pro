# Garnerのアルゴリズム  

Garnerさんのアルゴリズム。中国剰余定理の拡張版で、  

x = r1 (mod m1)  
x = r2 (mod m2)  
  :
x = rn (mod mn)  

を満たす最小のxを返す。  

## ライブラリ
[ライブラリ](https://github.com/kk-katayama/com_pro/blob/master/Numerical/Garner/lib/Garner.cpp)  

## 関数  
### Garner(vector<long long> r, vector<long long> m, long long mod)  
x = r[i] (mod m[i]) を満たすx を求め、x % mod を返す。計算量はO(|r|^2)。
