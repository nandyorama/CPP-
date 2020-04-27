#include<bits/stdc++.h>
using namespace std;
class B{
  public:
  void fun(){cout<<"B::fun()"<<endl;}
};
class D:public B{
  public:
  void fun(){cout<<"D::fun()"<<endl;}
};
void getfunction(B *bptr)
{
    bptr->fun();//Calls base class function when it is expected to call Derived class function.
}
int main()
{
    D d;
    getfunction(&d);
    
    //B *bptr = &d;
    //bptr->fun();
    //D *dptr = &d;
    //dptr->fun();
    return 0;
}
