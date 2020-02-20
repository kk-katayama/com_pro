#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<typename X>
struct Matrix
{
  vector<vector<X>> mat;
  int row;
  int col;
  
  Matrix(int _row,int _col){
    row = _row;
    col = _col;
    mat.resize(row,vector<X>(col,0));
    //    rep(i,row) mat[i].assign(col,0);
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

vector<vector<int>> Gauss_Jordan(vector<vector<int>> & A,vector<int>& b){
  int n = A.size();
  int m = A[0].size();
  vector<vector<int>> B(n,vector<int>(m+1));

  rep(i,n) rep(j,m) B[i][j] = A[i][j];
  rep(i,n) B[i][m] = b[i];

  rep(j,n){
    int pivot = j;
    for(int k=j;k<n;++k){
      if(abs(B[k][j]) > abs(B[pivot][j])) pivot = k;
    }
    if(pivot!=j){
      rep(l,m){
	B[j][l] = (B[j][l]+B[pivot][l])%2;
      }
    }
    for(int k=j+1;k<n;++k){
      if(B[k][j]==0) continue;
      rep(l,m){
	B[k][l] = (B[k][l]+B[j][l])%2;
      }
    }
    // Matrix<int> cc(B);
    // cc.print();
    // cout << "******************" << "\n";
  }

  return B;
}

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }

  ll res = 0;
  vector<vector<int>> A(60);
  rep(i,n){
    int cnt = __builtin_popcountll(A[i]);

    
  }

  vector<int> b(n,1);
  vector<vector<int>> B = Gauss_Jordan(a,b);

  
  
  return 0;
}

