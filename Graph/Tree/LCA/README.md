# 最近共通祖先(LCA)  

## ライブラリ  
[LCA](https://github.com/kk-katayama/com_pro/blob/master/Graph/Tree/LCA/LCA_temp.cpp)  

## 関数  
### fill_par()  
ダブリングのためのparentテーブルを埋める。これをしておかないといけない。  

### LCA(int u, int v)  
頂点uと頂点vの最近共通祖先を求める。O(log(N))？。  

### Distance(int u, int v)  
頂点uと頂点vの距離を求める。dist[u] + dist[v] - 2*dist[LCA(u, v)]。  
