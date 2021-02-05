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
//*******************************************************
// Tree
//*******************************************************

// status of edge
struct Edge{
  int from;
  int to;
  int cost;
  Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

//status of node
struct Node{
  int idx;
  vector<Edge> edge;
  vl cnt;
  int c;
  int p;
  Node(int idx) : idx(idx) {
    cnt.resize(26, 0);
  }
};

class Trie{
public:
  int n;
  vector<Node> node;
  
  Trie() {
    n = 1;
    node.push_back(Node(0));
    node[0].edge.resize(26, Edge(0, -1, 0));
    node[0].c = -1;
    node[0].p = -1;
  }

  vi fin;

  void add(const string &s, vi v) {
    int now = 0;
    rep(i,sz(s)) {
      rep(j,26) {
	if(v[j] > 0) {
	  node[now].cnt[j]++;
	}
      }
      int next = s[i] - 'a';
      v[next]--;
      if(node[now].edge[next].to == -1) {
	node.push_back(Node(n));
	node[n].edge.resize(26, Edge(n, -1, 0));
	node[n].c = next;
	node[n].p = now;
	node[now].edge[next].to = n;
	now = n;
	n++;
      }
      else {
	now = node[now].edge[next].to;
      }
      if(i == sz(s) - 1) {
	fin.push_back(now);
      }
    }
  }

  void Solve() {
    ll res = 0;
    for(auto val: fin) {
      int c = node[val].c;
      int p = node[val].p;
      res += node[p].cnt[c] - 1;
    }
    cout << res << "\n";
  }
  
};

int main()
{
  int n; cin >> n;
  vector<string> s(n);
  rep(i,n) {
    cin >> s[i];
  }

  vvi v(n, vi(26, 0));
  rep(i,n) {
    for(auto val: s[i]) {
      int c = val - 'a';
      v[i][c]++;
    }
  }

  rep(i,n) {
    reverse(s[i].begin(), s[i].end());
  }

  Trie tr;
  
  rep(i,n) {
    tr.add(s[i], v[i]);
  }

  tr.Solve();
  
  return 0;
}
