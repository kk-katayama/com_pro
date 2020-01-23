#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> cnt(3);
  rep(i,n){
    if(s[i]=='R'){
      cnt[0]++;
    }
    else if(s[i]=='G'){
      cnt[1]++;
    }
    else{
      cnt[2]++;
    }
  }

  int res=0;
  rep(i,3){
    res += cnt[i]%2;
  }
  cout << res << "\n";
  
  return 0;
}
