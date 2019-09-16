#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int manacher(string p){
  int res = 0;
  int ps = p.size();

  vector<int> d(ps);
  int i=0,j=0;
  while(i<ps){//manacher
    while(i-j>=0&&i+j<ps&&p[i-j]==p[i+j]) ++j;
    d[i] = j;
    int k = 1;
    while(i-k>=0&&d[i-k]<j-k){
      d[i+k] = d[i-k];
      ++k;
    }
    i+=k;
    j-=k;
  }  
  rep(i,ps) res = max(res,(d[i]-1)*2+1);
  return res;
}
int main()
{
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> l(q),r(q);
  rep(i,q) cin >> l[i] >> r[i];

  rep(i,q){
    string sub = s.substr(l[i]-1,r[i]-l[i]+1);
    cout << manacher(sub) << "\n";
  }
  
  return 0;
}
