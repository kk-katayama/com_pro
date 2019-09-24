#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i,n) cin >> p[i];

  vector<int> rle(0);
  int cnt = 1;
  rep(i,n-1){
    if(p[i]<p[i+1]) cnt++;
    else{
      rle.push_back(cnt);
      cnt = 1;
    }
  }
  rle.push_back(cnt);

  vector<int> len(0);
  rep(i,rle.size()){
    while(rle[i]>0){
      len.push_back(rle[i]);
      rle[i]--;
    }
  }

  bool f = false;
  if(len[n-k]>=k) f =true;

  set<int> stmin,stmax;
  
   
  rep(i,k-1) stmin.insert(p[i]);
  rep1(i,k-1) stmax.insert(p[i]);

  int res = 1;
  rep(i,n-k){
    if(len[i] >= k){
      if(!f){
	res++;
	f =true;
      }
      continue;
    }
    stmin.insert(p[i+k-1]);
    stmax.insert(p[i+k]);
    
    int in = *stmin.begin();
    int ax = *(--stmax.end());

    if(!(in==p[i]&&ax==p[i+k])) res++;

    stmin.erase(p[i]);
    stmax.erase(p[i+1]);
  }

  cout << res << "\n";
  
  return 0;
}
