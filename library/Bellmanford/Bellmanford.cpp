//最短経路問題。全ての辺についてのループを全ての頂点の数だけ回す(最悪のケース)。O(V*E)
//負のコストをもつ辺があっても適用可能。
struct edge{//辺の情報
  int from,to,cost;
};
int V,E;//頂点の数、辺の数
edge e[1001];
int d[1001];//d[v]は始点から頂点vまでの最短距離
bool update;
void bellmanford(int s){//始点sからスタート
  for(int i=0;i<V;i++) d[i]=INF;//初期化
  d[s]=0;
  for(int j=0;j<V;j++){
    update=false;//更新したか否かのフラグ
    for(int i=0;i<E;i++){//全エッジについてループ
      int f=e[i].from,t=e[i].to,c=e[i].cost;
      if(d[f]!=INF&&d[t]>d[f]+c){//更新
	d[t]=d[f]+c;
	update=true; 
      }
    }
    if(!update) break;
  }
}
//負閉路の検出
bool find_negative_loop(){
  for(int i=0;i<V;i++) d[i]=0;//初期化
  for(int i=0;i<V;i++){
    for(int j=0;j<E;j++){//全辺についてループ
      int f=e[i].from,t=e[i].to,c=e[i].cost;
      if(d[t]>d[f]+c){
	d[t]=d[f]+c;
	if(i==V-1) return true; //V回目にも更新があるなら負閉路が存在する
      }
    }
  }
  return false;
}


