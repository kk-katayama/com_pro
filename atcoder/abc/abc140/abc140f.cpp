#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
bool comp(int &a,int &b){
  return a>b;
}
int main()
{
  int _n;
  cin >> _n;
  int n = 1<<_n;
  vector<int> s(n);
  rep(i,n) cin >> s[i];
  sort(s.begin(), s.end(),comp);
  bool f = false;
  vector<int> a(1,s[0]);
  s[0] = -1;
  rep(i,_n){
    vector<int> p = a;
    sort(p.begin(), p.end(),comp);
    auto itr = p.begin();
    int j = 0;
    while(itr!=p.end()){
      if(j==n){
	f = true;
	break;
      }
      if(s[j]==-1){
	++j;
	continue;
      }
      if(*itr > s[j]){
	a.push_back(s[j]);
	s[j] = -1;
	++itr;
      }
      ++j;
    }
    if(f) break;
  }
  cout << (!f?"Yes":"No") << "\n";
  
  return 0;
}
