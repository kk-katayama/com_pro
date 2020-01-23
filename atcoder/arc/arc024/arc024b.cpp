#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> c(n);
  rep(i,n){
    cin >> c[i];
  }

  vector<int> com(0);
  int cnt=1;
  rep(i,n-1){
    if(c[i]!=c[i+1]){
      com.push_back(cnt);
      cnt=1;
    }
    else{
      cnt++;
    }
  }
  com.push_back(cnt);
  if(com.size()==1){
    cout << -1 << "\n";
    return 0;
  }
  if(c[0]==c[n-1]){
    com[0] += com[com.size()-1];
    com[com.size()-1] = 0;
  }

  int res=0;
  rep(i,com.size()){
    res = max(res,(com[i]+1)/2);
  }

  cout << res << "\n";
  return 0;
}
