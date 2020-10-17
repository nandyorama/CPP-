
#include <bits/stdc++.h> 
using namespace std; 
class MathSample 
{ 
private: 
    int num; 
public: 
    MathSample(int n) : num(n) {  } 
    //Functor that overloads the operator()
    int operator () (int to_add) const { 
        return num + to_add; 
    } 
}; 
int main() 
{ 
    int arr[] = {1, 2, 3, 4, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int toadd = 5; 
  
    transform(arr, arr+n, arr, MathSample(toadd)); 
  
    for(auto i: arr)
    {
        cout<<i<<"--";
    }
    return 0;    
} 
