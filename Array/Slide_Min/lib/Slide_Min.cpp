#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n; cin >> n;
  int k; cin >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  deque<int> deq;
  
  auto dig = [&](int i)-> void {
	       if( !deq.empty() ) {
		 int back = deq.back();
		 while(a[back] >= a[i]) {
		   deq.pop_back();
		   if( deq.empty() ) break;
		   back = deq.back();
		 }
	       }
	       deq.push_back(i);    
	     };
  

  rep(i,k) dig(i);


  
  for (int i = k; i <= n; ++i) {
    int fro = deq.front();
    cout << a[fro] << "\n";
    if(fro == i-k) deq.pop_front();
    if(i == n) break;
    dig(i);
  }

  

  
  return 0;
}
