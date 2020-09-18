# グラフにおける橋を検出する<br>

## 橋とは <br>
取り除くとグラフが連結でなくなる辺のこと。<br>

### 簡単にアルゴリズム解説<br>
グラフをDFSする時にそれぞれの頂点を何番目に訪れたかを記録しておく。<br>
```pre[v] := DFSで頂点vを訪れた順番```<br>
また、頂点vからDFSで辿れる頂点wのうち最小のpre[w]をlow[v]としておく。すると、辺(v,w)が橋であるという条件は、pre[v] < low[w]となる。
頂点vの祖先(とv自身)のpreはpre[v]以下である。また、low[w]は頂点wから辿れる最も古い祖先であるといえる。
low[w]がpre[v]以下であるとき、頂点wからは辺(v,w)以外で頂点vの祖先にたどり着けるということになる。その場合、辺(v,w)を取り除いても(v,w)は連結であるといえるので辺(v,w)は橋ではない。
逆にwからvの祖先にたどり着けない場合は、(v,w)を取り除くとvとwは連結ではなくなるので、(v,w)は橋である。

### ライブラリ <br>
[Bridge.cpp](https://github.com/kk-katayama/com_pro/blob/master/Graph/Bridge/Bridge.cpp)

### これを使う問題 <br>
[AOJ GRL 3B](https://github.com/kk-katayama/com_pro/blob/master/Graph/Bridge/GRL_3b.cpp) <br>
[ABC075C](https://github.com/kk-katayama/com_pro/blob/master/Graph/Bridge/abc075.cpp) <br>

## 関節点とは <br>
取り除くとグラフが連結でなくなる辺のこと。<br>

### 簡単にアルゴリズム解説<br>
大体橋と同じ。頂点vが関節点であるための条件はvの、ある子wについてpre[v] <= low[w]であれば良い。
pre[v] <= low[w]であるとき、wからは高々vまでしか古い祖先を辿れないのでvが潰れると、v以前の祖先にアクセスすることができなくなる。
vがDFSの根であるときは注意が必要。v以前の祖先が存在しないので。その場合は簡単に、vの子が2つ以上あればvは関節点であるということができる。

### ライブラリ <br>
[AirPoint.cpp](https://github.com/kk-katayama/com_pro/blob/master/Graph/Bridge/Bridge.cpp)

### これを使う問題 <br>
[AOJ GRL 3A](https://github.com/kk-katayama/com_pro/blob/master/Graph/Bridge/GRL_3a.cpp) <br>

てかまとめればいい気がする


