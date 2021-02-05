#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
// Modint
// modint<MOD> で宣言
template<ll MOD>
struct modint{
  ll x;
  ll mod = MOD;
  modint(ll x=0):x(x%MOD){}
  modint& operator+=(const modint a){
    if((x+=a.x)>=MOD) x-=MOD;
    return *this;
  }
  modint& operator-=(const modint a){
    if((x += MOD-a.x)>=MOD) x-=MOD;
    return *this;
  }
  modint& operator*=(const modint a){
    (x*=a.x)%=MOD;
    return *this;
  }
  modint operator+(const modint a) const{
    modint res(*this);
    return res+=a;
  }
  modint operator-(const modint a) const{
    modint res(*this);
    return res-=a;
  }
  modint operator*(const modint a) const{
    modint res(*this);
    return res*=a;
  }
  modint pow(ll t) const{
    if(!t) return 1;
    modint a = pow(t>>1);
    a*=a;
    if(t&1) a*=*this;
    return a;
  }
  
  //for prime mod
  modint inv() const{
    return pow(MOD-2);
  }
  modint& operator/=(const modint a){
    return (*this) *= a.inv();
  }
  modint operator/(const modint a) const{
    modint res(*this);
    return res/=a;
  }
};
using mint = modint<1000000007>;

//***********************************************************
// Dijkstra. You should include queue lib.
//***********************************************************

// status of edge
template <typename X>
struct Edge{ 
  int from; 
  int to;
  X cost;

  Edge() = default;

  Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
};

// status of node
template <typename X>
struct Node{ 
  int idx; // index of node
  vector<Edge<X>> edge;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
  
};


template <typename X = int>
struct Status{ // entered priority_queue
  int idx;
  X dist;

  Status() = default;

  Status(int idx, X dist) : idx(idx), dist(dist) {}

  bool operator == (const Status& r) const {
    return (idx == r.idx && dist == r.dist);
  }

  bool operator != (const Status& r) const {
    return !(*this == r);
  }

  bool operator < (const Status& r) const {
    return dist > r.dist;
  }

  bool operator > (const Status& r) const {
    return dist < r.dist;
  }

};

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<Node<X>> node; // node list

  void Init_Node() {
    rep(i,n) node.emplace_back(i);
  }  
public:
  vector<X> d;
  vector<int> prev;
  const X inf = 1e+9; // initial value of dist
  
  explicit Graph(int n) : n(n) {
    Init_Node();
  }

  // no-weight
  Graph(int n, int m, vector<int> from, vector<int> to) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(from[i], to[i]);
      add_edge(to[i], from[i]);      
    }
  }
  
  Graph(int n, int m, vector<int> from, vector<int> to, vector<X> cost) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(from[i], to[i], cost[i]);
     add_edge(to[i], from[i], cost[i]);      
    }
  }

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost);
  }



  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  vector<mint> num,num2;
  vector<X> d2;
  void dijkstra(int s, int t) { 
    // initalize d
    d.assign(n, infll);
    d2.assign(n, infll);    
    num.resize(n);
    num2.resize(n);    
    d[s] = 0;
    d2[t] = 0;    
    prev.assign(n, -1);
    num[s].x = 1;
    num2[t].x = 1;    
    priority_queue<Status<X>> pq;
    pq.emplace(s, 0); // pq have (node, shortest distance from start to the node)

    while( !pq.empty() ) {
      Status<X> now = pq.top(); pq.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      if(d[v] < dis) continue; 
      for(auto next: node[v].edge) {
  	    int w = next.to;
  	    X cos = next.cost;
        if(d[w] == d[v]+cos) {
          num[w] += num[v];
        }
    	  if(chmin(d[w], d[v] + cos)) {
  	      pq.emplace(w, d[w]);
    	    prev[w] = v;
          num[w] = num[v];
  	    }
      }
    }
    priority_queue<Status<X>> pq2;
    pq2.emplace(t, 0); // pq have (node, shortest distance from start to the node)

    while( !pq2.empty() ) {
      Status<X> now = pq2.top(); pq2.pop();
      int v = now.idx; // number of node
      X dis = now.dist; // distance of start from node "v"
      if(d2[v] < dis) continue; 
      for(auto next: node[v].edge) {
  	    int w = next.to;
  	    X cos = next.cost;
        if(d2[w] == d2[v]+cos) {
          num2[w] += num2[v];
        }
    	  if(chmin(d2[w], d2[v] + cos)) {
  	      pq2.emplace(w, d2[w]);
    	    prev[w] = v;
          num2[w] = num2[v];
  	    }
      }
    }

  }

  // s->t の最短経路復元
  vector<int> getpath(int t) {
    vector<int> res;
    for(; t != -1; t = prev[t]) {
      res.push_back(t);
    }
    reverse(res.begin(), res.end());
    return res;
  }
  
};

int main()
{
  int n,m; cin >> n >> m;
  int s,t; cin >> s >> t;
  s--; t--;
  vi a(m),b(m);
  vl c(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
  }
  Graph<ll> gp(n, m, a, b, c);
  gp.dijkstra(s,t);
//  rep(i,n) cout << i << ";" << gp.num[i].x << "\n";
  auto p2 = [&](mint tmp)->mint {
    return tmp*(tmp-mint(1));
  };
  ll dist = gp.d[t];
  mint res = p2(gp.num[t]);

  rep(i,n) {
    if(2*gp.d[i] == dist) {
      res -= p2(gp.num[i]*gp.num2[i]);
    }
  }

  rep(tmp,m) {
    int i = a[tmp], j = b[tmp];
    ll cos = c[tmp];
    if(gp.d[i] + gp.d2[j] + cos == dist && gp.d[i] <= (dist-1)/2 && gp.d2[j] <= (dist-1)/2) {
      res -= p2(gp.num[i]*gp.num2[j]);
    }
    if(gp.d[j] + gp.d2[i] + cos == dist && gp.d[j] <= (dist-1)/2 && gp.d2[i] <= (dist-1)/2) {
      res -= p2(gp.num[j]*gp.num2[i]);
    }    
  }
  cout << res.x << "\n";
  return 0;
}
