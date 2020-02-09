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
const double EPS = 1e-8;
vector<double> Gauss_Jordan(vector<vector<double>>& A,vector<double>& b){
  int n = A.size();
  vector<vector<double>> B(n,vector<double>(n+1));

  rep(i,n) rep(j,n) B[i][j] = A[i][j];
  rep(i,n) B[i][n] = b[i];

  rep(i,n){
    int pivot = i;
    for(int k=i;k<n;++k){
      if(abs(B[k][i]) > abs(B[pivot][i])) pivot = k;
    }
    swap(B[i],B[pivot]);

    if(abs(B[i][i]) < EPS) return vector<double>();

    for(int k=i+1;k<=n;++k) B[i][k] /= B[i][i];
    rep(j,n){
      if(i!=j){
	for(int k=i+1;k<=n;++k) B[j][k] -= B[j][i]*B[i][k];
      }
    }
  }

  vector<double> res(n);
  rep(i,n) res[i] = B[i][n];
  return res;
}
vector<vector<double>> Gauss_Jordan(vector<vector<double>>& A,vector<vector<double>>& b){
  int n = A.size();
  vector<vector<double>> B(n,vector<double>(2*n,0));

  rep(i,n) rep(j,n) B[i][j] = A[i][j];
  rep(i,n) rep(j,n) B[i][j+n] = b[i][j];
  
  rep(i,n){
    int pivot = i;
    for(int k=i;k<n;++k){
      if(abs(B[k][i]) > abs(B[pivot][i])) pivot = k;
    }
    swap(B[i],B[pivot]);


    if(abs(B[i][i]) < EPS) return vector<vector<double>>(n,vector<double>(n,-1));

    for(int k=i+1;k<2*n;++k) B[i][k] /= B[i][i];
    rep(j,n){
      if(i!=j){
	for(int k=i+1;k<2*n;++k) B[j][k] -= B[j][i]*B[i][k];
      }
    }
   
  }

  vector<vector<double>> res(n,vector<double>(n));
  rep(i,n) rep(j,n) res[i][j] = B[i][j+n];
  return res;
}




int main()
{
  // int n;
  // cin >> n;
  // vector<vector<double>> A(n,vector<double>(n));
  // rep(i,n) rep(j,n) cin >> A[i][j];
  // vector<double> b(n);
  // rep(i,n) cin >> b[i];
  int n;
  cin >> n;
  vector<vector<double>> A(n,vector<double>(n));
  rep(i,n) rep(j,n) cin >> A[i][j];
  vector<vector<double>> b(n,vector<double>(n));
  rep(i,n) rep(j,n) cin >> b[i][j];

  vector<vector<double>> res = Gauss_Jordan(A,b);
  Matrix<double> x(res);
  x.print();
  
  return 0;
}
