#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> x(n),l(n);
  rep(i,n){
    cin >> x[i] >> l[i];
  }
  vector<pair<int,int>> p(n);
  rep(i,n){
    p[i] = make_pair(x[i]-l[i],x[i]+l[i]);
  }
  sort(p.begin(), p.end());
  int cnt = 0;
  int back = -1e+9-10;
  rep(i,n){
    int f = p[i].first;
    int b = p[i].second;
    if(back<=f){
      back = b;
    }
    else{
      back = min(back,b);
      cnt++;
    }
  }

  cout << n-cnt << "\n";
  
  return 0;
}
