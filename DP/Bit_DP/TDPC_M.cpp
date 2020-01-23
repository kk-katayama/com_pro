#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll MOD=1e+9+7;
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
template<typename X>
struct Matrix
{
  vector<vector<X>> mat;
  int row;
  int col;
  
  Matrix(int _row,int _col){
    row = _row;
    col = _col;
    mat.resize(row);
    rep(i,row) mat[i].resize(col);
  }

  Matrix(vector<vector<X>> _mat){
    mat = _mat;
    row = mat.size();
    col = mat[0].size();
  }
  
  Matrix operator + (const Matrix a) const{
    Matrix temp(*this);
    rep(i,row) rep(j,col){
      temp.mat[i][j] += a.mat[i][j];
    }
    return temp;
  }

  Matrix operator - (const Matrix a) const{
    Matrix temp(*this);
    rep(i,row) rep(j,col){
      temp.mat[i][j] -= a.mat[i][j];
    }
    return temp;
  }

  Matrix operator * (const Matrix a) const{
    Matrix temp(*this);
    Matrix res(temp.row,a.col);
    rep(i,temp.row){
      rep(j,a.col){
	rep(k,temp.col){
	  res.mat[i][j] += temp.mat[i][k] * a.mat[k][j];
	}
      }
    }
    return res;
  }

  Matrix pow(int n){
    Matrix A = mat;
    Matrix B(col,col);
    rep(i,col)  B.mat[i][i].x = 1;
    while(n > 0){
      if(n & 1) B = B * A;
      A = A * A;
      n >>= 1;
    }
    return B;
  }
  
  void print(){
    rep(i,row){
      rep(j,col){
	cout << mat[i][j].x << " ";
      }
      cout  << "\n";
    }
  }
  
  
  
};
template<typename X>
struct Graph{
  int node;
  vector<vector<int>> edge;

  Graph(int _node){
    node = _node;
    edge.resize(node);
    
  }
  void add(int from,int to){
    edge[from].push_back(to);
  }
  vector<vector<X>> TSP(){
    vector<vector<X>> res(node);
    rep(i,node) res[i].resize(node);
    vector<X> sum(1<<node,0);
    vector<vector<X>> dp(1<<node);
    rep(i,(1<<node)) dp[i].resize(node);

    rep(s,node){
      rep(i,(1<<node)) rep(j,node) dp[i][j].x = 0;
      rep(i,(1<<node)) sum[i].x = 0;
      dp[1<<s][s].x = 1;
      sum[1<<s].x = 1;
      for(int S=(1<<s)+1;S<(1<<node);++S){
	rep(v,node){
	  for(auto &w:edge[v]){
	    if(((S>>v)&1)){
	      dp[S][v] += dp[S-(1<<v)][w];
	      //	      sum[S] += dp[S][v];
	    }
	  }
	}
      }
      rep(i,node){
	rep(S,(1<<node)){
	  res[s][i] += dp[S][i];
	}
      }
    }
    
    return res;
  }

  
};
int main()
{
  int h,r;
  cin >> h >> r;
  vector<vector<int>> edge(r);
  rep(i,r) edge[i].resize(r);
  rep(i,r) rep(j,r) cin >> edge[i][j];
  Graph<mint> gp(r);
  rep(i,r) rep(j,r){
    if(edge[i][j]){
      gp.add(i,j);
    }
  }
  Matrix<mint> mat(gp.TSP());

  mat = mat.pow(h);
  
  Matrix<mint> res(1,r);
  res.mat[0][0].x = 1;

  res = res * mat;

  cout << res.mat[0][0].x << "\n";
  
  return 0;
}
