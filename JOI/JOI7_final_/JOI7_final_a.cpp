#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> b = a;
  reverse(a.begin(), a.end());
  if(n % 2 == 0){
    int f = 0;
    int cnt = 0;
    for(int i = 0;i < n;i += 2){
      if(a[i] == 1 && a[i+1] == 0){
	if(f == -1) cnt += 2;
	else f = 1;
      }
      else if(a[i] == 1 && a[i+1] == 1){
	if(f == -1) cnt += 2;
	else f = 0;
      }
      else if(a[i] == 0 && a[i+1] == 0){
	if(f == 1) continue;
	else{
	  cnt += 2;
	  f = 0;
	}
      }
      else if(a[i] == 0 && a[i+1] == 1){
	if(f == 1) continue;
	else {
	  f = -1;
	  cnt += 2;
	}
      }
    }
    cout << cnt << "\n";
  }
  else {
    int f = 0;
    int cnt = 0;
    if(a[0] == 0) cnt++;
    for(int i = 1;i < n;i += 2){
      if(a[i] == 1 && a[i+1] == 0){
	if(f == -1) cnt += 2;
	else f = 1;
      }
      else if(a[i] == 1 && a[i+1] == 1){
	if(f == -1) cnt += 2;
	else f = 0;
      }
      else if(a[i] == 0 && a[i+1] == 0){
	if(f == 1) continue;
	else {
	  cnt += 2;
	  f = 0;
	}
      }
      else if(a[i] == 0 && a[i+1] == 1){
	if(f == 1) continue;
	else {
	  f = -1;
	  cnt += 2;
	}
      }
    }
    cout << cnt << "\n";
  }

  // rep(i,n){
  //   if(i % 2 == 1){
  //     if(b[i] == 1){
  // 	int j = i - 1;
  // 	while(b[j] == 0){
  // 	  b[j] = 1;
  // 	  j--;
  // 	  if(j == -1) break;
  // 	}
  //     }
  //     else {
  // 	int j = i - 1;
  // 	while(b[j] == 1){
  // 	  b[j] = 0;
  // 	  j--;
  // 	  if(j == -1) break;
  // 	}
  //     }      
  //   }
  // }
  // int cnt2 = 0;
  // rep(i,n) if(b[i] == 0) cnt2++;
  // cout << cnt2 << "\n";
  return 0;
}
