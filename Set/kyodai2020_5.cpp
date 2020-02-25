#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  vector<vector<int>> vec = {{1,2,3,4,5},
  			     {1,2,3,4,5},
  			     {1,2,3,4,5},
  			     {1,2,3,4,5},			     
  			     {1,2,3,4,5}};
  int cnt=0;
  ll t = 0;
  do{
    do{
      do{
	do{
	  do{
	  bool f = true;
	  rep(j,5){
	    int x = 1;
	    rep(i,5){
	      x *= vec[i][j];
	    }
	    if(x!=120){
	      f = false;
	      break;
	    }
	    if(!f) break;
	  }
	  ++t;
	  if(t%10000000==0) cout << t << ":" << cnt << "\n";
	  if(f) cnt++;
	  } while(next_permutation(vec[4].begin(), vec[4].end()));      	  
	} while(next_permutation(vec[3].begin(), vec[3].end()));      	  
      } while(next_permutation(vec[2].begin(), vec[2].end()));
    } while(next_permutation(vec[1].begin(), vec[1].end()));    
  } while(next_permutation(vec[0].begin(), vec[0].end()));
  cout << cnt << "\n";
  return 0;
}
