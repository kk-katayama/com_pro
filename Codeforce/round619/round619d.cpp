#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m,k;
  cin >> n >> m >> k;
  if(4*m*n-2*n-2*m<k){
    cout << "NO" << "\n";
    return 0;
  }
  
  vector<int> x;
  vector<char> y;
  while(k>0){
    rep(i,n-1){
      if(m!=1){
	if(k<=m-1){
	  x.push_back(k);
	  y.push_back('R');
	  k=0;
	  break;
	}
	else{
	  x.push_back(m-1);
	  y.push_back('R');
	  k-=m-1;
	}
	if(k<=m-1){
	  x.push_back(k);
	  y.push_back('L');
	  k=0;
	  break;
	}
	else{
	  x.push_back(m-1);
	  y.push_back('L');
	  k-=m-1;
	}      
      }
      x.push_back(1);
      y.push_back('D');
      k--;
      if(k==0) break;      
    }
    if(k==0) break;
    rep(i,m-1){
      if(k==1){
	x.push_back(1);
	y.push_back('R');
	k=0;
	break;
      }
      else{
	x.push_back(1);
	y.push_back('R');
	k--;
      }
      if(n==1) continue;
      if(k<=n-1){
	x.push_back(k);
	y.push_back('U');
	k=0;
	break;
      }
      else{
	x.push_back(n-1);
	y.push_back('U');
	k-=n-1;
      }
      if(k<=n-1){
	x.push_back(k);
	y.push_back('D');
	k=0;
	break;
      }
      else{
	x.push_back(n-1);
	y.push_back('D');
	k-=n-1;
      }            
    }
    if(k==0) break;
    if(m!=1){
      if(k<=m-1){
	x.push_back(k);
	y.push_back('L');
	k=0;
	break;      
      }
      else{
	x.push_back(m-1);
	y.push_back('L');
	k-=m-1;
      }
    }
    if(k==0) break;    
    if(k<=n-1){
      x.push_back(k);
      y.push_back('U');
      k=0;
      break;      
    }
    else{
      x.push_back(n-1);
      y.push_back('U');
      k-=n-1;
    }
    if(k==0) break;    
  }

  cout << "YES" << "\n";
  cout << (int)x.size() << "\n";
  rep(i,x.size()){
    cout << x[i] << " " << y[i] << "\n";
  }
  
  return 0;
}
