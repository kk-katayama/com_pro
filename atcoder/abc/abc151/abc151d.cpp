#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int h,w;
  cin >> h >> w;
  vector<vector<char>> c(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> c[i][j];
    }
  }

  int res =0;
  vector<vector<int>> d(h,vector<int>(w));  
  rep(i,h){
    rep(j,w){
      rep(k,h){
	rep(l,w){
	  if(c[i][j]=='.'&&c[k][l]=='.'){
	    rep(a,h){
	      d[a].assign(w,-1);
	    }
	    queue<pair<int,int>> q;
	    d[i][j] = 0;
	    q.push(make_pair(i,j));
	    while(!q.empty()){
	      pair<int,int> p = q.front();
	      q.pop();
	      int x = p.first;
	      int y = p.second;
	      if(x-1>=0){
		if(d[x-1][y]<0&&c[x-1][y]=='.'){
		  d[x-1][y] = d[x][y] + 1;
		  q.push(make_pair(x-1,y));
		}
	      }
	      if(x+1<h){
		if(d[x+1][y]<0&&c[x+1][y]=='.'){	     
		  d[x+1][y] = d[x][y] + 1;
		  q.push(make_pair(x+1,y));
		}
	      }
	      if(y-1>=0){
		if(d[x][y-1]<0&&c[x][y-1]=='.'){
		  d[x][y-1] = d[x][y] + 1;
		  q.push(make_pair(x,y-1));
		}
	      }
	      if(y+1<w){
		if(d[x][y+1]<0&&c[x][y+1]=='.'){
		  d[x][y+1] = d[x][y] + 1;
		  q.push(make_pair(x,y+1));
		}
	      }	    
	    }
	    // cout << i << ":" << j << "\n";
	    // cout << k << ":" << l << "\n";
	    // cout << d[k][l] << "\n";
	    res = max(res,d[k][l]);
	  }
	}	  
      }
    }
  }
  cout << res << "\n";
  
  return 0;
}
