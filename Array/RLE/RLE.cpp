#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template <typename X>
struct RLE{
  vector<X> array;
  int n;

  RLE(vector<X> _array){
    array = _array;
    n = array.size();
  }

  vector<int> compress(){
    vector<int> res(0);
    int cnt = 1;
    res.push_back(array[0]);
    rep(i,n-1){
      if(array[i]==array[i+1]){
	cnt++;
      }
      else{
	res.push_back(cnt);
	cnt = 1;
	res.push_back(array[i+1]);
      }
    }
    res.push_back(cnt);
    return res;
  }
  
};
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  RLE<int> rle(a);
  vector<int> res = rle.compress();
  
  
  rep(i,res.size()){
    cout << res[i] << " ";
  }
  cout  << "\n";
  
  return 0;
}
