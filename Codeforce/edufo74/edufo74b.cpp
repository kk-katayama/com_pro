#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
bool Cl(int x,vector<ll> a,ll xk){
  return a[x]<=xk;
}
int lower(int l,int r,vector<ll> a,ll xk){//条件を満たす中で最大のものを返す
  int lb=l-1,ub=r+1;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(Cl(mid,a,xk)) lb=mid;
    else ub=mid;
  }
  return lb;
}

bool C(ll x,vector<ll> a,ll k){
  int y = lower(0,a.size()-1,a,x*k);
  return (int)a.size()-y-1<=(int)x;
}
int upper(int l,int r,vector<ll> a,ll k){//条件を満たす中で最小のものを返す
  int lb=l-1,ub=r+1;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(C(mid,a,k)) ub=mid;
    else lb=mid;
  }
  return ub;
}


int main()
{
  int q;
  cin >> q;
  vector<int> n(q);
  vector<ll> r(q);
  vector<vector<ll>> x(q);
  rep(i,q){
    cin >> n[i] >> r[i];
    x[i].resize(n[i]);
    rep(j,n[i]) cin >> x[i][j];
  }

  rep(i,q){
    sort(x[i].begin(), x[i].end());
    vector<ll> a;
    rep(j,x[i].size()-1){
      if(x[i][j]!=x[i][j+1]) a.push_back(x[i][j]);
    }
    a.push_back(x[i][x[i].size()-1]);
    cout << upper(0,(1<<18),a,r[i]) << "\n";
  }
  
  return 0;
}
