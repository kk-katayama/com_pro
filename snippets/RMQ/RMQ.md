# RMQ(Range Minimum Query)

セグメント木によるRMQ。    
蟻本p.153  

ある数列に対して区間の最小値(最大値)をO(logN)で求めたい時に使うといいよ  
MinimumでもMaximumでもRMQ  

## RMQ.cpp
#### メンバ変数
* int dat[NMAX*2-1];  
セグメント木を構成する配列  
節点
* int nn;  
#### メンバ関数    
* RMQ(int n_);  
初期化、簡単のため要素数を2のべき乗にする.  
nnを　n_<=nn を満たす最小の2のべき乗の数にする.  
* void update(int k,int a);  
k番目の値(0-indexed)をaに変える.    
葉から登りながら更新していく.  
最大値が返したかったらmin→maxで良い.
* int query(int a,int b,int k,int l,int r);
[a,b) の最小値(最大値)を返す.  
k,l,rは現在どの節点を見ているかを表しており、kはその節点番号、その節点が表す区間が[i,r)である.  
外からはquery(a,b,0,0,n)のように呼ぶ.  

*何をしているか*
[a,b)と[l,r)が交差していない→その区間は無視  
[a,b)に[l,r)が完全に含まれている→その節点のもつ値が答えである  
それ以外、その節点の子2つでqueryを呼び出してその最小値を返す  
