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
#include <cstdlib>
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
int main()
{
  int h,w; cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  vi p(h);
  vi f(h, 0);
  vi cen(h, 0);
  auto rec = [&](auto self, int id, int cnt)->void {
    if(cnt == h/2) {
      vector<vector<char>> t(h, vector<char>(w));
      rep(j,w) {
        rep(i,h) {
          t[i][j] = s[p[i]][j];
        }
      }     
      bool center = true;
      vi ff(w,0);
      rep(i,w) {
        rep(j,w) {
          if(i >= j) continue;
          if(ff[i] || ff[j]) continue;          
          bool flag = true;
          rep(k,h) {
            if(t[k][i] != t[h-1-k][j]) {
              flag = false;
              break;
            }
          }
          if(flag) {
            ff[i] = 1;
            ff[j] = 1;
            break;
          }
        }
        if(!ff[i]) {
          if(w % 2 == 0) break;
          else {
            bool ffff = true;
            rep(k,h) if(t[k][i] != t[h-1-k][i]) ffff = false;
            if(ffff && center) {
              center = false;
              ff[i] = 1;
            }
          }
        }
      }
      bool fff = true;
      rep(i,w) {
        fff &= ff[i];
      }
      if(fff) {
        cout << "YES" << "\n";
        exit(0);
      }
      return ;
    }
    while(f[id] || cen[id]) id++;
    p[cnt] = id;
    f[id] = 1;
    for (int i = id+1; i < h; i++) {
      if(f[i] || cen[i]) continue;
      p[h-1-cnt] = i;
      f[i] = 1;
      self(self, id, cnt+1);
      f[i] = 0;
    }
    f[id] = 0;
  };
  if(h % 2 == 0) { 
    rec(rec, 0, 0);
    cout << "NO\n";
  }
  else {
    rep(i,h) {
      cen[i] = 1;
      p[h/2] = i;
      rec(rec, 0, 0);
      cen[i] = 0;
    }
    cout << "NO\n";
  }
  return 0;
}
