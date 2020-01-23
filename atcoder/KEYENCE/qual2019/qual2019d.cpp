#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
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

int main()
{
  int n,m;
  cin >> n >> m;
  //  vector<int> a(n),b(m);
  map<int,int> raw,col;
  bool f = false;
  rep(i,n){
    int a;
    cin >> a;
    raw[a]++;
    //    cin >> a[i];
    if(raw[a]>=2){
      f = true;
      break;
    }
  }
  rep(i,m){
    int b;
    cin >> b;
    col[b]++;
    //    cin >> b[i];
    if(col[b]>=2){
      f = true;
      break;
    }
  }
  if(f){
    cout << 0 << "\n";
    return 0;
  }

  // rep1(i,n*m){
  //   cout << raw[i] << "\n";
  //   raw[i] = 0;
  //   col[i] = 0;
  // }

  // rep(i,n){
  //   raw[a[i]]++;
  // }
  // rep(i,m){
  //   col[b[i]]++;
  // }

  int cntr=0,cntl=0,cnt=0;
  mint res(1);
  for(int i=n*m;i>0;--i){
    int x = raw[i];
    int y = col[i];
    //    cout << i << ":" << x << ":" << y << "\n";
    if(x>=2||y>=2){
      cout << 0 << "\n";
      return 0;
    }
    if(x==1&&y==1){
      cntr++;
      cntl++;
    }
    else if(x==1&&y==0){
      res *= (mint)cntl;
      cntr++;
    }
    else if(x==0&&y==1){
      res *= (mint)cntr;
      cntl++;
    }
    else if(x==0&&y==0){
      res *= (mint)(cntr*cntl-cnt);
    }
    cnt++;
  }

  cout << res.x << "\n";
  
  return 0;
}
