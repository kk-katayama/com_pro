//----------------------------
// 抽象化セグ木
// 二項演算と単位元を渡して使ってね
///****例****************************
//  auto f = [&](int a,int b){ return a+b;}; // 二項演算:和
//  int id = 0; //単位元:0
//  SegTree<decltype(f),int> seg(f,id);
//************************************
//----------------------------

template <typename F,typename T>
struct SegTree{
  // 二項演算merge,単位元identify
  F merge; 
  T identity;
  int size;
  vector<T> dat;
  
  // 二項演算fと単位元idを渡して宣言する
  SegTree(F f,T id):merge(f),identity(id){}

  // データの要素の数nを渡して初期化、sizeはnより大きい2の冪乗
  void init(int n){
    size = 1;
    while(size<=n) size *= 2;
    dat.resize(size*2-1,identity);
  }

  // 配列を渡して0(n)で初期化
  void build(vector<T> vec){
    rep(i,vec.size()) dat[size-1+i] = vec[i];
    dfs(0);
  }
  
  T dfs(int k){
    if(k>=size-1) return dat[k];
    else return dat[k] = merge(dfs(2*k+1),dfs(2*k+2));
  }

  // index kの要素をaに変更
  void update(int k,T a){
    k += size - 1;
    dat[k] = a;
    while(k > 0){
      k = (k-1)/2;
      dat[k] = merge(dat[2*k+1],dat[2*k+2]);
    }
  }
  
  // index kの要素にaを加算
  void add(int k,T a){
    k += size - 1;
    dat[k] += a;
    while(k > 0){
      k = (k-1)/2;
      dat[k] = merge(dat[2*k+1],dat[2*k+2]);
    }
  }

  // 区間[a,b)に対するクエリに答える。(k,l,r)=(0,0,size)
  T query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return identity;
    
    if(a<=l&&r<=b) return dat[k]; 
    else return merge(query(a,b,2*k+1,l,(l+r)/2),query(a,b,2*k+2,(l+r)/2,r));
  }

  T query(int a,int b){
    return query(a, b, 0, 0, size);
  }

  // デバッグ用
  void show(){
    int index = 0;
    int num = 1;
    while(index<size){
      rep(i,num){
	if(dat[i+index]==identity) cout << "e ";
	else cout << dat[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
  }
  
  
};
// 平面走査で右下の領域の点を数える
// PlaneSca(n, q, vector<Point> v)
// n = 点のy座標の最大値
// q = クエリの数
// v = 点とクエリの集合
struct Point{
  int x,y; // 座標
  int t; // クエリの種類 0:点追加 1:数える
  int idx; // クエリのid
};
vi PlaneScan(const int &n, const int &q, vector<Point> &p) {
  // x の降順、yの昇順、クエリ番号の昇順に並べる
  sort(p.begin(), p.end(), [](Point a, Point b) {
			     if(a.x == b.x) {
			       if(a.y == b.y) {
				 return a.t < b.t;
			       }
			       // 下の境界を含まないなら return a.y > b.y;
			       return a.y < b.y;
			     }
			     return a.x > b.x;
			   });
  
  auto f = [&](int a,int b){ return a+b;}; // 二項演算:和
  int id = 0; //単位元:0
  SegTree<decltype(f),int> seg(f,id);

  seg.init(n);
  vi res(q);
  for(auto val:p) {
    int y = val.y;
    if(val.t == 0) {
      seg.add(y, 1);
    }
    else {
      // 上の境界を含まないなら seg.query(0, y);
      int r = seg.query(0, y+1);
      res[val.idx] = r;
    }
  }
  return res;
}
