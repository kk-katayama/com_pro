#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  // string n;
  // int k;
  // cin >> n >> k;
  // vector<int> d(k);
  // rep(i,k) cin >> d[i];
  // set<int> st;
  // rep(i,k) st.insert(d[i]);

  // cout << (st.find(1)!=st.end()) << "\n";
  // int res = 0;
  // int m = n.size();
  // bool f = false;
  // rep(i,m){
  //   int x = n[i] - '0';
  //   if(f){
  //     rep(j,10){
  // 	if(st.find(j)==st.end()) {
  // 	  res = res*10+j;
  // 	  break;
  // 	}
  //     }
  //   }
  //   else{
  //     for(int j=x;j<=10;++j){
  // 	if(st.find(j)==st.end()) {
  // 	  res = res*10+j;
  // 	  if(j!=x) f = true;
  // 	  break;
  // 	}
  //     }
  //   }
  // }

  // cout << res << "\n";
    
  // return 0;

  int n,k;
  cin >> n >> k;
  vector<int> d(k);
  rep(i,k) cin >> d[i];
  set<int> st;
  rep(i,k) st.insert(d[i]);

  int j = 0;
  while(1){
    int x = n + j;
    bool f = true;
    while(x>0){
      if(st.find(x%10)!=st.end()){
	f = false;
	break;
      }
      x /= 10;
    }
    if(f){
      cout << n+j << "\n";
      break;
    }
    j++;
  }
  return 0;

}
