# 木  

木は辺が頂点数-1で連結なグラフ。🌳  

## ライブラリ  
[Tree](https://github.com/kk-katayama/com_pro/blob/master/Graph/Tree/lib/Tree_temp.cpp)  

## 関数  
### コンストラクタ  
テンプレートには辺の重みの型を入れてね。  
1. 頂点数を渡して宣言。
2. 頂点数と重み無し辺の配列を渡して宣言。  
3. 頂点数と重み付き辺の配列を渡して宣言。  

### add_edge(int from, int to, X cost)  
from->toに重みcostの辺を追加。有向か無向かに気を付ける。  

### Make_root(int root)  
rootを根とする根付き木を作成。  

### Diameter()  
木の直径を返すよ。  
