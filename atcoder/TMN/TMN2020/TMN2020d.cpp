#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
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
  int par;
  X depth;
  vector<Edge<X>> edge;
  int val,wei;
  vector<int> dp;
  vector<pi> p;
  bool flag;
  
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
    rep(i,n) {
      if(2*i + 1 < n) {
	add_edge(i, 2*i + 1);
	add_edge(2*i + 1, i);	
      }
      if(2*i + 2 < n) {
	add_edge(i, 2*i + 2);
	add_edge(2*i + 2, i);	
      }      
    }
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

  void Build(vector<int> v, vector<int> w) {
    rep(i,n) {
      node[i].val = v[i];
      node[i].wei = w[i];
    }
    node[0].p.push_back({0, 0});
    node[0].p.push_back({node[0].wei, node[0].val});    
    rep1(i,n-1) {
      if(pow(2,9) - 1 <= i && i < pow(2,10) - 1) {
	node[i].p.push_back({0,0});
	node[i].p.push_back({node[i].wei,node[i].val});	
      }
      else {
	int s = (i - 1) / 2;
	rep(j,node[s].p.size()) {
	  node[i].p.push_back(node[s].p[j]);
	  node[i].p.push_back({node[s].p[j].first + node[i].wei, node[s].p[j].second + node[i].val});
	}
      }
      sort(node[i].p.begin(), node[i].p.end());
      rep(j,node[i].p.size()-1) {
	if(node[i].p[j].second >= node[i].p[j+1].second){
	  node[i].p.erase(node[i].p.begin()+(j+1));
	  j--;
	}
      }
    }
  }

  void Solve(vector<int> v, vector<int> l) {
    // rep(i,n) {
    //   for(auto ppp: node[i].p) {
    // 	cout << ppp.first << ":" << ppp.second << "\n";
    //   }
    // }
    int q = v.size();
    rep(i,q) {
      int res = 0;
      if(pow(2,9) - 1 <= v[i] ){
	int s = v[i];
	while(pow(2,9) - 1 <= s) s = (s - 1) / 2;
	int right = node[v[i]].p.size() - 1;
	rep(left, node[s].p.size()) {
	  while(l[i] < node[s].p[left].first + node[v[i]].p[right].first) {
	    right--;
	    if(right < 0) break;
	  }
	  if(right < 0) break;
	  chmax(res, node[s].p[left].second + node[v[i]].p[right].second);
	}
	cout << res << "\n";
      }
      else {
	int lb=-1,ub=node[v[i]].p.size();
	int x = l[i];
	while(ub-lb>1){
	  int mid=(lb+ub)/2;
	  if(node[v[i]].p[mid].first<=x) lb=mid;
	  else ub=mid;
	}
	cout << node[v[i]].p[lb].second << "\n";
      }
    }
  }
};

int main()
{
  int n; cin >> n;
  vector<int> V(n), W(n);
  rep(i,n) {
    cin >> V[i] >> W[i];
  }
  int q; cin >> q;
  vector<int> v(q),l(q);
  rep(i,q) {
    cin >> v[i] >> l[i];
    v[i]--;
  }
  Tree<int> tr(n);
  tr.Build(V, W);
  tr.Solve(v, l);
  
  return 0;
}
