#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template <typename X>
struct SegT{
  vector<X> abox,bbox;  
  int n;
  
  SegT(int _n)
  {
    n = 1;
    while(n < _n) n *= 2;
    abox.assign(2*n-1,1);
    bbox.assign(2*n-1,0);
  }
  
  void update(int k,X a,X b)
  {
    k += n - 1;
    abox[k] = a;
    bbox[k] = b;
    while(k > 0){
      k = (k - 1)/2;
      abox[k] = abox[2*k+1] * abox[2*k+2];
      bbox[k] = bbox[2*k+1] * abox[2*k+2] + bbox[2*k+2];
    }
  }
  
  X query()
  {
    return abox[0] + bbox[0];
  }
};
ll _n;
int m;
vector<ll> p;
vector<double> a,b;
int main()
{
  cin >> _n >> m;
  rep(i,m){
    ll pp;
    double aa,bb;
    cin >> pp >> aa >> bb;
    p.push_back(--pp);
    a.push_back(aa);
    b.push_back(bb);
  }

  {
    map<ll,int> mp;
    rep(i,m){
      mp[p[i]] = 0;
    }
    int j = 0;
    for(auto itr = mp.begin();itr != mp.end();++itr){
      itr->second = j++;
    }
    rep(i,m){
      p[i] = mp[p[i]];
    }
  }
  
  SegT<double> st(m);

  double resn = 1,resx = 1;
  rep(i,m){
    st.update(p[i],a[i],b[i]);
    double temp = st.query();
    resn = min(resn,temp);
    resx = max(resx,temp);
  }
  
  printf("%.7f\n", resn);
  printf("%.7f\n", resx);
  
  return 0;
}
