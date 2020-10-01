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
struct UFT{
  vector<int> par;//親
  vector<int> rank;//木の深さ
  vector<int> size;//木の大きさ
  int n;
  
  UFT(int _n)
  {
    n = _n;
    par.resize(n);
    rank.assign(n,0);
    size.assign(n,1);
    rep(i,n){
      par[i] = i;
    }
  }
  
  //xの根を返す
  int find(int x)
  {
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  //x,yを併合
  void unite(int x,int y)
  {
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rank[x] < rank[y]){
      par[x] = y;
      size[y] += size[x];
    }
    else{
      par[y] = x;
      size[x] += size[y];
      if(rank[x] == rank[y]) rank[x]++;
    }
  }

  //x,yが同じグループにいるかどうかを返す
  bool same(int x,int y)
  {
    return find(x) == find(y);
  }

  //xの属する木のサイズを探す
  int usize(int x)
  {
    return size[find(x)];
  }
};


int main()
{
  int id,n,k; cin >> id >> n >> k;
  vector<string> s(n);
  vi cnt(10, 0);
  rep(i,n) {
    cin >> s[i];
    rep(j,(int)s[i].size()) {
      cnt[(int)s[i][j] - '0']++;
    }
  }

  int res = 0;
  int mx;
  rep(i, 10) {
    if(chmax(res, cnt[i])) {
      mx = i;
    }
  }

  UFT uf(n*n);
  vi dx = {-1, 0, 1, 0};
  vi dy = {0, -1, 0, 1};
  vi resx, resy, resc;
  rep(i,n) {
    rep(j,n) {
      if(((int)s[i][j] - '0') == mx) continue;
      vi table(4);
      vi cntt(10, 0);
      rep(l,4) {
	int ni = i + dx[l];
	int nj = j + dy[l];
	if(0 <= ni && ni < n && 0 <= nj && nj < n) {
	  if(s[i][j] == s[ni][nj]) {
	    uf.unite(i*n+j, ni*n+nj);
	  }
	  table[l] = (int)s[ni][nj] - '0';
	  cntt[table[l]]++;
	}
      }
      int mxx = 0;
      int idd;
      rep(l,10) {
	if(chmax(mxx, cntt[l])) idd = l;
      }
      if(mxx <= 3) continue;
      resx.push_back(i+1);
      resy.push_back(j+1);
      resc.push_back(idd);
      rep(l,4) {
	int ni = i + dx[l];
	int nj = j + dy[l];
	if(0 <= ni && ni < n && 0 <= nj && nj < n) {
	  if((int)s[ni][nj] - '0' == idd) uf.unite(i*n+j, ni*n+nj);
	}
      }
    }
  }

  rep(i,n) {
    rep(j,n) {
      if(uf.find(i*n+j) == i*n+j && ( (int)s[i][j] - '0') != mx) {
	resx.push_back(i+1);
	resy.push_back(j+1);
	resc.push_back(mx);
      }
    }
  }
  
  cout << (int)resx.size() << "\n";
  rep(i,(int)resx.size()) {
    cout << resx[i] << " ";
    cout << resy[i] << " ";
    cout << resc[i] << "\n";    
  }
  
  return 0;
}
