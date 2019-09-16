#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
//奇数長の回文判定
struct Manacher{
  string s;
  int n;
  vector<int> d;//回文の直径
  
  Manacher(string _s)
  {
    s = _s;
    n = s.size();
    d.resize(n);
  }

  //回文の直径を作成
  void make_d()
  {
    int i = 0,j = 0;
    while(i<n){
      while(i-j>=0&&i+j<n&&s[i-j]==s[i+j]) ++j;
      d[i] = (j-1)*2+1;
      int k = 1;
      while(i-k>=0&&d[i-k]<j-k){
	d[i+k] = d[i-k];
	++k;
      }
      i+=k;
      j-=k;
    }  
  }

  //最長奇数長回文の直径
  int longest_diamiter()
  {
    int res = 0;
    rep(i,n) res = max(res,d[i]);
    return res;
  }
};


int main()
{
  string s;
  cin >> s;
  
  Manacher mn(s);
  mn.make_d();
  cout << mn.longest_diamiter() << "\n";
  rep(i,mn.n){
    cout << mn.d[i] << "\n";
  }

  
  return 0;
}
