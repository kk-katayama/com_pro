#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
template <typename T>
struct SegTree{
  // 二項演算merge,単位元identify
  using F = function<T(T, T)>;
  F merge;
  T identity;
  int size;
  vector<T> dat;
  
  // 二項演算fと単位元idを渡して宣言する
  SegTree() = default;

  SegTree(F f, T id) : merge(f), identity(id) {}
  
  // データの要素の数nを渡して初期化、sizeはnより大きい2の冪乗
  void init(int n){
    size = 1;
    while(size<=n) size *= 2;
    dat.resize(size*2-1,0);
    merge = [](T a, T b)-> T{ return max(a, b); };
    identity = 0;
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

  // 区間[a,b)に対するクエリに答える。(k,l,r)=(0,0,size)
  T query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return 0;
    
    if(a<=l&&r<=b) return dat[k]; 
    else return merge(query(a,b,2*k+1,l,(l+r)/2),query(a,b,2*k+2,(l+r)/2,r));
  }
  
  void show(){
    int index = 0;
    int num = 1;
    while(index<size){
      rep(i,num){
	if(dat[i+index]==0) cout << "e ";
	else cout << dat[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
  }
  
};

vector<int> compress(vector<int> a) {
  int n = a.size();
  vector<int> vals;
  rep(i,n) vals.push_back(a[i]);

  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  vector<int> res;
  rep(i,n) {
    int id = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    res.push_back(id+1);
  }

  return res;
}

//*******************************************************
// Tree
//*******************************************************

// status of edge
template <typename X>
struct Edge{
  int from;
  int to;
  X cost;

  Edge() = default;

  Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
};

//status of node
template <typename X>
struct Node{
  int idx;
  int par;
  X depth;
  vector<Edge<X>> edge;
  int val;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {
  }
  
};

// tree
template <typename X>
class Tree{
private:
  int n; // number of node
  vector<Node<X>> node;
  vector<int> res;
  SegTree<int> seg;
  
  void Init_Node() {
    rep(i,n) node.emplace_back(i);    
  }
  
public:
  Tree() = default;

  explicit Tree(int n) : n(n) {
    Init_Node();
  }

  // no-weight
  Tree(int n, vector<int> a, vector<int> b) : n(n) {
    Init_Node();
    rep(i,n-1) {
      add_edge(a[i], b[i]);
      add_edge(b[i], a[i]);  // indirected edge
    }
  }

  Tree(int n, vector<int> a, vector<int> b, vector<X> c) : n(n) {
    Init_Node();
    rep(i,n-1) {
      add_edge(a[i], b[i], c[i]);
      add_edge(b[i], a[i], c[i]);  // indirected edge
    }
  }  

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost);
  }

  void DFS_Init(int v, int p, int d) {
    node[v].par = p;
    node[v].depth = d;
    for(auto next: node[v].edge) {
      int w = next.to;
      X cost = next.cost;
      if(w == p) continue;
      DFS_Init(w, v, d + cost);
    }
  }

  // make rooted tree
  void Make_root(int root) {
    DFS_Init(root, -1, 0);
  }

  void DFS(int v, int p, int ans) {
    int old = seg.query(node[v].val, node[v].val+1, 0, 0, seg.size);
    int x = seg.query(0, node[v].val, 0, 0, seg.size);
    seg.update(node[v].val, x+1);
    chmax(ans, x+1);
    res[v] = ans;
    for(auto next: node[v].edge) {
      int w = next.to;
      if(w == p) continue;
      DFS(w, v, ans);
    }
    seg.update(node[v].val, old);
  }
  
  void solve(vector<int> a) {
    res.resize(n);
    rep(i,n) node[i].val = a[i];
    seg.init(n+2);
    DFS(0, -1, 0);
    rep(i,n) cout << res[i] << "\n";
  }
  
};

int main()
{
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<int> u(n-1), v(n-1);
  rep(i,n-1) {
    cin >> u[i] >> v[i];
    u[i]--; v[i]--;
  }
  
  a = compress(a);

  Tree<int> tr(n, u, v);
  tr.solve(a);
  return 0;
}
