//--------------------------------------
// 抽象化遅延セグ木
// 要素のマージ関数f, 作用素のマージ関数h, 要素に作用素を作用させる関数g, 作用素に区間の長さを作用させる関数p, 要素の初期値id1, 作用素の初期値id2を代入して宣言
//****例******
//  auto f = [&](ll a, ll b){ return min(a, b); };
//  auto h = [&](ll a, ll b){ return b; };
//  auto g = [&](ll a, ll b){ return b; };
//  auto p = [&](ll a, int b){ return a; };  
//  ll id1 = (1LL << 31) - 1;
//  ll id2 = (1LL << 31) - 1;
//  LST<decltype(f), decltype(h), decltype(g), decltype(p), ll, ll> lst(f, h, g, p, id1, id2);
//*********************
//-------------------------------------------------------------------------


template <typename F, typename H, typename G, typename P, typename T, typename E>
struct LST{
  F f; // 要素のマージ関数
  H h; // 作用素のマージ関数
  G g; // 要素に作用素を作用させる関数
  P p; // 作用素と区間の長さの関数
  T id1; // 要素の初期値
  E id2; // 作用素の初期値
  int size;
  vector<T> dat;
  vector<E> lazy;
  
  LST(F f, H h, G g, P p, T id1, E id2)
    :f(f), h(h), g(g), id1(id1), id2(id2), p(p){}

  void init(int n){
    size = 1;
    while(size<=n) size *= 2;
    dat.resize(size*2-1, id1);
    lazy.resize(size*2-1, id2);    
  }

  void build(vector<T> vec){
    rep(i,vec.size()) dat[size-1+i] = vec[i];
    dfs(0);
  }

  T dfs(int k){
    if(k>=size-1) return dat[k];
    else return dat[k] = f(dfs(2*k+1),dfs(2*k+2));
  }

  // 遅延評価
  void eval(int k,int l,int r){
    if(lazy[k] != id2){
      if(k<size-1){
	lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
	lazy[2*k+2] = h(lazy[2*k+2], lazy[k]);
      }
      dat[k] = g(dat[k], p(lazy[k], r-l));
      lazy[k] = id2;
    }
  }


  void update(int a,int b,T x,int k,int l,int r){
    eval(k,l,r);
    if(r<=a||b<=l) return ;
    if(a<=l&&r<=b){
      lazy[k] = h(lazy[k], x);
      eval(k,l,r);
    }
    else{
      update(a,b,x,2*k+1,l,(l+r)/2);
      update(a,b,x,2*k+2,(l+r)/2,r);
      dat[k] = f(dat[2*k+1],dat[2*k+2]);
    }
  }

  void update(int a, int b, T x) {
    update(a, b, x, 0, 0, size);
  }
  
  T query(int a,int b,int k,int l,int r){
    eval(k,l,r);
    if(r<=a||b<=l) return id1;

    if(a<=l&&r<=b) return dat[k];
    else return f(query(a,b,2*k+1,l,(l+r)/2),query(a,b,2*k+2,(l+r)/2,r));
  }

  T query(int a, int b) {
    return query(a, b, 0, 0, size);
  }

  void all_eval(){
    rep(i,2*size-1){
      eval(i,0,0);
    }
  }

  T get(int k){ return dat[size-1+k];}
  
  void show(){
    int index = 0;
    int num = 1;
    while(index<size){
      rep(i,num){
	if(dat[i+index]==id1) cout << "e ";
	else cout << dat[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
    index = 0;
    num = 1;
    while(index<size){
      rep(i,num){
	cout << lazy[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
  }
  

  
};
