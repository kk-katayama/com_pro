#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
class Tree{
private:
  int n;//number of node
  int m;
  vector<vector<int>> edge;// edge does not have cost.
  vector<vector<pair<int,int>>> edge2;// edge has cost.
  vector<bool> col;
  vector<bool> f;
public:  
  //*****Constructor************
  Tree(int n_){
    n = n_;
    edge.resize(n);
  }

  Tree(int n_,int m_,vector<int> a,vector<int> b){
    n = n_;
    m = m_;
    edge.resize(n);
    rep(i,m){
      edge[a[i]].push_back(b[i]);
      edge[b[i]].push_back(a[i]);
    }
  }

  Tree(int n_,int m_,vector<int> a,vector<int> b,vector<int> c){
    n = n_;
    m = m_;
    edge2.resize(n);
    rep(i,m){
      edge2[a[i]].push_back(make_pair(b[i],c[i]));
      edge2[b[i]].push_back(make_pair(a[i],c[i]));
    }
  }  
  //*******************************************
  bool bipa_check(int v,bool color)
  {
    f[v] = true;
    col[v] = color;
    for(auto& w:edge[v]){
      if(f[w]){
	if(col[w] == color) return false;
      }
      else if(!bipa_check(w,!color)) return false;
    }
    return true;
  }

  void solve(){
    col.assign(n,0);
    f.assign(n,0);
    bipa_check(0,0);
    int x = 0,y = 0;
    vector<int> xvec,yvec;
    rep(i,n){
      if(col[i]){
	x++;
	xvec.push_back(i);
      }
      else{
	y++;
	yvec.push_back(i);	
      }
    }
    int n0 = n/3,n1 = (n+2)/3,n2 = (n+1)/3;
    vector<int> res(n,0);
    if(n1+n2<=x){
      rep(i,n1){
	res[xvec[i]] = i*3+1;
      }
      rep(i,n2){
	res[xvec[i+n1]] = i*3+2;
      }      
    }
    else if(n1+n2<=y){
      rep(i,n1){
	res[yvec[i]] = i*3+1;
      }
      rep(i,n2){
	res[yvec[i+n1]] = i*3+2;
      }            
    }
    else if(n1<=x){
      rep(i,n1){
	res[xvec[i]] = i*3+1;
      }
      rep(i,n2){
	res[yvec[i]] = i*3+2;
      }      
    }
    else if(n2<=x){
      rep(i,n2){
	res[xvec[i]] = i*3+2;
      }
      rep(i,n1){
	res[yvec[i]] = i*3+1;
      }      
    }
    int z = 3;
    rep(i,n){
      if(res[i]==0){
	res[i] = z;
	z += 3;
      }
    }
    rep(i,n) cout << res[i] << " ";
    cout  << "\n";
  }
  
};



int main()
{
  int n;cin >> n;
  vector<int> a(n-1),b(n-1);
  rep(i,n-1){
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
  }
  Tree tr(n,n-1,a,b);
  tr.solve();
  return 0;
}
