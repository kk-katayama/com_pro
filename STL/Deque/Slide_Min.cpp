#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
vector<int> Slide_Min(vector<int> a,int n,int k){
  deque<int> deq;
  vector<int> b(0);
  rep(i,k){
    while((!deq.empty()) && a[*(deq.end()-1)] >= a[i]) deq.pop_back();
    deq.push_back(i);
  }

  b.push_back(*deq.begin());
  if(*deq.begin()==0) deq.pop_front();

  rep(i,n-k){
    while((!deq.empty()) && a[*(deq.end()-1)] >= a[i+k]) deq.pop_back();
    deq.push_back(i+k);
    //    while(*deq.begin() < i+1) deq.pop_front();
    b.push_back(*deq.begin());
    if(*deq.begin() == i+1) deq.pop_front();
  }
  return b;
}
vector<int> Slide_Max(vector<int> a,int n,int k){
  deque<int> deq;
  vector<int> b(0);
  rep(i,k){
    while((!deq.empty()) && a[*(deq.end()-1)] <= a[i]) deq.pop_back();
    deq.push_back(i);
  }

  b.push_back(*deq.begin());
  if(*deq.begin()==0) deq.pop_front();

  rep(i,n-k){
    while((!deq.empty()) && a[*(deq.end()-1)] <= a[i+k]) deq.pop_back();
    deq.push_back(i+k);
    //    while(*deq.begin() < i+1) deq.pop_front();
    b.push_back(*deq.begin());
    if(*deq.begin() == i+1) deq.pop_front();
  }
  return b;
}



int main()
{
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<int> b = Slide_Min(a,n,k);
  
  rep(i,b.size()){
    cout << b[i] << "\n";
  }
  return 0;
}
