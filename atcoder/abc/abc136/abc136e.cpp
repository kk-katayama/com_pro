#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
vector<int> divisor(int a){
  vector<int> res;
  for(int i=1;i*i<=a;i++){
    if(a%i==0){
      res.push_back(i);
      if(i!=a/i) res.push_back(a/i);
    }
  }
  return res;
}

int main()
{
  int n,k;cin >> n >> k;
  vector<int> a(n);
  int sum=0;
  rep(i,n){ cin >> a[i];sum += a[i];}
  vector<int> div = divisor(sum);
  int res = 0;
  rep(i,div.size()){
    int x = div[i];
    vector<int> mi(n),pl(n);
    rep(j,n){
      mi[j] = a[j]%x;
      pl[j] = x-mi[j];
    }
    sort(mi.begin(), mi.end());
    sort(pl.begin(), pl.end());
    vector<int> psum(n+1),msum(n+1);
    psum[0]=0;msum[0]=0;
    rep(l,n){
      msum[l+1] = msum[l]+mi[l];
      psum[l+1] = psum[l]+pl[l];
    }
    
    rep(l,n+1){
      if(msum[l]>k) break;
      if(msum[l]==psum[n-l]) res=max(res,x);
    }
    
  }
  cout << res << "\n";
  return 0;
}
