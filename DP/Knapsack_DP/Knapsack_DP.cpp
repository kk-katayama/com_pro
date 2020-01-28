template<typename X>
class KnapDP{ //standard KnapsackDP template
  int n; //number of goods
  int wmax; //maximum weight of goods
  vector<X> v; // v[i] := value of goods i is v[i]
  vector<int> w; //w[i] := weight of goods i is w[i]
  vector<vector<X>> dp; //dp table

  //**************Constructor************************
  KnapDP(int _n,int _wmax,vector<X> _v,vector<int> _w){
    n = _n;
    wmax = _wmax;
    v = _v;
    w = _w;
  }

  //*************Fill DP Table*************************
  void solve(){
    dp.assign(n+1,vector<X>(wmax+1,0));
    rep(i,n){
      rep(j,wmax+1){
	if(j-w[i]<0){
	  dp[i+1][j] = dp[i][j];
	}
	else{
	  dp[i+1][j] = max(dp[i][j],dp[i][j-w[i]]+v[i]);
	}
      }
    }
  }
  //************Get DP Value*************************
  X get_dp(int x,int y){
    return dp[x][y];
  }
};
