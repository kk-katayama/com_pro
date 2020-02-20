#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  map<int,int> mp;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
    mp[a[i]]=i;
  }
  int num=0;
  for(auto it=mp.begin();it!=mp.end();++it){
    mp[it->first]=num++;
  }

  rep(i,n){
    cout << mp[a[i]] << "\n";
  }
  
  return 0;
}
