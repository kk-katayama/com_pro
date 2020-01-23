#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
bool comp(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b){
  return a.first>b.first;
}
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

int main()
{
  int h,w;
  cin >> h >> w;
  vector<vector<int>> a(h,vector<int>(w));
  rep(i,h){
    rep(j,w){
      cin >> a[i][j];
    }
  }

  vector<pair<int,pair<int,int>>> p(0);
  rep(i,h){
    rep(j,w){
      p.push_back(make_pair(a[i][j],make_pair(i,j)));
    }
  }

  sort(p.begin(), p.end(),comp);
  vector<vector<mint>> d(h,vector<mint>(w));
  
  rep(i,h*w){
    int x = p[i].second.first;
    int y = p[i].second.second;
    if(x-1>=0){
      if(a[x][y]<a[x-1][y]){
	d[x][y] += d[x-1][y];
      }
    }
    if(y-1>=0){
      if(a[x][y]<a[x][y-1]){
	d[x][y] += d[x][y-1];
      }
    }    
    if(x+1<h){
      if(a[x][y]<a[x+1][y]){
	d[x][y] += d[x+1][y];
      }
    }
    if(y+1<w){
      if(a[x][y]<a[x][y+1]){
	d[x][y] += d[x][y+1];
      }
    }        
    d[x][y] += (mint)1;
  }

  mint res;
  rep(i,h){
    rep(j,w){
      res += d[i][j];
    }
  }
  cout << res.x << "\n";
  
  
  return 0;
}
