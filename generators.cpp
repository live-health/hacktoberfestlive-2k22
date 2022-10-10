#include <algorithm>  
#include <iostream>  
#include <vector>  
  
using namespace std;  
  
int main() {  
  vector<int> v(10);  
  
  int n = 1;  
  generate(v.begin(), v.end(), [&n]() {   
      auto t = n;   
      n *= 2;   
      return t;   
      } );  
  
  for_each(v.begin(), v.end(), [](int x) {   
      cout << x << ",";   
      });  
    
  return 0;  
}  
