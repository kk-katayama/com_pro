#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<vector<char>> res(n,vector<char>(n));
  if(n%3==0){
    rep(i,n){
      rep(j,n){
	if(i%3==0){
	  if(j%3==2) res[i][j] = 'b';
	  else res[i][j] = 'a';
	}
	else if(i%3==1){
	  if(j%3==0) res[i][j] = 'd';
	  else if(j%3==1) res[i][j] = '.';
	  else res[i][j] = 'b';
	}
	else{
	  if(j%3==0) res[i][j] = 'd';
	  else res[i][j] = 'c';
	}
      }
    }

    rep(i,n){
      rep(j,n){
	cout << res[i][j];
      }
      cout  << "\n";
    }
    return 0;
  }

  if(n%7==0){
    rep(i,n){
      rep(j,n){
	if(i%7==0){
	  if(j%7==0||j%7==1) cout<<'a';
	  else if(j%7==2) cout << 'b';
	  else if(j%7==6) cout << 'e';
	  else cout << '.';
	}
	else if(i%7==1){
	  if(j%7==0) cout << 'd';
	  else if(j%7==2) cout << 'b';
	  else if(j%7==6) cout << 'e';	  
	  else cout << '.';
	}
	else if(i%7==2){
	  if(j%7==0) cout << 'd';
	  else if(j%7==1||j%7==2) cout << 'c';
	  else if(j%7==6) cout << 'f';	  
	  else cout << '.';
	}
	else if(i%7==3){
	  if(j%7==3||j%7==4) cout<<'a';
	  else if(j%7==5) cout << 'b';
	  else if(j%7==6) cout << 'f';	  	  
	  else cout << '.';
	}
	else if(i%7==4){
	  if(j%7==3) cout << 'd';
	  else if(j%7==5) cout << 'b';
	  else if(j%7==6) cout << 'g';	  	  
	  else cout << '.';
	}
	else if(i%7==5){
	  if(j%7==3) cout << 'd';
	  else if(j%7==4||j%7==5) cout << 'c';
	  else if(j%7==6) cout << 'g';	  	 	  
	  else cout << '.';
	}
	else{
	  if(j%7==0||j%7==1) cout<<'e';
	  else if(j%7==2||j%7==3) cout<<'f';
	  else if(j%7==4||j%7==5) cout<<'g';
	  else cout << '.';
	}
      }
      cout  << "\n";
    }
    return 0;
  }


  
  cout << -1 << "\n";
  return 0;
}
