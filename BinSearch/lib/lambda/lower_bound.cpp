#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n = 10;
  vector<int> a = { 1, 2, 5, 19, 199, 200, 409, 1000, 9000, 503920};

  int k;
  cin >> k;
  
  auto isok = [&](int idx)-> bool{ return a[idx] >= k; };

  auto bins = [&]()-> int{
		int lb = -1, ub = a.size();
		while(ub - lb > 1) {
		  int mid = (ub + lb) / 2;
		  if(isok(mid)) ub = mid;
		  else lb = mid;
		}		
		return ub;
	      };  


  cout << a[bins()] << "\n";
  
  
  return 0;
}
