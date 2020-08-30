#include<bits/stdc++.h>
using namespace std;
class Sample{
  public:
  //Default Constructor
  Sample(){}
  
  //Copy Constructor with non-const Reference
  Sample(Sample &s){}
  
  //Solution-2 Temporary Object Created(by fun() function) bound to Const Reference of Copy Constructor. 
  //Sample(const Sample &s){}
};

Sample fun()
{
  Sample s;//Calls Default Constructor
  return s;
}

int main()
{
    Sample S = fun();//Compiler Error::Copy Constructor Agrument is non-const
    
    //Solution-1 Calls Default Assignment Operator
    //Sample S;
    //S = fun();
    
    return 0;
}
