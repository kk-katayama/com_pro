#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k,q;
  cin >> n >> k >> q;
  vector<int> a(q);
  rep(i,q){
    cin >> a[i];
    a[i]--;
  }
  map<int,int> mp;
  rep(i,n) mp[i]=0;

  rep(i,q) mp[a[i]]++;
  
  vector<bool> res(n,0); 
  
  for(auto& itr:mp){
    int index = itr.first;
    int x = itr.second;
    if(x>=q-k+1) res[index] = true;
  }

  rep(i,n){
    if(res[i]) cout << "Yes" << "\n";
    else cout << "No" << "\n";
  }
  
  return 0;
}
