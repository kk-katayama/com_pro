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
#include <bitset>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define rev(i,n) for(int i = n-1; i >= 0; --i)
#define rev1(i,n) for(int i = n; i > 0; --i)
#define rev2(i,s,t) for(int i = s; i >= t; --i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
int main()
{
  int n,m; cin >> n >> m;
  vi a(n);
  rep(i,n) cin >> a[i];
  vi b(m), c(m);
  vii d(m);
  rep(i,m) {
    cin >> b[i] >> c[i];
    d[i].resize(c[i]);
    rep(j,c[i]) {
      cin >> d[i][j];
      d[i][j]--;
    }
  }

  int k = 9;
  int res = 0;
  int xx;
  int comb=(1<<k)-1;//辞書順最小
  while(comb<(1<<n)){//n個の要素から選ぶのでcomb>=(1<<n)となってはいけない
    int tmp = 0;
    rep(i,n){
      //      if((1<<i)&comb) tmp += a[i];
      if((comb>>i)&1) tmp += a[i];      
    }
    rep(i,m) {
      int cnt = 0;
      rep(j,c[i]) {
	//	if( !( (1<<d[i][j]) & comb) ) f = false;
	if( (comb >> d[i][j]) & 1 ) cnt++;
      }
      if(cnt >= 3) tmp += b[i];
    }
    chmax(res, tmp);
    int x=comb&-comb;//最下位の1bitを独立させたもの
    int y=comb+x;//combの最下位の1の連続した部分を0に変え、その部分より1つ上の位を1に変える
    comb=((comb&~y)/x>>1)|y;
    //z=comb&~yは最下位の1の連続した部分を取り出す。
    //z/xでzの最下位の1の連続した部分より下位にある0を消し、右に1ビットシフトする。
    //それとyのorをとれば求めたい次のビット列が得られる。
  }
  
  cout << res << "\n";
  return 0;
}
