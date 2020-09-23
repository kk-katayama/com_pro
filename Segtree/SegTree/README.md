# セグメントツリー  

beetさんの抽象化セグ木を参考に作成されておる。

## ライブラリ  
[segtree](https://github.com/kk-katayama/com_pro/blob/master/Segtree/SegTree/lib/SegTree.cpp)  

## コンストラクタ  
二項演算と単位元を渡して宣言。
```
auto f = [&](int a,int b){ return a+b;};  
ll id = 0;                                                                                                                                                              
SegTree<decltype(f),ll> seg(f,id);  
```
こんな感じ。

## 関数  
### init(int n)  
セグ木の初期化。引数はセグ木のサイズ。初期値はidentity。  

### build(vector<T> v)  
配列を渡してセグ木を初期化。initをしてからやってね。  

### dfs(int k)  
build用の再帰関数。外から触ることはないので気にしない。  

### update(int k, T a)  
k番目の要素をaに変更。O(logN)。

### add(int k, T a)  
k番目の要素にaを加算。O(logN)。  

### query(int a, int b, int k, int l, int r)  
半開区間[a, b)におけるクエリに答える。(k, l, r) = (0, 0, seg.size) を代入すればよし。

### show()  
デバッグ用。セグ木の様子を標準出力する。


