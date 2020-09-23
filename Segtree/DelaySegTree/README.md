# 遅延評価セグメントツリー  

## ライブラリ  
[LazySegmentTree](https://github.com/kk-katayama/com_pro/blob/master/Segtree/DelaySegTree/lib/DelaySegTree.cpp)  

## コンストラクタ  
LST(F f, H h, G g, P p, T id1, E id2);  
要素のマージ関数f, 作用素のマージ関数h, 要素に作用素を作用させる関数g, 作用素に区間の長さを作用させる関数p, 要素の初期値id1, 作用素の初期値id2を代入して宣言。

## 関数  
ほとんど普通のセグ木と同じ。[こちら](https://github.com/kk-katayama/com_pro/tree/master/Segtree/SegTree)を参照。eval関数が追加されたのが違い。  

## 使用例  
### 区間更新、区間最小  
[verify](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F)  
```
  auto f = [&](ll a, ll b){ return min(a, b); };
  auto h = [&](ll a, ll b){ return b; };
  auto g = [&](ll a, ll b){ return b; };
  auto p = [&](ll a, int b){ return a; };
  ll id1 = (1LL << 31) - 1;
  ll id2 = (1LL << 31) - 1;
```

### 区間加算、区間合計  
[verify](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G)  
```
  auto f = [&](ll a, ll b){ return a+b; };
  auto h = [&](ll a, ll b){ return a+b; };
  auto g = [&](ll a, ll b){ return a+b; };
  auto p = [&](ll a, int b){ return a*b; };
  ll id1 = 0;
  ll id2 = 0;
```

### 区間加算、区間最小  
[verify](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H)  
```
  auto f = [&](ll a, ll b){ return min(a,b); };
  auto h = [&](ll a, ll b){ return a+b; };
  auto g = [&](ll a, ll b){ return a+b; };
  auto p = [&](ll a, int b){ return a; };
  ll id1 = 0;
  ll id2 = 0;
```

### 区間更新、区間合計  
[verify](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I)  
```
  auto f = [&](ll a, ll b){ return a+b; };
  auto h = [&](ll a, ll b){ return b; };
  auto g = [&](ll a, ll b){ return b; };
  auto p = [&](ll a, int b){ return a*b; };
  ll id1 = 0;
  ll id2 = -1001;
```
