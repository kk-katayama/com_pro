#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
//****************************************
// Graph template
//****************************************

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
  int idx;
  vector<Edge<X>> edge;
  bool uing, used;
  int color;
  
  Node() = default;

  explicit Node(int idx) : idx(idx) {}
};

template <typename X>
class Graph{
private:
  int n; // number of node
  int m; // number of edge
  vector<Node<X>> node; 
  bool loopflag;
  int start;
  vector<int> tmp, loop;
  
  void Init_Node() {
    rep(i,n) node.emplace_back(i);
  }
public:
  explicit Graph(int n) : n(n) {
    Init_Node();
  }

  // edges have no-weight 
  Graph(int n, int m, vector<int> from, vector<int> to) : n(n), m(m) {
    Init_Node();
    rep(i,m) {
      add_edge(from[i], to[i]);
      add_edge(to[i], from[i]);      
    }
  }  

  // edges have weight
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

  bool DFS_Find_Loop(int v, int p) {
    bool res = true;
    node[v].uing = true;
    for(auto next: node[v].edge) {
      if(loopflag) continue;
      int w = next.to;
      if(w == p || node[w].used) continue;
      if(node[w].uing) {
	res = false;
	loopflag = true;
	start = w;
      }
      res = res && DFS_Find_Loop(w, v);
    }
    if(loopflag) tmp.push_back(v);
    if(v == start) {
      loopflag = false;
      loop = tmp;
      start = -1;
    }
    node[v].uing = false;    
    node[v].used = true;
    return res;
  }

  bool paint_dfs(int v, int c) {
    node[v].color = c; // paint node[v] c
    for(auto next: node[v].edge) {
      int w = next.to;
      if(node[w].color == c) return false;
      if(node[w].color == 0 && !paint_dfs(w, -c)) return false;
    }
    return true;
  }

  
  void Solve(int k) {
    loopflag = false;
    start = -1;
    rep(i,n) {
      node[i].used = false;
      node[i].uing = false;
      node[i].color = 0;
    }
    DFS_Find_Loop(0, -1);
    if(loop.size() != 0) {
      if(loop.size() <= k) {
	cout << 2 << "\n";
	cout << loop.size() << "\n";
	for(auto val: loop) cout << val + 1 << " ";
	cout << "\n";	
      }
      else {
	vector<int> res;
	vector<bool> fff(n, false);
	//	for(auto val: loop) fff[val] = true;
	map<int,int> mp;
	int ln = loop.size();	
	rep(i,ln) mp[loop[i]] = i;
	int idx;
	rep(i,loop.size()) {
	  if(i % 2 == 0) {
	    res.push_back(loop[i]);
	    bool f = false;
	    for(auto next: node[loop[i]].edge) {
	      int w = next.to;
	      if(w == loop[(i+1) % ln] || w == loop[(i-1+ln)%ln]) continue;
	      if(fff[w]) {
		idx = w;
		f = true;
	      }
	    }
	    if(f && i != 0) {
	      cout << 2 << "\n";
	      cout << i - mp[idx] + 1 << "\n";
	      for(int j = mp[idx]; j <= i; ++j) {
		cout << loop[j] + 1 << " ";
	      }
	      cout  << "\n";
	      return ;
	    }
	    fff[loop[i]] = true;
	  }
	  if(res.size() == (k + 1) / 2) {
	    cout << 1 << "\n";
	    for(auto val: res) cout << val+1 << " ";
	    cout << "\n";
	    return ;
	  }
	}
      }
    }
    else {
      paint_dfs(0, 1);
      int cnt = 0;
      rep(i,n) {
	if(node[i].color == 1) cnt++;
      }
      if(cnt >= (k + 1) / 2) {
	cout << 1 << "\n";
	int cc = 0;
	rep(i,n) {
	  if(node[i].color == 1) {
	    cout << i+1 << " ";
	    cc++;
	  }
	  if(cc == (k+1)/2){
	    cout  << "\n";
	    return ;
	  }
	}
      }
      else {
	cout << 1 << "\n";
	int cc = 0;
	rep(i,n) {
	  if(node[i].color == 0) {
	    cout << i+1 << " ";
	    cc++;
	  }
	  if(cc == (k+1)/2){
	    cout  << "\n";
	    return ;
	  }
	}
      }      
    }
  }
  
};


int main()
{
  int n,m,k; cin >> n >> m >> k;
  vector<int> a(m), b(m);
  rep(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  Graph<int> gp(n, m, a, b);
  gp.Solve(k);
  
  return 0;
}
