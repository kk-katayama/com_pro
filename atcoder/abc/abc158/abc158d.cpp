#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string s;cin >> s;
  int q;cin >> q;
  vector<int> t(q);
  vector<int> f(q);
  vector<char> c(q);
  rep(i,q){
    cin >> t[i];
    if(t[i]==2){
      cin >> f[i] >> c[i];
    }
  }

  string fr="",ba="";
  int p=0;
  rep(i,q){
    if(t[i]==1) p = (p+1)%2;
    else{
      if(p==0){
	if(f[i]==1) fr.push_back(c[i]);
	else ba.push_back(c[i]);
      }
      else{
	if(f[i]==1) ba.push_back(c[i]);
	else fr.push_back(c[i]);
      }
    }
  }
  if(p==0){
    reverse(fr.begin(), fr.end());
    cout << fr << s << ba << "\n";
  }
  else{
    reverse(s.begin(), s.end());
    reverse(ba.begin(), ba.end());
    cout << ba << s << fr << "\n";
  }

  
  return 0;
}
