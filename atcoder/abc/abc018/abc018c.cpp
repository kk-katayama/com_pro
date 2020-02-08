#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int r,c,k;
  cin >> r >> c >> k;
  vector<vector<char>> s(r,vector<char>(c));
  rep(i,r){
    rep(j,c){
      cin >> s[i][j];
    }    
  }

  vector<set<int>> rb(r),cb(c);
  rep(i,r){
    rb[i].insert(-1);
    rb[i].insert(c);    
    rep(j,c){
      if(s[i][j]=='x'){
  	rb[i].insert(j);
      }
    }
  }
  rep(j,c){
    cb[j].insert(-1);
    cb[j].insert(r);
    rep(i,r){
      if(s[i][j]=='x'){
  	cb[j].insert(i);
      }
    }
  }  

  vector<vector<pair<int,int>>> dis(r,vector<pair<int,int>>(c));
  
  rep(i,r){
    rep(j,c){
      auto itr = rb[i].upper_bound(j);
      itr--;
      int rl=*itr;
      int ru=*(rb[i].lower_bound(j));
      auto itc = cb[j].upper_bound(i);
      itc--;      
      int cl=*itc;
      int cu=*(cb[j].lower_bound(i));
      dis[i][j] = {min(j-rl,ru-j),min(i-cl,cu-i)};
    }
  }

  // rep(i,r){
  //   rep(j,c){
  //     cout << "{" << dis[i][j].first <<  "," <<  dis[i][j].second<< "}" ;
  //   }
  //   cout  << "\n";
  // }
  
  int cnt = 0;
  for(int i=k-1;i<=r-k;++i){
    for(int j=k-1;j<=c-k;++j){
      bool f = true;
      rep(l,k){
	if(dis[i][j-l].second<k-l||dis[i][j+l].second<k-l){
	  f = false;
	  break;
	}
      }
      if(f) cnt++;
    }
  }
  cout << cnt << "\n";
  
  return 0;
}
