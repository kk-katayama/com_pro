#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;
  cin >> n >> k;
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  int res=0;
  rep(i,n){
    rep(j,n-i+1){
      vector<int> vec;
      int sum=0;
      rep(a,i){	vec.push_back(v[a]);sum+=v[a];}
      rep(b,j){ vec.push_back(v[n-b-1]);sum+=v[n-b-1];}
      sort(vec.begin(), vec.end());
      if(i+j>k) continue;
      //      cout << i+j << " " << sum << "\n";
      // rep(qq,vec.size()) cout << vec[qq] << " ";
      // cout << "\n";
      rep(c,k-(i+j)){
	if(i+j<=c) break;
	if(vec[c]<0) sum -= vec[c];
	else break;
      }
      res = max(res,sum);
    }
  }

  cout << res << "\n";
  
  return 0;
}
