#include<bits/stdc++.h>
using namespace std;
class Incorrect{
public:
  Incorrect(int a,int b):C(A*B),A(a),B(b){}
  int A;
  int C;//C initialization depends on A and B and therefore should be declared after B
  int B;
};
class Correct{
  public:
  Correct(int a,int b):C(A*B),A(a),B(b){}
  int A;
  int B;
  int C;
};

int main()
{
Incorrect ic(2,3);
cout<<ic.A<<ic.B<<endl<<ic.C<<endl;

Correct cc(2,3);
cout<<cc.A<<cc.B<<endl<<cc.C<<endl;

return 0;
}
