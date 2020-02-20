#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
void refl(vector<int> &a){
  vector<int> tmp((int)a.size());
  rep(i,a.size()/2){
    tmp[2*i] = a[i];
  }
  rep(i,a.size()/2){
    tmp[2*i+1] = a[i+(int)a.size()/2];
  }
  a = tmp;
}

void kcut(vector<int> &a,int k){
  vector<int> tmp;
  for(int i=k;i<a.size();++i){
    tmp.push_back(a[i]);
  }
  rep(i,k){
    tmp.push_back(a[i]);
  }
  a = tmp;
}
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> k(m);
  rep(i,m){
    cin >> k[i];
  }

  vector<int> a;
  rep1(i,2*n){
    a.push_back(i);
  }

  rep(i,m){
    if(k[i]==0){
      refl(a);
    }
    else{
      kcut(a,k[i]);
    }
  }

  rep(i,2*n){
    cout << a[i] << "\n";
  }
  
  return 0;
}
