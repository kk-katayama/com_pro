# Modint  

一番使うライブラリと言っても過言ではない。mod M上での四則演算を定義した構造体。いつかのABC解説放送で見た実装を参考にしている。<<とかはオーバーロードしてないので標準出力の際は気をつけて。  

## ライブラリ  
[Modint](https://github.com/kk-katayama/com_pro/blob/master/Numerical/Mod/Modint/lib/Modint.cpp)  

## テンプレート引数  
modint\<MOD\> x の形で宣言。好きなMODをMODにいれてね。  

なお、デフォルトでusing mint = modint<1000000007> としてある。

## 関数  
### pow(int t)  
繰り返し二乗法でmodpowを求める。　　

### inv()  
逆元を求める。その実、pow(MOD-2)をしているだけなので、これを何回も計算するとTLEになることがある。前計算が可能ならしておく。  

### 除算  
逆元をかける。これも毎回逆元を計算していたらTLEになることがあるので、注意。気付きにくいエラーなので要注意。  
