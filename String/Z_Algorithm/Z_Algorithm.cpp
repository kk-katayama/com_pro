#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct STR
{
  string s;
  int n;

  STR(string _s)
  {
    s = _s;
    n = s.size();
  }
  
  vector<int> Z_Algo()
  {
    vector<int> res(n);
    res[0] = n;
    int i = 1;
    int j = 0;
    while(i < n){
      while(i+j < n && s[j] == s[i+j]) ++j;
      res[i] = j;
      if(j == 0){
	++i;
	continue;
      }
      int k = 1;
      while(i+k < n && k+res[k] < j){
	res[i+k] = res[k];
	++k;
      }
      i += k;
      j -= k;
    }
    return res;    
  }

};
int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  int res = 0;
  string ss = "";
  rep(i,n){
    ss = s[n-1-i] + ss;
    STR st(ss);
    vector<int> vec = st.Z_Algo();
    rep(j,vec.size()){
      res = max(res,min(vec[j],j));
    }
  }

  cout << res << "\n";
  
  return 0;
}
