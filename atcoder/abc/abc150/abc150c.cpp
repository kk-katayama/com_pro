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
  vector<int> p(n);
  rep(i,n){
    cin >> p[i];
  }
  vector<int> q(n);
  rep(i,n){
    cin >> q[i];
  }

  vector<int> v(0);
  rep1(i,n){
    v.push_back(i);
  }

  int cnt=1;
  int a,b;
  do{
    bool fp = true;
    rep(i,n){
      if(p[i]!=v[i]){
	fp = false;
	break;
      }
    }
    if(fp) a=cnt;
    bool fq = true;
    rep(i,n){
      if(q[i]!=v[i]){
	fq = false;
	break;
      }
    }
    if(fq) b=cnt;
    cnt++;
  }while(next_permutation(v.begin(), v.end()));

  int ans = abs(a-b);
  cout << ans << "\n";
  
  return 0;
}
