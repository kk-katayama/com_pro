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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
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
  char c;
  int par;
  X depth;
  vector<Edge<X>> edge;
  vector<ll> num;
  ll fin;
  ll size;
  
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

  ll DFS(int v, int p) {
    //    cout << v << ":" << node[v].str << "\n";
    ll res = 0;
    for(auto next: node[v].edge) {
      int w = next.to;
      if(w == p) continue;
      if(node[w].fin > 0) {
	char c = node[w].c;
	node[v].num[(int)c - 'a'] += node[w].fin;
      }
      res += DFS(w, v);
    }
    res += node[v].fin;
    //    cout << v << ":" << node[v].str << "\n";    
    return node[v].size = res;
  }

  ll ans;
  vector<ll> m;
  
  void DFS2(int v, int p) {
    // cout << v << "\n";
    // for(auto val: m) {
    //   cout << val << " ";
    // }
    // cout << "\n";
    ll tmp = 0;
    char a = 'a';
    if(v != 0) {
      char c = node[v].c;
      ans += node[v].size * m[(int)c - 'a'];
      tmp = m[(int)c - 'a'];
      a = c;
      m[(int)c - 'a'] = 0;
    }
    rep(i,26) {
      m[i] += node[v].num[i];
    }
    for(auto next: node[v].edge) {
      int w = next.to;
      if(w == p) continue;
      DFS2(w, v);
    }
    rep(i,26) {
      m[i] -= node[v].num[i];
    }    
    m[(int)a - 'a'] += tmp;
  }
  
  void Show() {
    rep(i,11) {
      cout << "size = " << node[i].size << "\n";
      for(auto val: node[i].num) {
	cout << val << " ";
      }
      cout  << "\n";
    }
  }
  
  map<string,int> mp;
  
  void Build(vector<string> s) {
    rep(i,n) node[i].fin = 0;
    rep(i,n) node[i].num.assign(26, 0);
    int sn = s.size();
    int idx = 1;
    mp[""] = 0;
    rep(i,sn) {
      string tmp = "";
      rep(j,s[i].size()) {
	int old = mp[tmp];
	tmp.push_back(s[i][j]);
	if(mp[tmp] == 0) {
	  mp[tmp] = idx;
	  node[idx].c = tmp[tmp.size() - 1];
	  idx++;
	  add_edge(old, mp[tmp]); add_edge(mp[tmp], old);	  
	}
	if(j == s[i].size() - 1) {
	  node[mp[tmp]].fin++;
	}
      }
    }
  }

  ll Solve() {
    ans = 0;
    m.assign(26, 0);
    DFS2(0, -1);
    return ans;
  }
  
};

int main()
{
  int n; cin >> n;
  vector<string> s(n);
  rep(i,n) {
    cin >> s[i];
    reverse(s[i].begin(), s[i].end());
  }
  sort(s.begin(), s.end());

  Tree<ll> tr(1e+6 + 1);
  tr.Build(s);
  tr.DFS(0,-1);
  //  cout << tr.Solve() - n << "\n";
  return 0;
}
