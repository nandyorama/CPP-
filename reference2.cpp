#include<bits/stdc++.h>
using namespace std;

//Function returns as value, treated as rvalue
int getValue()
{
 int i =10;
 return i;
}
int main()
{
 int x = getValue();
 //int &r = getValue();//lvalue should be assigned to referece, not rvalue(getValue is rvalue)
 const int & cr = getValue();

 int &&rr = getValue();
 const int &&crr = getValue();
 return 0;
}
