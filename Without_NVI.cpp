#include<bits/stdc++.h>
using namespace std;
class Base{
public:
virtual void displayString()=0;
};
class D1:public Base{
virtual void displayString(){cout<<"Input string is D1"<<endl;}
};
class D2:public Base{
virtual void displayString(){cout<<"Input string is D2"<<endl;}
};
int main()
{
Base *bptr = new D1();
bptr->displayString();
bptr = new D2();
bptr->displayString();
return 0;
}
