#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
const double EPS = 1e-8;
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
  int n;
  cin >> n;
  vector<string> a(n);
  rep(i,n) cin >> a[i];
  vector<string> b(n);
  rep(i,n) cin >> b[i];

  vector<vector<double>> A(n,vector<double>(n));
  vector<vector<double>> B(n,vector<double>(n));  

  rep(i,n) rep(j,n) A[i][j] = (double)a[i][j] -  '0';
  rep(i,n) rep(j,n) B[i][j] = (double)b[i][j] -  '0';  

  vector<vector<double>> res = Gauss_Jordan(A,B);

  rep(i,n) rep(j,n){
    if(res[i][j]<0){
      cout << -1 << "\n";
      return 0;
    }
  }
  
  rep(i,n){
    rep(j,n){
      cout << (int)res[i][j];
    }
    cout  << "\n";
  }
  
  return 0;
}
