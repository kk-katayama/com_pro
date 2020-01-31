#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
int main()
{
  int mask;
  cin >> mask;
  cout << bitset<8>(mask) << "\n";
  // enumerate subset of mask without 0
  cout << "without_0" << "\n";
  for(int i=mask;i>0;i=(i-1)&mask){ 
    cout << bitset<8>(i) << "\n";
  }
  // enumerate subset of mask with 0
  cout << "with_0" << "\n";  
  for(int i=mask;i>=0;--i){
    i &= mask;
    cout << bitset<8>(i) << "\n";
  }
  // enumerate set including mask
  cout << "include_mask" << "\n";
  for(int i=mask;i<(1<<8);i=(i+1)|mask){
    cout << bitset<8>(i) << "\n";
  }

  return 0;
}

