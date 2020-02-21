#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
//k以下である要素のうち最大のもののインデックスを求める
int n;
vector<int> a;
int bins(int k){
  int lb=-1,ub=a.size();;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(a[mid]<=k) lb=mid;
    else ub=mid;
  }
  return lb;
}

int main()
{
  int m;
  cin >> n >> m;
  vector<int> p(n);
  rep(i,n) cin >> p[i];
  rep(i,n) rep(j,n){
    if(i>j) continue;
    a.push_back(p[i]+p[j]);
  }
  rep(i,n) a.push_back(p[i]);
  
  sort(a.begin(), a.end());

  int res = 0;
  // rep(i,a.size()){
  //   if(m-a[i]<0) continue;
  //   int kk = bins(m-a[i]);
  //   if(kk==-1) res = max(res,a[i]);
  //   else{
  //     res = max(res,a[i]+a[kk]);
  //   }
  //   //    cout << a[i] << ":" << res << "\n";
  // }
  // cout << res << "\n";

  // set 
  set<int> st;
  rep(i,n) rep(j,n) st.insert(p[i]+p[j]);
  rep(i,n) st.insert(p[i]);
  for(auto it=st.begin();it!=st.end();++it){
    int x = m - *it;
    if(x<0) continue;
    auto itr = st.upper_bound(x);
    if(itr==st.begin()) res = max(res,*it);
    else{
      --itr;
      res = max(res,*itr+*it);
    }
  }

  cout << res << "\n";
  return 0;
}
