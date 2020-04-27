#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  {
    set<int> st;
    st.insert(10);
    st.insert(19);
    st.insert(7);
    auto it = st.upper_bound(8); // *it = 10
    st.insert(*it-1); // st = {7, 9, 10, 19}
    cout << *it << "\n"; // *it = 10 
    st.erase(it); 
    for(auto s: st) {
      cout << s << "\n"; // st = {7, 9, 19}
    }
  }
  cout << "***************" << "\n";
  {
    set<int> st;
    st.insert(10);
    st.insert(19);
    st.insert(7);    
    auto it = st.upper_bound(8);
    st.insert(*it+1); // st = {7, 10, 11, 19} 
    cout << *it << "\n"; // *it = 10
    st.erase(it);
    for(auto s: st) {
      cout << s << "\n"; // st = {7, 10, 19}
    }
  }
  cout << "***************" << "\n";
  {
    set<int> st;
    st.insert(10);
    st.insert(19);
    st.insert(7);    
    auto it = st.upper_bound(8);
    st.insert(*it+1); // st = {7, 10, 11, 19} 
    cout << *it << "\n"; // *it = 10
    it++;  // *it = 11
    cout << *it << "\n";
  }
  cout << "***************" << "\n";
  {
    set<int> st;
    st.insert(10);
    st.insert(19);
    st.insert(7);    
    auto it = st.upper_bound(8);
    st.insert(*it-1); // st = {7, 9, 10, 19} 
    cout << *it << "\n"; // *it = 10
    it--;  // *it = 9
    cout << *it << "\n";
  }      
  cout << "***************" << "\n";
  {
    set<int> st;
    st.insert(10);
    st.insert(19);
    st.insert(7);    
    auto it = st.upper_bound(8);
    st.insert(*it-1); // st = {7, 9, 10, 19} 
    cout << *it << "\n"; // *it = 10
    st.erase(it);
    it--;
    cout << *it << "\n"; 
  }        

  
  return 0;
}
