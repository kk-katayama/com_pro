#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template <typename X>
struct RLE{
  string array;
  int n;

  RLE(string _array){
    array = _array;
    n = array.size();
  }

  string compress(){
    string res = "";
    int cnt = 1;
    res += array[0];
    rep(i,n-1){
      if(array[i]==array[i+1]){
	cnt++;
      }
      else{
	string ss = to_string(cnt);
	cnt = 1;
	res += ss;
	res += array[i+1];
      }
    }
    string ss = to_string(cnt);    
    res += ss;
    return res;
  }
  
};

int main()
{
  string s;
  cin >> s;
  RLE<int> rle(s);
  cout << rle.compress() << "\n";

  
  return 0;
}
