#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll MOD=1e+9+7;
ll l,r;
struct mint{
  ll x;
  mint(ll x=0):x(x%MOD){}
  mint& operator+=(const mint a){
    if((x+=a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator-=(const mint a){
    if((x += MOD-a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator*=(const mint a){
    (x*=a.x)%=MOD;
    return *this;
  }
  mint operator+(const mint a) const{
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const{
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const{
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const{
    if(!t) return 1;
    mint a = pow(t>>1);
    a*=a;
    if(t&1) a*=*this;
    return a;
  }
  
  //for prime mod
  mint inv() const{
    return pow(MOD-2);
  }
  mint& operator/=(const mint a){
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const{
    mint res(*this);
    return res/=a;
  }
};
mint dp[70][2][2][2][2][2];
vector<int> bitr,bitl;
int main()
{
  cin >> l >> r;

  dp[0][0][0][0][0][0].x = 1;

  while(r > 0){
    bitr.push_back(r%2);
    r /= 2;
  }
  int brs = bitr.size();
  
  while(l > 0){
    bitl.push_back(l%2);
    l /= 2;
  }
  int bls = bitl.size();  

  rep(i,brs-bls) bitl.push_back(0);
  
  reverse(bitr.begin(), bitr.end());
  reverse(bitl.begin(), bitl.end());  

  rep(i,brs){
    int li=bitl.at(i),ri=bitr.at(i);

    if(li == 0 && ri == 1){
      rep(j,2){
	rep(k,2){
	  if(j<k) continue;
	  rep(l,2){
	    rep(m,2){
	      rep(n,2){
		dp[i+1][1][1][l][1][1] += dp[i][j][k][l][m][n];
		dp[i+1][0][0][1][m][n] += dp[i][j][k][l][m][n];
		if(n == 1) dp[i+1][1][0][l][m][1] += dp[i][j][k][l][m][n];
	      }
	    }
	  }
	}
      }
    }
    else if(li == 0 && ri == 0){
      rep(j,2){
	rep(k,2){
	  if(j<k) continue;
	  rep(n,2){
	    dp[i+1][1][1][1][1][1] += dp[i][j][k][1][1][n];
	    dp[i+1][0][0][1][1][n] += dp[i][j][k][1][1][n];

	    dp[i+1][1][1][1][1][1] += dp[i][j][k][1][0][n];
	    dp[i+1][0][0][1][0][n] += dp[i][j][k][1][0][n];
	    
	    dp[i+1][0][0][0][1][n] += dp[i][j][k][0][1][n];
	    
	    dp[i+1][0][0][0][0][n] += dp[i][j][k][0][0][n];
	    if(n == 1){
	      dp[i+1][1][0][1][1][1] += dp[i][j][k][1][1][n];
	      dp[i+1][1][0][1][0][1] += dp[i][j][k][1][0][n];
	    }
	  }
	}
      }
    }
    else if(li == 1 && ri == 1){
      rep(j,2){
	rep(k,2){
	  if(j<k) continue;
	  rep(n,2){
	    dp[i+1][1][1][1][1][1] += dp[i][j][k][1][1][n];
	    dp[i+1][0][0][1][1][n] += dp[i][j][k][1][1][n];
	    
	    dp[i+1][1][1][0][1][1] += dp[i][j][k][0][1][n];
	    dp[i+1][0][0][1][1][n] += dp[i][j][k][0][1][n];
	    
	    dp[i+1][1][1][1][0][1] += dp[i][j][k][1][0][n];
	    
	    dp[i+1][1][1][0][0][1] += dp[i][j][k][0][0][n];
	    if(n == 1){
	      dp[i+1][1][0][1][1][1] += dp[i][j][k][1][1][1];
	      dp[i+1][1][0][0][1][1] += dp[i][j][k][0][1][1];
	    }
	  }
	}
      }
    }
    else{
      rep(j,2){
	rep(k,2){
	  if(j<k) continue;
	  rep(n,2){
	    dp[i+1][1][1][1][1][1] += dp[i][j][k][1][1][n];
	    dp[i+1][0][0][1][1][n] += dp[i][j][k][1][1][n];
	    
	    dp[i+1][1][1][1][0][1] += dp[i][j][k][1][0][n];
	    
	    dp[i+1][0][0][0][1][n] += dp[i][j][k][0][1][n];
	    if(n == 1){
	      dp[i+1][1][0][1][1][1] += dp[i][j][k][1][1][1];
	    }
	  }
	}
      }
    }
  } 

  mint res;
  
  rep(j,2){
    rep(k,2){
      if(j<k) continue;
      rep(l,2){
	rep(m,2){
	  rep(n,2){
	    res += dp[brs][j][k][l][m][n];
	  }
	}
      }
    }
  }

  cout << res.x << "\n";
  
  return 0;
}
