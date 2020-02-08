#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;

  set<string> st;
  rep(i,s.size()){
    rep1(j,5){
      if(i+j>(int)s.size()) break;
      string ss = s.substr(i,j);
      st.insert(ss);
    }
  }

  int cnt = 1;
  for(auto it=st.begin();it!=st.end();++it){
    //    cout << *it << "\n";
    if(cnt==k){
      cout << *it << "\n";
      break;
    }
    cnt++;
  }
  
  return 0;
}
