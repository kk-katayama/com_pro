#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll inf = -(1LL<<60);
class max_plus{
private:
  ll x;
  ll y;
public:
  max_plus(ll _x=inf,ll _y=0):x(_x),y(_y){
  }

  void add(ll _x){
    x = _x;
  }
  
  max_plus operator+(const max_plus& other) const{
    return {max(x,other.x),max(y,other.y)};
  }

  max_plus operator*(const max_plus& other) const{
    if(x==inf||other.x==inf) return {inf,0};
    else return {x+other.x,max(y+other.x,other.y)};
  }

  ll solve(ll z){
    return max(z+x,y);
  }
  
  ll get(){
    return x;
  }

  void show(){
    cout << "{" <<  x << ":" << y << "}";
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
    rep(i,row) mat[i].assign(col,inf);
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
	  res.mat[i][j] = res.mat[i][j]+(temp.mat[i][k]*a.mat[k][j]);
	}
      }
    }
    return res;
  }

  Matrix pow(int n){
    Matrix A = mat;
    Matrix B(col,col);
    rep(i,col){
      B.mat[i][i].add(0);
    }
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
	if(mat[i][j].get()==inf) cout << "inf" << " ";
	else mat[i][j].show();
      }
      cout  << "\n";
    }
  }
  
  
  
};


int main()
{
  int n,m;
  cin >> n >> m;
  ll W;
  cin >> W;
  int s,k;
  cin >> s >> k;
  s--;
  vector<int> u(m),v(m);
  vector<ll> w(m);
  rep(i,m){
    cin >> u[i] >> v[i] >> w[i];
    u[i]--;
    v[i]--;
  }

  vector<vector<max_plus>> _mat(n,vector<max_plus>(n));
  rep(i,m){
    _mat[u[i]][v[i]].add(w[i]);
  }
  Matrix<max_plus> mat(_mat);

  // rep1(i,k){
  //   cout << i << "\n";
  //   mat.pow(i).print();
  // }

  Matrix<max_plus> c = mat.pow(k);
  ll res = 0;
  bool f = false;
  rep(i,n){
    if(c.mat[s][i].get()!=inf) f = true;
    res = max(res,c.mat[s][i].solve(W));
  }
  if(f) cout << res << "\n";
  else cout << -1 << "\n";
  return 0;
}
