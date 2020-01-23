#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int q;
  cin >> q;
  vector<int> n(q);
  vector<vector<int>> a(q);
  rep(i,q){
    cin >> n[i];
    a[i].resize(n[i]);
    rep(j,n[i]) cin >> a[i][j];
  }
  const int inf = 1e+9;
  rep(i,q){
    vector<int> b=a[i];
    sort(b.begin(), b.end());
    map<int,int> mp;
    int k=0;
    rep(j,b.size()-1){
      if(b[j]!=b[j+1]) mp[b[j]]=k++;
    }
    mp[b[b.size()-1]]=k++;
    vector<int> fr(k,inf),ba(k,0);
    rep(j,a[i].size()){
      fr[mp[a[i][j]]] = min(fr[mp[a[i][j]]],j);
      ba[mp[a[i][j]]] = max(ba[mp[a[i][j]]],j);
    }
    int len=1;
    int tmp=1;
    rep(j,k-1){
      if(ba[j]<fr[j+1]) tmp++;
      else{
	len=max(len,tmp);
	tmp=1;
      }
    }
    len=max(len,tmp);
    cout << k-len << "\n";
  }
  



  
  return 0;
}
