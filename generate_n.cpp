#include<bits/stdc++.h>
using namespace std;
// Defining the generator function 
int fun() 
{ 
    static int i = 0; 
    return ++i; 
} 
  
using namespace std; 
int main() 
{ 
    int i; 
  
    // Declaring a vector of size 10 
    vector<int> v1(10); 
  
    // using std::generate_n 
    std::generate_n(v1.begin(), 10, fun); 
  
    vector<int>::iterator i1; 
    for (i1 = v1.begin(); i1 != v1.end(); ++i1) { 
        cout << *i1 << " "; 
    } 
    return 0; 
} 
