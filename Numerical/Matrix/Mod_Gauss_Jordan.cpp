#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
// 逆元計算
ll modinv(ll a, ll mod) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a/b;
        a -= t*b; swap(a, b);
        u -= t*v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}
template<int MOD>
struct Matrix
{
  vector<vector<ll>> mat;
  int row;
  int col;
  
  Matrix(int _row,int _col){
    row = _row;
    col = _col;
    mat.resize(row,vector<ll>(col,0));
  }

  Matrix(vector<vector<ll>> _mat){
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

  vector<ll>& operator [] (int i){
    return mat[i];
  }

  int size() const{
    return mat.size();
  }
  
  Matrix pow(int n){
    Matrix A = mat;
    Matrix B(col,col);
    rep(i,col)  B.mat[i][i] = 1;
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
	cout << mat[i][j] << " ";
      }
      cout  << "\n";
    }
  }
  
  
};
template<int MOD> int GaussJordan(Matrix<int MOD> &A,bool flag=false){
  int m = A.size(),n = A[0].size(); // m row and n col
  rep(row,m){
    rep(col,n){
      A[row][col] = (A[row][col]%MOD+MOD)%MOD;
    }
  }
  int rank = 0;
  

  rep(col,n){
    // 拡大係数行列は最後の列を掃き出さない
    if(flag&&col==n-1) break; 

    // find pivot
    int pivot = -1;
    X ma = 0;
    for(int row=rank;row<m;++row){
      if(A[row][col]!=0){
	pivot = row;
	break;
      }
    }

    // if there is no pivot, go next col.
    if(pivot==-1) continue;

    // swap row
    swap(A[pivot],A[rank]);

    // cahnge pivot's value to 1
    auto inv = modinv(A[rank][col],MOD);
    rep(col2,n) A[rank][col2] = A[rank][col2]*inv%MOD;

    // sweep out col that has pivot
    rep(row,m){
      if(row!=rank&&A[row][col]!=0){
	auto fac = A[row][col];
	rep(col2,n){
	  A[row][col2] -= A[rank][col2]*fac%MOD;
	  if(A[row][col2]<0) A[row][col2] += MOD;
	}
      }
    }
    rank++;
    A.print();
  }
  return rank;
}

template<int MOD> int linear_eq(Matrix<MOD> A,vector<ll> b,vector<ll> &res){
  // extend
  int m = A.size(),n = A[0].size();
  Matrix<MOD> B(m,n+1);
  rep(row,m){
    rep(col,n+1) B[row][col] = A[row][col];
    B[row][n] = b[row];
  }
  int rank = GaussJordan(B,true);
  
  for(int row=rank;row<m;++row) if(B[row][n]!=0) return -1;
  
  res.assign(n,0);
  rep(col,rank) res[col] = B[col][n];
  return res;
}

int main()
{
  int n,m;
  cin >> n >> m;
  vector<vector<double>> mat(n,vector<double>(m));
  rep(i,n){
    rep(j,m){
      cin >> mat[i][j];
    }
  }

  vector<double> b(n);
  rep(i,n){
    cin >> b[i];
  }
  Matrix<double> A(mat);

  linear_eq(A,b);
  
  return 0;
}
