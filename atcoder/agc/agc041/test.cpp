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
  int nn = n;
  vector<vector<char>> res(n,vector<char>(n,'.'));
  if(n==3||n==6){
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
  }
  else if(n==2){
    cout << -1 << "\n";
    return 0;
  }
  else if(n==7){
    rep(i,n){
      rep(j,n){
	if(i%7==0){
	  if(j%7==0||j%7==1){
	    res[i][j] = 'a';
	  }
	  else if(j%7==2){
	    res[i][j] = 'b';
	  }
	  else if(j%7==6){
	    res[i][j] = 'e';
	  }
	}
	else if(i%7==1){
	  if(j%7==0){
	    res[i][j] = 'd';
	  }
	  else if(j%7==2){
	    res[i][j] = 'b';
	  }
	  else if(j%7==6){
	    res[i][j] = 'e';
	  }
	}
	else if(i%7==2){
	  if(j%7==0){
	    res[i][j] = 'd';
	  }
	  else if(j%7==1||j%7==2){
	    res[i][j] = 'c';
	  }
	  else if(j%7==6){
	    res[i][j] = 'f';
	  }
	}
	else if(i%7==3){
	  if(j%7==3||j%7==4){
	    res[i][j] = 'a';
	  }
	  else if(j%7==5){
	    res[i][j] = 'b';
	  }
	  else if(j%7==6){
	    res[i][j] = 'f';
	  }
	}	
	else if(i%7==4){
	  if(j%7==3){
	    res[i][j] = 'd';
	  }
	  else if(j%7==5){
	    res[i][j] = 'b';
	  }
	  else if(j%7==6){
	    res[i][j] = 'g';
	  }
	}
	else if(i%7==5){
	  if(j%7==3){
	    res[i][j] = 'd';
	  }
	  else if(j%7==4||j%7==5){
	    res[i][j] = 'c';
	  }
	  else if(j%7==6){
	    res[i][j] = 'g';
	  }
	}
	else {
	  if(j%7==0||j%7==1){
	    res[i][j] = 'e';
	  }
	  else if(j%7==2||j%7==3){
	    res[i][j] = 'f';
	  }
	  else if(j%7==4||j%7==5){
	    res[i][j] = 'g';
	  }
	}
      }
    }    
  }
  else if(n==11){
    rep(i,7){
      rep(j,7){
	if(i%7==0){
	  if(j%7==0||j%7==1){
	    res[i][j] = 'a';
	  }
	  else if(j%7==2){
	    res[i][j] = 'b';
	  }
	  else if(j%7==6){
	    res[i][j] = 'e';
	  }
	}
	else if(i%7==1){
	  if(j%7==0){
	    res[i][j] = 'd';
	  }
	  else if(j%7==2){
	    res[i][j] = 'b';
	  }
	  else if(j%7==6){
	    res[i][j] = 'e';
	  }
	}
	else if(i%7==2){
	  if(j%7==0){
	    res[i][j] = 'd';
	  }
	  else if(j%7==1||j%7==2){
	    res[i][j] = 'c';
	  }
	  else if(j%7==6){
	    res[i][j] = 'f';
	  }
	}
	else if(i%7==3){
	  if(j%7==3||j%7==4){
	    res[i][j] = 'a';
	  }
	  else if(j%7==5){
	    res[i][j] = 'b';
	  }
	  else if(j%7==6){
	    res[i][j] = 'f';
	  }
	}	
	else if(i%7==4){
	  if(j%7==3){
	    res[i][j] = 'd';
	  }
	  else if(j%7==5){
	    res[i][j] = 'b';
	  }
	  else if(j%7==6){
	    res[i][j] = 'g';
	  }
	}
	else if(i%7==5){
	  if(j%7==3){
	    res[i][j] = 'd';
	  }
	  else if(j%7==4||j%7==5){
	    res[i][j] = 'c';
	  }
	  else if(j%7==6){
	    res[i][j] = 'g';
	  }
	}
	else {
	  if(j%7==0||j%7==1){
	    res[i][j] = 'e';
	  }
	  else if(j%7==2||j%7==3){
	    res[i][j] = 'f';
	  }
	  else if(j%7==4||j%7==5){
	    res[i][j] = 'g';
	  }
	}
      }
    }
    int offset = 7;
    for(int i=0;i<4;++i){
      for(int j=0;j<4;++j){
	if(i%4==0){
	  if(j%4==0||j%4==1){
	    res[i+offset][j+offset] = 'a';
	  }
	  else if(j%4==2){
	    res[i+offset][j+offset] = 'c';
	  }
	  else{
	    res[i+offset][j+offset] = 'd';
	  }
	}
	else if(i%4==1){
	  if(j%4==0||j%4==1){
	    res[i+offset][j+offset] = 'b';
	  }
	  else if(j%4==2){
	    res[i+offset][j+offset] = 'c';
	  }
	  else{
	    res[i+offset][j+offset] = 'd';
	  }	  
	}
	else if(i%4==2){
	  if(j%4==0){
	    res[i+offset][j+offset] = 'e';
	  }
	  else if(j%4==1){
	    res[i+offset][j+offset] = 'f';
	  }
	  else{
	    res[i+offset][j+offset] = 'g';
	  }	  
	}
	else if(i%4==3){
	  if(j%4==0){
	    res[i+offset][j+offset] = 'e';
	  }
	  else if(j%4==1){
	    res[i+offset][j+offset] = 'f';
	  }
	  else{
	    res[i+offset][j+offset] = 'h';
	  }	  
	}		
      }      
    }    
  }
  else{
    int offset = 0;
    while(n%5!=0){
      for(int i=0;i<4;++i){
	for(int j=0;j<4;++j){
	  if(i%4==0){
	    if(j%4==0||j%4==1){
	      res[i+offset][j+offset] = 'a';
	    }
	    else if(j%4==2){
	      res[i+offset][j+offset] = 'c';
	    }
	    else{
	      res[i+offset][j+offset] = 'd';
	    }
	  }
	  else if(i%4==1){
	    if(j%4==0||j%4==1){
	      res[i+offset][j+offset] = 'b';
	    }
	    else if(j%4==2){
	      res[i+offset][j+offset] = 'c';
	    }
	    else{
	      res[i+offset][j+offset] = 'd';
	    }	  
	  }
	  else if(i%4==2){
	    if(j%4==0){
	      res[i+offset][j+offset] = 'e';
	    }
	    else if(j%4==1){
	      res[i+offset][j+offset] = 'f';
	    }
	    else{
	      res[i+offset][j+offset] = 'g';
	    }	  
	  }
	  else if(i%4==3){
	    if(j%4==0){
	      res[i+offset][j+offset] = 'e';
	    }
	    else if(j%4==1){
	      res[i+offset][j+offset] = 'f';
	    }
	    else{
	      res[i+offset][j+offset] = 'h';
	    }	  
	  }		
	}      
      }
      offset += 4;
      n -= 4;
    }

    while(n>0){
      for(int i=0;i<5;++i){
	for(int j=0;j<5;++j){
	  if(i%5==0){
	    if(j%5==0){
	      res[i+offset][j+offset] = 'a';
	    }
	    else if(j%5==1||j%5==2){
	      res[i+offset][j+offset] = 'b';
	    }
	    else if(j%5==3){
	      res[i+offset][j+offset] = '.';
	    }
	    else {
	      res[i+offset][j+offset] = 'd';
	    }
	  }
	  else if(i%5==1){
	    if(j%5==0){
	      res[i+offset][j+offset] = 'a';
	    }
	    else if(j%5==2||j%5==3){
	      res[i+offset][j+offset] = 'c';
	    }
	    else if(j%5==1){
	      res[i+offset][j+offset] = '.';
	    }
	    else {
	      res[i+offset][j+offset] = 'd';
	    }
	  }
	  else if(i%5==2){
	    if(j%5==0||j%5==1){
	      res[i+offset][j+offset] = 'e';
	    }
	    else if(j%5==2){
	      res[i+offset][j+offset] = 'f';
	    }
	    else {
	      res[i+offset][j+offset] = 'g';
	    }
	  }		
	  else if(i%5==3){
	    if(j%5==2){
	      res[i+offset][j+offset] = 'f';
	    }
	    else if(j%5==3){
	      res[i+offset][j+offset] = 'i';
	    }
	    else if(j%5==4){
	      res[i+offset][j+offset] = 'j';
	    }
	    else {
	      res[i+offset][j+offset] = '.';
	    }
	  }
	  else if(i%5==4){
	    if(j%5==2){
	      res[i+offset][j+offset] = '.';
	    }
	    else if(j%5==3){
	      res[i+offset][j+offset] = 'i';
	    }
	    else if(j%5==4){
	      res[i+offset][j+offset] = 'j';
	    }
	    else {
	      res[i+offset][j+offset] = 'h';
	    }
	  }	
	}
      }
      offset += 5;
      n -= 5;
    }
  }
  rep(i,nn){
    rep(j,nn){
      cout << res[i][j];
    }
    cout  << "\n";
  }

  return 0;
}
