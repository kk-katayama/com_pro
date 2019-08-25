#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int VMAX=100010;
ll n,m;
int a[100010],b[100010];
ll cntx,cnty;
bool f[100010],col[100010];
vector<int> edge[VMAX];
void add_edge(int from,int to){
  edge[from].push_back(to);
  edge[to].push_back(from);  
}
bool bipa_check(int x,bool c){
  f[x] = true;
  if(c) cntx++;
  else cnty++;
  col[x] = c;
  int vs = edge[x].size();
  rep(i,vs){
    int w = edge[x][i];
    if(f[w]){
      if(col[w] == c) return false;	      
    }
    else if(!bipa_check(w,!c)) return false;
  }
  return true;
}
int main()
{
  cin >> n >> m;
  rep(i,m) cin >> a[i] >> b[i];

  rep(i,m) add_edge(--a[i],--b[i]);

  cntx = cnty = 0;
  rep(i,n) f[i] = false;
  
  if(bipa_check(0,1)) cout << cntx*cnty - m << "\n";
  else cout << n*(n-1)/2 - m << "\n";
  
  
  return 0;
}
