#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
vector<vector<ll> > comb;
void pascal(int n)
{
  comb.resize(n+1);
  rep(i,n+1) comb[i].assign(n+1,1);

  for(int i=2;i<=n;++i){
    for(int j=1;j<i;++j){
      comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
    }
  }
}
template <typename X>
struct RLE{
  vector<X> array;
  int n;
  vector<X> key;
  vector<int> value;
  
  RLE(vector<X> _array){
    array = _array;
    n = array.size();
  }

  vector<int> compress(){
    vector<int> res(0);
    int cnt = 1;
    key.push_back(array[0]);    
    rep(i,n-1){
      if(array[i]==array[i+1]){
	cnt++;
      }
      else{
	res.push_back(cnt);
	cnt = 1;
	key.push_back(array[i+1]);
      }
    }
    res.push_back(cnt);
    value = res;
    return res;
  }
  
};
bool comp(double &a,double &b) {return a>b;}
int main()
{
  int n,a,b;
  cin >> n >> a >> b;
  vector<double> v(n);
  rep(i,n) cin >> v[i];
  sort(v.begin(), v.end(),comp);
  double res = 0;
  rep(i,a) res += v[i];
  double aa = a;
  res /= aa;
  printf("%.7f\n", res);
  
  RLE<double> rle(v);
  vector<int> val = rle.compress();
  
  int cnt = val[0];
  int index = 0;
  while(cnt<a){
    index++;
    cnt += val[index];
  }
  if(index == 0){
    int m = val[index];
    pascal(m);
    ll ans = 0;
    for(int i=a;i<=min(b,m);++i) ans += comb[m][i];
    cout << ans << "\n";
  }
  else{
    cnt -= val[index];
    pascal(val[index]);
    cout << comb[val[index]][a-cnt] << "\n";
  }

  
  return 0;
}
