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

  Matrix pow(ll n){
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

int main()
{
  ll n;
  cin >> n;
  vector<vector<mint>> vec(2);
  rep(i,2) vec[i].resize(2);
  vec[0][0].x = 1;
  vec[0][1].x = 1;
  vec[1][0].x = 1;
  vec[1][1].x = 0;  

  rep1(i,n){
    Matrix<mint> A(vec);
    A =  A.pow(i);
    cout << A.mat[1][0].x << "\n";
  }
  return 0;
}
