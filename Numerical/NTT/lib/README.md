# 数論変換(NTT)  

離散フーリエ変換(DFT)は、複素数に拡張して1の原始n乗根を持ってきた。特殊なmod上では、1の原始n乗根が知られており、それを使ってDFTを行う。
DFTの高速化については、高速フーリエ変換(FFT)の手続きと同じ。
これによって、特殊なmod上での畳み込みを高速に行うことができる。  

## 特殊なmodとは  

mod = 2^n * k + 1 を満たす整数。例えば、998244353。  


## ライブラリ  
[ライブラリ](https://github.com/kk-katayama/com_pro/blob/master/Numerical/NTT/lib/NTT_new.cpp)  

## 関数  
### ntt(vector\<T\> a, bool inverse = false)  
高速フーリエ変換をmod上で行う。modはtypenameで指定。inverse = trueで逆変換。これをあらわに使うことはないので別に知らなくても良い。  

### naive_convolve(vector\<long long\> a, vector\<long long\> b)  
特殊なmod上での畳み込み。テンプレート引数にはmodint<mod>を入れてあげる。特殊なmod上での畳み込みがしたかったら後のものよりこっちの方が早い。  

### convolve(vector\<long long\> a, vector\<long long\> b, long long mod)  
任意mod上での畳み込み。Garnerのアルゴリズムを使っている。遅い。  

### fast_convolve(vector\<long long\> a, vector\<long long\> b, long long mod)  
任意mod上での畳み込み。少し高速化されている。  
