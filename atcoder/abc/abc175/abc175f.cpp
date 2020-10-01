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
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
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
      //      add_edge(to[i], from[i], cost[i]);      
    }
  }

  void add_edge(int from, int to, X cost = 1) {
    node[from].edge.emplace_back(from, to, cost);
  }



  //*************************************
  // dijkstra
  // s is start node
  //*************************************
  void dijkstra(int s) { 
    // initalize d
    d.assign(n, infll/2);
    d[s] = 0;
    prev.assign(n, -1);
    
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
	if(chmin(d[w], d[v] + cos)) {
	  pq.emplace(w, d[w]);
	  prev[w] = v;
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
  int n; cin >> n;
  vector<string> s(n);
  vl c(n);
  rep(i,n) {
    cin >> s[i] >> c[i];
  }

  map<string,int> mp;
  set<int> st;
  vector<string> vs;
  vs.push_back("");
  Graph<ll> gp(3000);
  int id = 1;
  rep(i,n) {
    string tmp = "";
    rep(j,(int)s[i].size()) {
      tmp += s[i][j];
      string t = tmp;
      reverse(t.begin(), t.end());
      if(tmp == t) st.insert(id);
      if(mp[tmp] != 0) {
	gp.add_edge(mp[tmp], id, 0);
	gp.add_edge(id, mp[tmp], 0);
      }
      mp[tmp] = id++;
      vs.push_back(tmp);
    }
    tmp = "";
    for(int j = (int)s[i].size()-1; j >= 0; --j) {
      tmp += s[i][j];
      string t = tmp;
      reverse(t.begin(), t.end());
      if(tmp == t) st.insert(id);
      if(mp[t] != 0) {
	gp.add_edge(mp[t], id, 0);
	gp.add_edge(id, mp[t], 0);
      }      
      mp[t] = id++;
      vs.push_back(t);
    }
  }
  st.insert(id);

  // for(auto val: mp) {
  //   auto [fi, se] = val;
  //   cout << fi << " " << se << "\n";
  // }
  
  rep(i,(int)vs.size()) {
    rep(j,n) {
      // right
      string ss = s[j];
      reverse(ss.begin(), ss.end());
      if(ss.size() > vs[i].size()) {
	int vss = vs[i].size();
	string tmp = "";
	bool f = true;
	rep(k,(int)ss.size()) {
	  if(k < vss && ss[k] != vs[i][k]) {
	    f = false;
	    break;
	  }
	  else if(k >= vss) {
	    tmp += ss[k];
	  }
	}
	if(f) {
	  if(tmp == "") {
	    gp.add_edge(mp[vs[i]], id, c[j]);
	  }
	  else {
	    reverse(tmp.begin(), tmp.end());
	    gp.add_edge(mp[vs[i]], mp[tmp], c[j]);
	  }
	}
      }
      else {
	int sss = ss.size();
	string tmp = "";
	bool f = true;
	rep(k,(int)vs[i].size()) {
	  if(k < sss && ss[k] != vs[i][k]) {
	    f = false;
	    break;
	  }
	  else if(k >= sss) {
	    tmp += vs[i][k];
	  }
	}
	if(f) {
	  if(tmp == "") {
	    gp.add_edge(mp[vs[i]], id, c[j]);
	  }
	  else {
	    //	    reverse(tmp.begin(), tmp.end());
	    gp.add_edge(mp[vs[i]], mp[tmp], c[j]);
	  }
	}
      }      
      //left
      ss = vs[i];
      reverse(ss.begin(), ss.end());
      if(ss.size() > s[j].size()) {
	int vss = s[j].size();
	string tmp = "";
	bool f = true;
	rep(k,(int)ss.size()) {
	  if(k < vss && ss[k] != s[j][k]) {
	    f = false;
	    break;
	  }
	  else if(k >= vss) {
	    tmp += ss[k];
	  }
	}
	if(f) {
	  if(tmp == "") {
	    gp.add_edge(mp[vs[i]], id, c[j]);
	  }
	  else {
	    reverse(tmp.begin(), tmp.end());
	    gp.add_edge(mp[vs[i]], mp[tmp], c[j]);
	  }
	}
      }
      else {
	int sss = ss.size();
	string tmp = "";
	bool f = true;
	rep(k,(int)s[j].size()) {
	  if(k < sss && ss[k] != s[j][k]) {
	    f = false;
	    break;
	  }
	  else if(k >= sss) {
	    tmp += s[j][k];
	  }
	}
	if(f) {
	  if(tmp == "") {
	    gp.add_edge(mp[vs[i]], id, c[j]);
	  }
	  else {
	    //	    reverse(tmp.begin(), tmp.end());
	    gp.add_edge(mp[vs[i]], mp[tmp], c[j]);
	  }
	}
      }            
    }
  }
  
  gp.dijkstra(0);
  ll res = infll/2;
  for(auto val: st) {
    chmin(res, gp.d[val]);
  }
  cout << (res == infll/2 ? -1 : res) << "\n";
  
  return 0;
}
