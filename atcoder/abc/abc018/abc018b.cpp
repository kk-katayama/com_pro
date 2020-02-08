#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<int> l(n),r(n);
  rep(i,n){
    cin >> l[i] >> r[i];
  }

  rep(i,n){
    reverse(s.begin()+l[i]-1,s.begin()+r[i]);
  }
  cout << s << "\n";
  return 0;
}
