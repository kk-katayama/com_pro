#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
const ll MOD=1e+9+7;
struct mint{
  ll x;
  mint(ll x=0):x(x%MOD){}
  mint& operator+=(const mint a){
    if((x+=a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator-=(const mint a){
    if((x += MOD-a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator*=(const mint a){
    (x*=a.x)%=MOD;
    return *this;
  }
  mint operator+(const mint a) const{
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const{
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const{
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const{
    if(!t) return 1;
    mint a = pow(t>>1);
    a*=a;
    if(t&1) a*=*this;
    return a;
  }
  
  //for prime mod
  mint inv() const{
    return pow(MOD-2);
  }
  mint& operator/=(const mint a){
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const{
    mint res(*this);
    return res/=a;
  }
};



template <typename X>
struct Node{
  int idx;
  
  Node() = default;

  Node(int idx) : idx(idx) {}
};
template <typename X>
struct Edge{
  int from;
  int to;
  X cost;
  
  Edge() = default;

  Edge(int from, int to, X cost) : from(from), to(to), cost(cost) {}
};
template <typename X>
class Tree{
private:
  int n; // number of node
  vector<vector<Edge<X>>> edge; 

  mint dp[100010][2];
  
public:
  Tree() = default;

  Tree(int n) : n(n) {
    edge.resize(n);
  }

  Tree(int n, vector<int> a, vector<int> b) : n(n) {
    edge.resize(n);
    rep(i,n-1) {
      add_edge(a[i], b[i]);
      add_edge(b[i], a[i]);  // indirected edge
    }
  }

  Tree(int n, vector<int> a, vector<int> b, vector<X> c) : n(n) {
    edge.resize(n);
    rep(i,n-1) {
      add_edge(a[i], b[i], c[i]);
      add_edge(b[i], a[i], c[i]);  // indirected edge
    }
  }  

  void add_edge(int from, int to, X cost = 1) {
    edge[from].emplace_back(from, to, cost);
  }

  mint DFS(int v, int p, int color) {
    if(dp[v][color].x > 0) return dp[v][color];
    mint res(1);
    for(auto next: edge[v]) {
      int w = next.to;
      if(w == p) continue;
      if(color == 0) {
	res *= (DFS(w, v, 0) + DFS(w, v, 1));
      }
      else {
	res *= DFS(w, v, 0);
      }
    }
    return dp[v][color] = res;
  }
};

int main()
{
  int n;cin >> n;
  vector<int> a(n-1), b(n-1);
  rep(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  Tree<int> tr(n, a, b);
  cout << (tr.DFS(0, -1, 0) + tr.DFS(0, -1, 1)).x  << "\n";
  
  return 0;
}
